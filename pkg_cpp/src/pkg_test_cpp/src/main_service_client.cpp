#include "pkg_test_cpp/turtlesim_service_client.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlesimClinetService>());
    rclcpp::shutdown();

    return 0;
}