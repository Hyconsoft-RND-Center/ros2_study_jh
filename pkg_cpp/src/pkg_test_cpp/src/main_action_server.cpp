#include "rclcpp/rclcpp.hpp"
#include "pkg_test_cpp/turtlesim_action_server.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtlesimActionServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}