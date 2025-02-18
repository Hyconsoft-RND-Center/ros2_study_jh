#include "rclcpp/rclcpp.hpp"
#include "pkg_test_cpp/turtlesim_publisher.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlesimPublisher>());
    rclcpp::shutdown();

    return 0;
}