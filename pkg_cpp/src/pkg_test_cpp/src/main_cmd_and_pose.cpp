#include "rclcpp/rclcpp.hpp"
#include "pkg_test_cpp/turtlesim_cmd_and_pose.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlesimCmdAndPose>());
    rclcpp::shutdown();
    return 0;
}