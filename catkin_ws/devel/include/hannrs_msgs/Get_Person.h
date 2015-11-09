// Generated by gencpp from file hannrs_msgs/Get_Person.msg
// DO NOT EDIT!


#ifndef HANNRS_MSGS_MESSAGE_GET_PERSON_H
#define HANNRS_MSGS_MESSAGE_GET_PERSON_H

#include <ros/service_traits.h>


#include <hannrs_msgs/Get_PersonRequest.h>
#include <hannrs_msgs/Get_PersonResponse.h>


namespace hannrs_msgs
{

struct Get_Person
{

typedef Get_PersonRequest Request;
typedef Get_PersonResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Get_Person
} // namespace hannrs_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::hannrs_msgs::Get_Person > {
  static const char* value()
  {
    return "26f0c8a5e492d0bf40eb98ffffc050e6";
  }

  static const char* value(const ::hannrs_msgs::Get_Person&) { return value(); }
};

template<>
struct DataType< ::hannrs_msgs::Get_Person > {
  static const char* value()
  {
    return "hannrs_msgs/Get_Person";
  }

  static const char* value(const ::hannrs_msgs::Get_Person&) { return value(); }
};


// service_traits::MD5Sum< ::hannrs_msgs::Get_PersonRequest> should match 
// service_traits::MD5Sum< ::hannrs_msgs::Get_Person > 
template<>
struct MD5Sum< ::hannrs_msgs::Get_PersonRequest>
{
  static const char* value()
  {
    return MD5Sum< ::hannrs_msgs::Get_Person >::value();
  }
  static const char* value(const ::hannrs_msgs::Get_PersonRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::hannrs_msgs::Get_PersonRequest> should match 
// service_traits::DataType< ::hannrs_msgs::Get_Person > 
template<>
struct DataType< ::hannrs_msgs::Get_PersonRequest>
{
  static const char* value()
  {
    return DataType< ::hannrs_msgs::Get_Person >::value();
  }
  static const char* value(const ::hannrs_msgs::Get_PersonRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::hannrs_msgs::Get_PersonResponse> should match 
// service_traits::MD5Sum< ::hannrs_msgs::Get_Person > 
template<>
struct MD5Sum< ::hannrs_msgs::Get_PersonResponse>
{
  static const char* value()
  {
    return MD5Sum< ::hannrs_msgs::Get_Person >::value();
  }
  static const char* value(const ::hannrs_msgs::Get_PersonResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::hannrs_msgs::Get_PersonResponse> should match 
// service_traits::DataType< ::hannrs_msgs::Get_Person > 
template<>
struct DataType< ::hannrs_msgs::Get_PersonResponse>
{
  static const char* value()
  {
    return DataType< ::hannrs_msgs::Get_Person >::value();
  }
  static const char* value(const ::hannrs_msgs::Get_PersonResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HANNRS_MSGS_MESSAGE_GET_PERSON_H
