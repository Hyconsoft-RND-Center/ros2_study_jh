#include "rclcpp/rclcpp.hpp"
#include "pkg_test_cpp/turtlesim_service_server.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlesimMultiSpawning>());
    rclcpp::shutdown();

    return 0;
}