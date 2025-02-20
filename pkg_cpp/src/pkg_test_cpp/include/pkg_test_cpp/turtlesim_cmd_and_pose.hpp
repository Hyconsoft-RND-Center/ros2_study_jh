#ifndef TURTLESIM_CMD_AND_POSE_HPP
#define TURTLESIM_CMD_AND_POSE_HPP

#include "rclcpp/node.hpp"
#include "turtlesim/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include "pkg_test_cpp_msg/msg/cmd_and_pose_vel.hpp"

class TurtlesimCmdAndPose : public rclcpp::Node {
    public:
        TurtlesimCmdAndPose();

    private:
        void timer_callback();
        void callback_pose(const turtlesim::msg::Pose::SharedPtr msg);
        void callback_cmd(const geometry_msgs::msg::Twist::SharedPtr msg);

        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_pose_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub_cmdvel_;
        rclcpp::Publisher<pkg_test_cpp_msg::msg::CmdAndPoseVel>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;

        pkg_test_cpp_msg::msg::CmdAndPoseVel cmd_pose_;
};

#endif //TURTLESIM_CMD_AND_POSE_VEL_HPP