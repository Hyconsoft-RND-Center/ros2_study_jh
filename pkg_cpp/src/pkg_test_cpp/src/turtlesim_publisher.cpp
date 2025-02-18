#include "pkg_test_cpp/turtlesim_publisher.hpp"

TurtlesimPublisher::TurtlesimPublisher() : Node("turtlesim_publisher") {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&TurtlesimPublisher::timer_callback, this)
    );
}

void TurtlesimPublisher::timer_callback() {
    auto message = geometry_msgs::msg::Twist();

    message.linear.x = 2.0;
    message.angular.z = 2.0;
    RCLCPP_INFO(this->get_logger(), "Turtlesim Publishing: linear.x= %.2f, angular.z= %.2f", message.linear.x, message.angular.z);
    publisher_->publish(message);
}