#ifndef TURTLESIM_CMD_AND_POSE_HPP
#define TURTLESIM_CMD_AND_POSE_HPP

#include "rclcpp/node.hpp"
#include "turtlesim/msg/pose.hpp"
#include "pkg_test_cpp_msg/msg/cmd_and_pose_vel.hpp"

class TurtlesimCmdAndPose : public rclcpp::Node {
    public:
        TurtlesimCmdAndPose();

    private:
        void callback(const turtlesim::msg::Pose::SharedPtr msg);

        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub_pose_;

        pkg_test_cpp_msg::msg::CmdAndPoseVel cmd_pose_;
};

#endif //TURTLESIM_CMD_AND_POSE_VEL_HPP