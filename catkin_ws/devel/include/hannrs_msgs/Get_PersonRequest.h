// Generated by gencpp from file hannrs_msgs/Get_PersonRequest.msg
// DO NOT EDIT!


#ifndef HANNRS_MSGS_MESSAGE_GET_PERSONREQUEST_H
#define HANNRS_MSGS_MESSAGE_GET_PERSONREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/String.h>

namespace hannrs_msgs
{
template <class ContainerAllocator>
struct Get_PersonRequest_
{
  typedef Get_PersonRequest_<ContainerAllocator> Type;

  Get_PersonRequest_()
    : name()  {
    }
  Get_PersonRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)  {
    }



   typedef  ::std_msgs::String_<ContainerAllocator>  _name_type;
  _name_type name;




  typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> const> ConstPtr;

}; // struct Get_PersonRequest_

typedef ::hannrs_msgs::Get_PersonRequest_<std::allocator<void> > Get_PersonRequest;

typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonRequest > Get_PersonRequestPtr;
typedef boost::shared_ptr< ::hannrs_msgs::Get_PersonRequest const> Get_PersonRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0fce35bd9f5b27a63eb9b0e831759a0b";
  }

  static const char* value(const ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0fce35bd9f5b27a6ULL;
  static const uint64_t static_value2 = 0x3eb9b0e831759a0bULL;
};

template<class ContainerAllocator>
struct DataType< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hannrs_msgs/Get_PersonRequest";
  }

  static const char* value(const ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/String name\n\
\n\
================================================================================\n\
MSG: std_msgs/String\n\
string data\n\
";
  }

  static const char* value(const ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Get_PersonRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hannrs_msgs::Get_PersonRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HANNRS_MSGS_MESSAGE_GET_PERSONREQUEST_H