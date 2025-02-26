#include "pkg_test_cpp/turtle_subscriber.hpp"

TurtleSubscriber::TurtleSubscriber(const std::string & node_name)
: Node(node_name)
{
  // /turtle1/pose 토픽 구독 (파생 클래스에서 pose_callback 구현)
  pose_sub_ = this->create_subscription<turtlesim::msg::Pose>(
    "/turtle1/pose", 10,
    std::bind(&TurtleSubscriber::pose_callback, this, std::placeholders::_1));
}