// Generated by gencpp from file hannrs_msgs/Prox_GoalRequest.msg
// DO NOT EDIT!


#ifndef HANNRS_MSGS_MESSAGE_PROX_GOALREQUEST_H
#define HANNRS_MSGS_MESSAGE_PROX_GOALREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/String.h>
#include <std_msgs/String.h>

namespace hannrs_msgs
{
template <class ContainerAllocator>
struct Prox_GoalRequest_
{
  typedef Prox_GoalRequest_<ContainerAllocator> Type;

  Prox_GoalRequest_()
    : action()
    , person()  {
    }
  Prox_GoalRequest_(const ContainerAllocator& _alloc)
    : action(_alloc)
    , person(_alloc)  {
    }



   typedef  ::std_msgs::String_<ContainerAllocator>  _action_type;
  _action_type action;

   typedef  ::std_msgs::String_<ContainerAllocator>  _person_type;
  _person_type person;




  typedef boost::shared_ptr< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> const> ConstPtr;

}; // struct Prox_GoalRequest_

typedef ::hannrs_msgs::Prox_GoalRequest_<std::allocator<void> > Prox_GoalRequest;

typedef boost::shared_ptr< ::hannrs_msgs::Prox_GoalRequest > Prox_GoalRequestPtr;
typedef boost::shared_ptr< ::hannrs_msgs::Prox_GoalRequest const> Prox_GoalRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "80d48c8f7ef3ef2fbb374afd2dbeaff8";
  }

  static const char* value(const ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x80d48c8f7ef3ef2fULL;
  static const uint64_t static_value2 = 0xbb374afd2dbeaff8ULL;
};

template<class ContainerAllocator>
struct DataType< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hannrs_msgs/Prox_GoalRequest";
  }

  static const char* value(const ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/String action\n\
std_msgs/String person\n\
\n\
================================================================================\n\
MSG: std_msgs/String\n\
string data\n\
";
  }

  static const char* value(const ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action);
      stream.next(m.person);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Prox_GoalRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hannrs_msgs::Prox_GoalRequest_<ContainerAllocator>& v)
  {
    s << indent << "action: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.action);
    s << indent << "person: ";
    s << std::endl;
    Printer< ::std_msgs::String_<ContainerAllocator> >::stream(s, indent + "  ", v.person);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HANNRS_MSGS_MESSAGE_PROX_GOALREQUEST_H