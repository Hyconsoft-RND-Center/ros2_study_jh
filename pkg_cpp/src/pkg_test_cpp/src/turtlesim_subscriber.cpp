#include "pkg_test_cpp/turtlesim_subscriber.hpp"

TurtlesimSubscriber::TurtlesimSubscriber() : Node("turtlesim_subscriber") {
    subscription_ = this->create_subscription<turtlesim::msg::Pose> (
        "/turtle1/pose", 10, std::bind(&TurtlesimSubscriber::callback, this, std::placeholders::_1));
}

void TurtlesimSubscriber::callback(const turtlesim::msg::Pose::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "Turtle Position: x = %.2f, y = %.2f, theta = %.2f", 
    msg->x, msg->y, msg->theta);
}