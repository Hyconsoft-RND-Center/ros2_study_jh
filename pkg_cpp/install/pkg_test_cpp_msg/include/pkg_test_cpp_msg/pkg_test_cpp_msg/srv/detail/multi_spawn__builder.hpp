// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pkg_test_cpp_msg:srv/MultiSpawn.idl
// generated code does not contain a copyright notice

#ifndef PKG_TEST_CPP_MSG__SRV__DETAIL__MULTI_SPAWN__BUILDER_HPP_
#define PKG_TEST_CPP_MSG__SRV__DETAIL__MULTI_SPAWN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pkg_test_cpp_msg/srv/detail/multi_spawn__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pkg_test_cpp_msg
{

namespace srv
{

namespace builder
{

class Init_MultiSpawn_Request_num
{
public:
  Init_MultiSpawn_Request_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pkg_test_cpp_msg::srv::MultiSpawn_Request num(::pkg_test_cpp_msg::srv::MultiSpawn_Request::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pkg_test_cpp_msg::srv::MultiSpawn_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pkg_test_cpp_msg::srv::MultiSpawn_Request>()
{
  return pkg_test_cpp_msg::srv::builder::Init_MultiSpawn_Request_num();
}

}  // namespace pkg_test_cpp_msg


namespace pkg_test_cpp_msg
{

namespace srv
{

namespace builder
{

class Init_MultiSpawn_Response_theta
{
public:
  explicit Init_MultiSpawn_Response_theta(::pkg_test_cpp_msg::srv::MultiSpawn_Response & msg)
  : msg_(msg)
  {}
  ::pkg_test_cpp_msg::srv::MultiSpawn_Response theta(::pkg_test_cpp_msg::srv::MultiSpawn_Response::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pkg_test_cpp_msg::srv::MultiSpawn_Response msg_;
};

class Init_MultiSpawn_Response_y
{
public:
  explicit Init_MultiSpawn_Response_y(::pkg_test_cpp_msg::srv::MultiSpawn_Response & msg)
  : msg_(msg)
  {}
  Init_MultiSpawn_Response_theta y(::pkg_test_cpp_msg::srv::MultiSpawn_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MultiSpawn_Response_theta(msg_);
  }

private:
  ::pkg_test_cpp_msg::srv::MultiSpawn_Response msg_;
};

class Init_MultiSpawn_Response_x
{
public:
  Init_MultiSpawn_Response_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiSpawn_Response_y x(::pkg_test_cpp_msg::srv::MultiSpawn_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MultiSpawn_Response_y(msg_);
  }

private:
  ::pkg_test_cpp_msg::srv::MultiSpawn_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pkg_test_cpp_msg::srv::MultiSpawn_Response>()
{
  return pkg_test_cpp_msg::srv::builder::Init_MultiSpawn_Response_x();
}

}  // namespace pkg_test_cpp_msg

#endif  // PKG_TEST_CPP_MSG__SRV__DETAIL__MULTI_SPAWN__BUILDER_HPP_
