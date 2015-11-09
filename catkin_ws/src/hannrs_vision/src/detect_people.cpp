//ROS
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <dynamic_reconfigure/server.h>
#include <hannrs_vision/UndistortConfig.h>
//OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <math.h>
#include <iostream>
#include <fstream>

typedef struct{
  std::vector<double> pol;    // the polynomial coefficients: pol[0] + x"pol[1] + x^2*pol[2] + ... + x^(N-1)*pol[N-1]
  int length_pol;                // length of polynomial
  std::vector<double> invpol; // the coefficients of the inverse polynomial
  int length_invpol;             // length of inverse polynomial
  double xc;         // row coordinate of the center
  double yc;         // column coordinate of the center
  double c;          // affine parameter
  double d;          // affine parameter
  double e;          // affine parameter
  int width;         // image width
  int height;        // image height
}ocam_model;

class PersonDetector{
protected:
  ocam_model fisheye_model;
  
  ros::NodeHandle nh;
  image_transport::ImageTransport it;
  image_transport::Subscriber image_sub;
  cv_bridge::CvImagePtr cv_ptr;
  bool fst_im;
  cv::Mat undistorted_im;
  
  cv::Mat fgMaskMOG; //fg mask generated by MOG method
  cv::Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
  cv::Ptr<cv::BackgroundSubtractor> pMOG; //MOG Background subtractor
  cv::Ptr<cv::BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
  std::vector<cv::Rect> boundRectMOG, boundRectMOG2;
  std::vector<cv::RotatedRect> ellipseMOG, ellipseMOG2;
  std::vector<cv::RotatedRect> ellipse_filtetred;
  
  dynamic_reconfigure::Server<hannrs_vision::UndistortConfig> server;
  dynamic_reconfigure::Server<hannrs_vision::UndistortConfig>::CallbackType f;
  
  std::ofstream myfile;
  cv::Point2f im_center;
  
  unsigned int clicks;
  
  cv::Mat img_map;
  
  double sf;
  bool changed_sf;
  cv::Mat mapx, mapy;
  
  void imageCB(const sensor_msgs::ImageConstPtr& msg){
    try{
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }catch(cv_bridge::Exception& e){
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    
    if(fst_im){
      fst_im = false;
    }
    
//     ros::Time t = ros::Time::now();
    
    undistorted_im.setTo(cv::Scalar(0,0,0));
    
    if(changed_sf){
      create_undistort_map();
      changed_sf = false;
    }
    
    cv::remap( cv_ptr->image, undistorted_im, mapx, mapy, cv::INTER_LINEAR, cv::BORDER_TRANSPARENT, cvScalarAll(0));
    
    //update the background model
    pMOG->operator()(undistorted_im, fgMaskMOG);
    pMOG2->operator()(undistorted_im, fgMaskMOG2);

//     double elapsed = ros::Time::now().toSec() - t.toSec();
//     ROS_INFO("Elapsed: %f", elapsed);
  }

  void create_perspecive_undistortion_LUT( CvMat *mapx, CvMat *mapy){
    float Nxc = mapx->rows/2.0;
    float Nyc = mapx->cols/2.0;
    float Nz  = -mapx->cols/sf;
    double M[3];
    double m[2];
    double norm;
    double theta;
    double t, t_i;
    double rho, x, y;
    double invnorm;
    int j,k;
    
    for (int i = 0; i < mapx->rows; i++)
      for (j = 0; j < mapx->cols; j++){   
	M[0] = (i - Nxc);
	M[1] = (j - Nyc);
	M[2] = Nz;
	
	norm = sqrt(M[0]*M[0] + M[1]*M[1]);
	theta = atan(M[2]/norm);
	
	if (norm != 0){
	  invnorm = 1/norm;
	  t  = theta;
	  rho = fisheye_model.invpol[0];
	  t_i = 1;

	  for (k = 1; k < fisheye_model.length_invpol; k++){
	    t_i *= t;
	    rho += t_i*fisheye_model.invpol[k];
	  }
	  
	  x = M[0]*invnorm*rho;
	  y = M[1]*invnorm*rho;
	
	  m[0] = x*fisheye_model.c + y*fisheye_model.d + fisheye_model.xc;
	  m[1] = x*fisheye_model.e + y   + fisheye_model.yc;
	}else{
	  m[0] = fisheye_model.xc;
	  m[1] = fisheye_model.yc;
	}
	
	*( mapx->data.fl + i*mapx->cols+j ) = (float) m[1];
	*( mapy->data.fl + i*mapx->cols+j ) = (float) m[0];
      }
  }
  
public:
  PersonDetector():it(nh){
    cv::namedWindow("undistorted image", cv::WINDOW_NORMAL);
//     cv::namedWindow("MOG", cv::WINDOW_NORMAL);
//     cv::namedWindow("MOG2", cv::WINDOW_NORMAL);
    
    fst_im = true;
    changed_sf = false;
    
    std::string stream, calib_file;
    
    ros::NodeHandle pnh("~");
    pnh.getParam("image", stream);
    pnh.getParam("calib_file", calib_file);
    
    //subscribe video stream
    image_sub = it.subscribe(stream, 1, &PersonDetector::imageCB, this, image_transport::TransportHints("compressed"));
    
    f = boost::bind(&PersonDetector::callbackDR, this, _1, _2);
    server.setCallback(f);
    
    //load calib
    cv::FileStorage fileS(calib_file.c_str(), cv::FileStorage::READ);
    fileS["ss"] >> fisheye_model.pol;
    fileS["invpol"] >> fisheye_model.invpol;
    fileS["center_row"] >> fisheye_model.xc;
    fileS["center_column"] >> fisheye_model.yc;
    fileS["c"] >> fisheye_model.c;
    fileS["d"] >> fisheye_model.d;
    fileS["e"] >> fisheye_model.e;
    fileS["height"] >> fisheye_model.height;
    fileS["width"] >> fisheye_model.width;
    fisheye_model.length_pol = fisheye_model.pol.size();
    fisheye_model.length_invpol = fisheye_model.invpol.size();
    
    //compute map for distorsion removal
    create_undistort_map();
    
    //create Background Subtractor objects
    pMOG= new cv::BackgroundSubtractorMOG(); //MOG approach
    pMOG2 = new cv::BackgroundSubtractorMOG2(); //MOG2 approach
    
    myfile.open("/home/mateus/cam99_data.txt");
    
    im_center.x = fisheye_model.width/2;
    im_center.y = fisheye_model.height/2;
    
    clicks = 0;
  }
  
  ~PersonDetector(){
    cv::destroyAllWindows();
    myfile.close();
  }
  
  void create_undistort_map(){
    CvMat* mapx_persp = cvCreateMat(fisheye_model.height, fisheye_model.width, CV_32FC1);
    CvMat* mapy_persp = cvCreateMat(fisheye_model.height, fisheye_model.width, CV_32FC1);
    create_perspecive_undistortion_LUT( mapx_persp, mapy_persp);
    mapx = cv::Mat(mapx_persp);
    mapy = cv::Mat(mapy_persp);
  }
  
  void callbackDR(hannrs_vision::UndistortConfig &config, uint32_t level){
    sf = config.sf;
    changed_sf = true;
  }
  
  void find_contours(){
    if(!fst_im){
      std::vector<std::vector<cv::Point> > contoursMOG, contoursMOG2;
      std::vector<cv::Vec4i> hierarchyMOG, hierarchyMOG2;
      std::vector<std::vector<cv::Point> > contours_polyMOG, contours_polyMOG2;
      
      cv::Mat thresholdMOG, thresholdMOG2;
      
      cv::threshold(fgMaskMOG, fgMaskMOG, 254, 255, cv::THRESH_BINARY);
      cv::threshold(fgMaskMOG2, fgMaskMOG2, 254, 255, cv::THRESH_BINARY);
      
      //filter foreground masks
      cv::morphologyEx(fgMaskMOG, fgMaskMOG, cv::MORPH_OPEN, cv::Mat() , 
		     cv::Point(-1,-1), 3, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());    
      cv::morphologyEx(fgMaskMOG, fgMaskMOG, cv::MORPH_CLOSE, cv::Mat() , 
		       cv::Point(-1,-1), 3, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
    
      cv::morphologyEx(fgMaskMOG2, fgMaskMOG2, cv::MORPH_OPEN, cv::Mat() , 
		       cv::Point(-1,-1), 3, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
      cv::morphologyEx(fgMaskMOG2, fgMaskMOG2, cv::MORPH_CLOSE, cv::Mat() , 
		       cv::Point(-1,-1), 3, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
      
      // Find contours
      thresholdMOG = fgMaskMOG.clone();
      thresholdMOG2 = fgMaskMOG2.clone();
      cv::findContours(thresholdMOG, contoursMOG, hierarchyMOG, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
      cv::findContours(thresholdMOG2, contoursMOG2, hierarchyMOG2, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
      
      // Approximate contours to polygons + get bounding rects
      contours_polyMOG = std::vector<std::vector<cv::Point> >(contoursMOG.size());
      boundRectMOG = std::vector<cv::Rect>( contoursMOG.size() );
      ellipseMOG = std::vector<cv::RotatedRect>(contoursMOG.size());
      
      for( int i = 0; i < contoursMOG.size(); i++ ){ 
	cv::approxPolyDP( cv::Mat(contoursMOG[i]), contours_polyMOG[i], 3, true );
// 	boundRectMOG[i] = cv::boundingRect( cv::Mat(contoursMOG[i]) );
	if(contours_polyMOG[i].size() > 5){
	  ellipseMOG[i] = cv::fitEllipse(cv::Mat(contours_polyMOG[i]));
// 	  cv::ellipse(undistorted_im, ellipseMOG[i], cv::Scalar(0,0,255), 3, 8 );
	}
// 	cv::ellipse(undistorted_im, ellipseMOG[i], cv::Scalar(0,0,255), 1, 8, 0 );
// 	cv::rectangle(undistorted_im, boundRectMOG[i].tl(), boundRectMOG[i].br(), cv::Scalar(0,0,255), 1, 8, 0 );
// 	cv::drawContours(undistorted_im, contours_polyMOG, i, cv::Scalar(0,0,255), 2, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
      }

      contours_polyMOG2 = std::vector<std::vector<cv::Point> >(contoursMOG2.size());
      boundRectMOG2  = std::vector<cv::Rect>( contoursMOG2.size() );
      ellipseMOG2 = std::vector<cv::RotatedRect>(contoursMOG2.size());
      
      for( int i = 0; i < contoursMOG2.size(); i++ ){ 
	cv::approxPolyDP( cv::Mat(contoursMOG2[i]), contours_polyMOG2[i], 3, true );
// 	boundRectMOG2[i] = cv::boundingRect( cv::Mat(contoursMOG2[i]) );
	if(contours_polyMOG2[i].size() > 5){
	  ellipseMOG2[i] = cv::fitEllipse(cv::Mat(contours_polyMOG2[i]));
// 	  cv::ellipse(undistorted_im, ellipseMOG2[i], cv::Scalar(0,255,0), 3, 8 );
	}
// 	cv::rectangle(undistorted_im, boundRectMOG2[i].tl(), boundRectMOG2[i].br(), cv::Scalar(0,255,0), 1, 8, 0 );
// 	cv::drawContours(undistorted_im, contours_polyMOG2, i, cv::Scalar(0,255,0), 2, 8, std::vector<cv::Vec4i>(), 0, cv::Point() );
      }

    }
  }
  
  void merge_detections(){
    if(!fst_im){
      ellipse_filtetred.clear();
      
      cv::Rect rect;
      for(unsigned int i = 0; i < ellipseMOG2.size(); i++){
	for(unsigned int j = 0; j < ellipseMOG.size(); j++){
	  if(ellipseMOG2[i].boundingRect().area() > 5000 && ellipseMOG[j].boundingRect().area() > 2500){
	    rect = ellipseMOG2[i].boundingRect() | ellipseMOG[j].boundingRect();
	    if(rect.area() >= ellipseMOG2[i].boundingRect().area() && rect.area() <= (ellipseMOG2[i].boundingRect().area() + 0.5*ellipseMOG[j].boundingRect().area())){
	      ellipse_filtetred.push_back(ellipseMOG2[i]);
	    }
	  }
	}
      }
      
      for(unsigned int i = 0; i < ellipse_filtetred.size(); i++){
	cv::ellipse(undistorted_im, ellipse_filtetred[i], cv::Scalar(255,0,0), 5, 8 );
	// rotated rectangle
//        cv::Point2f rect_points[4]; 
//        ellipse_filtetred[i].points( rect_points );
//        for( int j = 0; j < 4; j++ )
// 	cv::line( undistorted_im, (rect_points[0] + rect_points[1])*0.5, (rect_points[2] + rect_points[3])*0.5, cv::Scalar(0,0,255), 5, 8 );
// 	cv::line( undistorted_im, (rect_points[0] + rect_points[3])*0.5, (rect_points[2] + rect_points[1])*0.5, cv::Scalar(0,255,0), 5, 8 );
      }
      
    }
  }
  
  void check_person(){
    if(!fst_im){
      cv::Point2f im_center;
      im_center.x = undistorted_im.cols/2;
      im_center.y = undistorted_im.rows/2;
      cv::circle(undistorted_im, im_center, 10, cv::Scalar(0,255,0), 2, 8);
//       for(unsigned int i = 0; i < ellipse_filtetred.size(); i++){
// 	cv::Point2f p = ellipse_filtetred[i].center;
// 	cv::Size2f s = ellipse_filtetred[i].size;
// 	double rot = std::atan2(p.y - im_center.y, p.x - im_center.x)*180/M_PI;
// 	cv::line(undistorted_im, p, im_center, cv::Scalar(255,0,0), 2, 8);
// 
// 	double dist_to_center = abs(sqrt((p.x-im_center.x)*(p.x-im_center.x) + (p.y-im_center.y)*(p.y-im_center.y)) - s.height/2);
// 	myfile << dist_to_center << " " << s.height << " " << s.width << "\n"; 
//       }
    }
  }
  
  void showImage(){
    if(!fst_im){
      cv::imshow("undistorted image", undistorted_im);
      cv::imshow("map", img_map);
//       cv::imshow("MOG", fgMaskMOG);
//       cv::imshow("MOG2", fgMaskMOG2);
      cv::waitKey(3);
    }
  }
  
  void spinOnce(){
     ros::spinOnce();
  }
  
  void CallBackFunc(int event, int x, int y, int flags){
    if  ( event == cv::EVENT_LBUTTONDOWN ){
      double dist_to_center = sqrt((x-im_center.x)*(x-im_center.x) + (y-im_center.y)*(y-im_center.y));
      std::cout << x << " " << y << " " << dist_to_center << std::endl;
      clicks++;
//       double dist_to_center = sqrt((x-im_center.x)*(x-im_center.x) + (y-im_center.y)*(y-im_center.y));
      myfile << clicks << " " << dist_to_center << "\n"; 
    }
    else if( event == cv::EVENT_RBUTTONDOWN ){
  //       cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if  ( event == cv::EVENT_MBUTTONDOWN ){
  //       cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if ( event == cv::EVENT_MOUSEMOVE ){
  //       cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
    }
  }
  
};

// This is a function, not a class method
void wrappedCallBackFunc(int event, int x, int y, int flags, void* ptr){
    PersonDetector* mcPtr = (PersonDetector*)ptr;
    if(mcPtr != NULL)
        mcPtr->CallBackFunc(event, x, y, flags);
}

int main(int argc, char* argv[]){
  ros::init(argc, argv, "person_detector");
  
  PersonDetector pd;
  
  //set the callback function for any mouse event
  cv::setMouseCallback("undistorted image", wrappedCallBackFunc, (void*)&pd);
  
  ros::Rate loop_rate(10);
  
  while(ros::ok()){
//     ros::Time t = ros::Time::now();
    
//     pd.find_contours();
//     pd.merge_detections();
    pd.check_person();
    pd.showImage();
    
    pd.spinOnce();
    loop_rate.sleep();
    
//     double elapsed = ros::Time::now().toSec() - t.toSec();
//     ROS_INFO("Elapsed: %f", elapsed);
  }
  
  return 0;
}
