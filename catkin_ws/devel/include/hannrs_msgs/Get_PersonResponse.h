// Generated by gencpp from file hannrs_msgs/Get_PersonResponse.msg
// DO NOT EDIT!


#ifndef HANNRS_MSGS_MESSAGE_GET_PERSONRESPONSE_H
#define HANNRS_MSGS_MESSAGE_GET_PERSONRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose.h>
#include <std_msgs/String.h>

namespace hannrs_msgs
{
template <class ContainerAllocator>
struct Get_PersonResponse_
{
  typedef Get_PersonResponse_<ContainerAllocator> Type;

  Get_PersonResponse_()
    : pose()
    , status()  {
    }
  Get_PersonResponse_(const ContainerAllocator& _alloc)
    : pose(_alloc)
    , status(_alloc)  {
    }



   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::std_msgs::String_<ContainerAllocator>  _status_type;
  _status_type status;




  typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> const> ConstPtr;

}; // struct Get_PersonResponse_

typedef ::hannrs_msgs::Get_PersonResponse_<std::allocator<void> > Get_PersonResponse;

typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonResponse > Get_PersonResponsePtr;
typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonResponse const> Get_PersonResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hannrs_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'hannrs_msgs': ['/home/amateus/HANNRS/catkin_ws/src/hannrs_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0fe042f9cd3458896776862e431533c2";
  }

  static const char* value(const ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0fe042f9cd345889ULL;
  static const uint64_t static_value2 = 0x6776862e431533c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hannrs_msgs/Get_PersonResponse";
  }

  static const char* value(const ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose pose\n\
std_msgs/String status\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: std_msgs/String\n\
string data\n\
";
  }

  static const char* value(const ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pose);
      stream.next(m.status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Get_PersonResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hannrs_msgs::Get_PersonResponse_<ContainerAllocator>& v)
  {
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "status: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HANNRS_MSGS_MESSAGE_GET_PERSONRESPONSE_H