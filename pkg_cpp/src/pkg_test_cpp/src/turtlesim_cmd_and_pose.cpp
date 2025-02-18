#include "pkg_test_cpp/turtlesim_cmd_and_pose.hpp"

TurtlesimCmdAndPose::TurtlesimCmdAndPose() : Node("turtlesim_cmd_pose") {
    sub_pose_ = this->create_subscription<turtlesim::msg::Pose> (
        "/turtle1/pose", 10, std::bind(&TurtlesimCmdAndPose::callback, this, std::placeholders::_1)
    );
}

void TurtlesimCmdAndPose::callback(const turtlesim::msg::Pose::SharedPtr msg) {
    cmd_pose_.pose_x = msg->x;
    cmd_pose_.pose_y = msg->y;
    cmd_pose_.linear_vel = msg->linear_velocity;
    cmd_pose_.angular_vel = msg->angular_velocity;

    RCLCPP_INFO(this->get_logger(), "Pose: x = %.2f, y = %.2f, linear_velocity = %.2f, angular_velocity = %.2f", 
    msg->x, msg->y, msg->linear_velocity, msg->angular_velocity); 
}