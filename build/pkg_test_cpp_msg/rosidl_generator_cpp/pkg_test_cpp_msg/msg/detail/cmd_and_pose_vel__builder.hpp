// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pkg_test_cpp_msg:msg/CmdAndPoseVel.idl
// generated code does not contain a copyright notice

#ifndef PKG_TEST_CPP_MSG__MSG__DETAIL__CMD_AND_POSE_VEL__BUILDER_HPP_
#define PKG_TEST_CPP_MSG__MSG__DETAIL__CMD_AND_POSE_VEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pkg_test_cpp_msg/msg/detail/cmd_and_pose_vel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pkg_test_cpp_msg
{

namespace msg
{

namespace builder
{

class Init_CmdAndPoseVel_angular_vel
{
public:
  explicit Init_CmdAndPoseVel_angular_vel(::pkg_test_cpp_msg::msg::CmdAndPoseVel & msg)
  : msg_(msg)
  {}
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel angular_vel(::pkg_test_cpp_msg::msg::CmdAndPoseVel::_angular_vel_type arg)
  {
    msg_.angular_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel msg_;
};

class Init_CmdAndPoseVel_linear_vel
{
public:
  explicit Init_CmdAndPoseVel_linear_vel(::pkg_test_cpp_msg::msg::CmdAndPoseVel & msg)
  : msg_(msg)
  {}
  Init_CmdAndPoseVel_angular_vel linear_vel(::pkg_test_cpp_msg::msg::CmdAndPoseVel::_linear_vel_type arg)
  {
    msg_.linear_vel = std::move(arg);
    return Init_CmdAndPoseVel_angular_vel(msg_);
  }

private:
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel msg_;
};

class Init_CmdAndPoseVel_pose_y
{
public:
  explicit Init_CmdAndPoseVel_pose_y(::pkg_test_cpp_msg::msg::CmdAndPoseVel & msg)
  : msg_(msg)
  {}
  Init_CmdAndPoseVel_linear_vel pose_y(::pkg_test_cpp_msg::msg::CmdAndPoseVel::_pose_y_type arg)
  {
    msg_.pose_y = std::move(arg);
    return Init_CmdAndPoseVel_linear_vel(msg_);
  }

private:
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel msg_;
};

class Init_CmdAndPoseVel_pose_x
{
public:
  explicit Init_CmdAndPoseVel_pose_x(::pkg_test_cpp_msg::msg::CmdAndPoseVel & msg)
  : msg_(msg)
  {}
  Init_CmdAndPoseVel_pose_y pose_x(::pkg_test_cpp_msg::msg::CmdAndPoseVel::_pose_x_type arg)
  {
    msg_.pose_x = std::move(arg);
    return Init_CmdAndPoseVel_pose_y(msg_);
  }

private:
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel msg_;
};

class Init_CmdAndPoseVel_cmd_vel_angular
{
public:
  explicit Init_CmdAndPoseVel_cmd_vel_angular(::pkg_test_cpp_msg::msg::CmdAndPoseVel & msg)
  : msg_(msg)
  {}
  Init_CmdAndPoseVel_pose_x cmd_vel_angular(::pkg_test_cpp_msg::msg::CmdAndPoseVel::_cmd_vel_angular_type arg)
  {
    msg_.cmd_vel_angular = std::move(arg);
    return Init_CmdAndPoseVel_pose_x(msg_);
  }

private:
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel msg_;
};

class Init_CmdAndPoseVel_cmd_vel_linear
{
public:
  Init_CmdAndPoseVel_cmd_vel_linear()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CmdAndPoseVel_cmd_vel_angular cmd_vel_linear(::pkg_test_cpp_msg::msg::CmdAndPoseVel::_cmd_vel_linear_type arg)
  {
    msg_.cmd_vel_linear = std::move(arg);
    return Init_CmdAndPoseVel_cmd_vel_angular(msg_);
  }

private:
  ::pkg_test_cpp_msg::msg::CmdAndPoseVel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pkg_test_cpp_msg::msg::CmdAndPoseVel>()
{
  return pkg_test_cpp_msg::msg::builder::Init_CmdAndPoseVel_cmd_vel_linear();
}

}  // namespace pkg_test_cpp_msg

#endif  // PKG_TEST_CPP_MSG__MSG__DETAIL__CMD_AND_POSE_VEL__BUILDER_HPP_
