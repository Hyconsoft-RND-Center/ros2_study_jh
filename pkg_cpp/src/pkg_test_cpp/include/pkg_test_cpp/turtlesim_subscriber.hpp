#ifndef TURTLESIM_SUBSCRIBER_HPP
#define TURTLESIM_SUBSCRIBER_HPP

#include <iostream>

#include "rclcpp/node.hpp"
#include "turtlesim/msg/pose.hpp"

class TurtlesimSubscriber : public rclcpp::Node {
    public:
        TurtlesimSubscriber();
    
    private:
        void callback(const turtlesim::msg::Pose::SharedPtr msg);
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
};

#endif //TURTLESIM_SUBSCRIBER_HPP