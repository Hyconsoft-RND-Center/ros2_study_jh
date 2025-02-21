#ifndef TURTLESIM_PUBLISHER_HPP
#define TURTLESIM_PUBLISHER_HPP

#include "rclcpp/node.hpp"
#include "geometry_msgs/msg/twist.hpp"

class TurtlesimPublisher : public rclcpp::Node {
    public:
        TurtlesimPublisher();

    private:
        void timer_callback();

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};

#endif //TURTLESIM_PUBLISHER_HPP