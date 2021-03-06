// Generated by gencpp from file hannrs_msgs/Goal.msg
// DO NOT EDIT!


#ifndef HANNRS_MSGS_MESSAGE_GOAL_H
#define HANNRS_MSGS_MESSAGE_GOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose.h>

namespace hannrs_msgs
{
template <class ContainerAllocator>
struct Goal_
{
  typedef Goal_<ContainerAllocator> Type;

  Goal_()
    : header()
    , action()
    , person()
    , object()
    , pose()  {
    }
  Goal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , action(_alloc)
    , person(_alloc)
    , object(_alloc)
    , pose(_alloc)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _action_type;
  _action_type action;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _person_type;
  _person_type person;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _object_type;
  _object_type object;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;




  typedef boost::shared_ptr< ::hannrs_msgs::Goal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hannrs_msgs::Goal_<ContainerAllocator> const> ConstPtr;

}; // struct Goal_

typedef ::hannrs_msgs::Goal_<std::allocator<void> > Goal;

typedef boost::shared_ptr< ::hannrs_msgs::Goal > GoalPtr;
typedef boost::shared_ptr< ::hannrs_msgs::Goal const> GoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hannrs_msgs::Goal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hannrs_msgs::Goal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hannrs_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'hannrs_msgs': ['/home/amateus/HANNRS/catkin_ws/src/hannrs_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::Goal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::Goal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Goal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::Goal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Goal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::Goal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hannrs_msgs::Goal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f1534f9cbdf89e2a447adf2acc6beaf5";
  }

  static const char* value(const ::hannrs_msgs::Goal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf1534f9cbdf89e2aULL;
  static const uint64_t static_value2 = 0x447adf2acc6beaf5ULL;
};

template<class ContainerAllocator>
struct DataType< ::hannrs_msgs::Goal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hannrs_msgs/Goal";
  }

  static const char* value(const ::hannrs_msgs::Goal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hannrs_msgs::Goal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header             header\n\
string             action\n\
string             person\n\
string             object\n\
geometry_msgs/Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
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
";
  }

  static const char* value(const ::hannrs_msgs::Goal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hannrs_msgs::Goal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.action);
      stream.next(m.person);
      stream.next(m.object);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Goal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hannrs_msgs::Goal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hannrs_msgs::Goal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "action: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.action);
    s << indent << "person: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.person);
    s << indent << "object: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.object);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HANNRS_MSGS_MESSAGE_GOAL_H
