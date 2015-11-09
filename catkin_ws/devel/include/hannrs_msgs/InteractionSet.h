// Generated by gencpp from file hannrs_msgs/InteractionSet.msg
// DO NOT EDIT!


#ifndef HANNRS_MSGS_MESSAGE_INTERACTIONSET_H
#define HANNRS_MSGS_MESSAGE_INTERACTIONSET_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64.h>

namespace hannrs_msgs
{
template <class ContainerAllocator>
struct InteractionSet_
{
  typedef InteractionSet_<ContainerAllocator> Type;

  InteractionSet_()
    : center()
    , radius()
    , importance()  {
    }
  InteractionSet_(const ContainerAllocator& _alloc)
    : center(_alloc)
    , radius(_alloc)
    , importance(_alloc)  {
    }



   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _center_type;
  _center_type center;

   typedef  ::std_msgs::Float64_<ContainerAllocator>  _radius_type;
  _radius_type radius;

   typedef  ::std_msgs::Float64_<ContainerAllocator>  _importance_type;
  _importance_type importance;




  typedef boost::shared_ptr< ::hannrs_msgs::InteractionSet_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hannrs_msgs::InteractionSet_<ContainerAllocator> const> ConstPtr;

}; // struct InteractionSet_

typedef ::hannrs_msgs::InteractionSet_<std::allocator<void> > InteractionSet;

typedef boost::shared_ptr< ::hannrs_msgs::InteractionSet > InteractionSetPtr;
typedef boost::shared_ptr< ::hannrs_msgs::InteractionSet const> InteractionSetConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hannrs_msgs::InteractionSet_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hannrs_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'hannrs_msgs': ['/home/amateus/HANNRS/catkin_ws/src/hannrs_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hannrs_msgs::InteractionSet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hannrs_msgs::InteractionSet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hannrs_msgs::InteractionSet_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bb76bfc545446f6e2a45fcee2a9e6bc8";
  }

  static const char* value(const ::hannrs_msgs::InteractionSet_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbb76bfc545446f6eULL;
  static const uint64_t static_value2 = 0x2a45fcee2a9e6bc8ULL;
};

template<class ContainerAllocator>
struct DataType< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hannrs_msgs/InteractionSet";
  }

  static const char* value(const ::hannrs_msgs::InteractionSet_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Point center\n\
std_msgs/Float64 radius\n\
std_msgs/Float64 importance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: std_msgs/Float64\n\
float64 data\n\
";
  }

  static const char* value(const ::hannrs_msgs::InteractionSet_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.center);
      stream.next(m.radius);
      stream.next(m.importance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct InteractionSet_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hannrs_msgs::InteractionSet_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hannrs_msgs::InteractionSet_<ContainerAllocator>& v)
  {
    s << indent << "center: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.center);
    s << indent << "radius: ";
    s << std::endl;
    Printer< ::std_msgs::Float64_<ContainerAllocator> >::stream(s, indent + "  ", v.radius);
    s << indent << "importance: ";
    s << std::endl;
    Printer< ::std_msgs::Float64_<ContainerAllocator> >::stream(s, indent + "  ", v.importance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HANNRS_MSGS_MESSAGE_INTERACTIONSET_H
