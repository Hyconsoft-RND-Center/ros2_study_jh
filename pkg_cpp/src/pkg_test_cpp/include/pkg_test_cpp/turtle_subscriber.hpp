#ifndef TURTLE_SUBSCRIBER_HPP_
#define TURTLE_SUBSCRIBER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"

class TurtleSubscriber : public rclcpp::Node
{
public:
  // 기본 노드 이름은 생성자에서 지정 가능
  TurtleSubscriber(const std::string & node_name = "turtle_subscriber");
protected:
  // 순수 가상 함수로 콜백을 정의 (파생 클래스에서 구현)
  virtual void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) = 0;

  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub_;
};

#endif