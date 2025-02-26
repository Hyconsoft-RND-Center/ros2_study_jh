#include "pkg_test_cpp/turtlesim_service_client.hpp"

TurtlesimClinetService::TurtlesimClinetService() : Node("turtlesim_service_client") {
    service_client_ = this->create_client<turtlesim::srv::TeleportAbsolute>("/turtle1/teleport_absolute");

    while (!service_client_->wait_for_service(std::chrono::seconds(1))) {
        RCLCPP_WARN(this->get_logger(), "Waiting for service...");
    }

    send_service_request();
}

void TurtlesimClinetService::send_service_request() {
    auto request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    request->x = 1.0;
    request->y = 1.1;
    request->theta = 3.14;

    auto result_future = service_client_->async_send_request(request);

    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future) == rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_INFO(this->get_logger(), "Service call succeeded");
    } else {
        RCLCPP_ERROR(this->get_logger(), "Failed to call service");
    }
}