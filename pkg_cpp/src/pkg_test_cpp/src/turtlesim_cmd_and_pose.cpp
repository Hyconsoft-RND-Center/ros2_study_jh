#include "pkg_test_cpp/turtlesim_cmd_and_pose.hpp"

TurtlesimCmdAndPose::TurtlesimCmdAndPose() : Node("turtlesim_cmd_pose") {
    sub_pose_ = this->create_subscription<turtlesim::msg::Pose> (
        "/turtle1/pose", 10, std::bind(&TurtlesimCmdAndPose::callback_pose, this, std::placeholders::_1)
    );
    
    sub_cmdvel_ = this->create_subscription<geometry_msgs::msg::Twist> (
        "/turtle1/cmd_vel", 10, std::bind(&TurtlesimCmdAndPose::callback_cmd, this, std::placeholders::_1)
    );
    
    publisher_ = this->create_publisher<pkg_test_cpp_msg::msg::CmdAndPoseVel> ("/cmd_and_pose", 10);
    
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&TurtlesimCmdAndPose::timer_callback, this)
    );
}

void TurtlesimCmdAndPose::callback_pose(const turtlesim::msg::Pose::SharedPtr msg) {
    cmd_pose_.pose_x = msg->x;
    cmd_pose_.pose_y = msg->y;
    cmd_pose_.linear_vel = msg->linear_velocity;
    cmd_pose_.angular_vel = msg->angular_velocity;

    // RCLCPP_INFO(this->get_logger(), "Pose: x = %.2f, y = %.2f, linear_velocity = %.2f, angular_velocity = %.2f", 
    // msg->x, msg->y, msg->linear_velocity, msg->angular_velocity); 
}

void TurtlesimCmdAndPose::callback_cmd(const geometry_msgs::msg::Twist::SharedPtr msg) {
    cmd_pose_.cmd_vel_linear = msg->linear.x;
    cmd_pose_.cmd_vel_angular = msg->angular.z;

    RCLCPP_INFO(this->get_logger(), "cmd vel : cmd_vel_linear = %.2f, cmd_vel_angular = %.2f", 
    msg->linear.x, msg->angular.z); 
}

void TurtlesimCmdAndPose::timer_callback() {
    publisher_->publish(cmd_pose_);
}