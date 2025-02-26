#include "pkg_test_cpp/turtlesim_service_server.hpp"

TurtlesimMultiSpawning::TurtlesimMultiSpawning() : Node("mult_spawn") {
    server_ = this->create_service<pkg_test_cpp_msg::srv::MultiSpawn>(
        "multi_spawn", std::bind(&TurtlesimMultiSpawning::callback_service, this, std::placeholders::_1, std::placeholders::_2)
    );

    spawn_client_ = this->create_client<turtlesim::srv::Spawn>("/spawn");

    RCLCPP_INFO(this->get_logger(), "TurtlesimMultiSpawning service node has started.");
}

void TurtlesimMultiSpawning::calc_position(const int n, const double r, std::vector<double>& x_vec, std::vector<double>& y_vec, std::vector<double>& theta_vec) {
    double gap_theta = 2 * M_PI / n;

    for (int i = 0; i < n; ++i) {
        double angle = gap_theta * i;
        x_vec.emplace_back(r * cos(angle));
        y_vec.emplace_back(r * sin(angle));
        theta_vec.emplace_back(angle);
    }
}

void TurtlesimMultiSpawning::callback_service(
    const std::shared_ptr<pkg_test_cpp_msg::srv::MultiSpawn::Request> request_,
    std::shared_ptr<pkg_test_cpp_msg::srv::MultiSpawn::Response> response_
) {
    std::vector<double> x_vec, y_vec, theta_vec;
    calc_position(request_->num, 3.0, x_vec, y_vec, theta_vec);

    // spawn 서비스가 활성화될 때까지 대기
    if (!spawn_client_->wait_for_service(std::chrono::seconds(3))) {
        RCLCPP_ERROR(this->get_logger(), "Spawn service is not available. Exiting...");
        return;
    }

    for (size_t i = 0; i < request_->num; ++i) {
        auto spawn_request_ = std::make_shared<turtlesim::srv::Spawn::Request>();
        spawn_request_->x = x_vec[i] + center_x_;
        spawn_request_->y = y_vec[i] + center_y_;
        spawn_request_->theta = theta_vec[i];

        response_->x.push_back(spawn_request_->x);
        response_->y.push_back(spawn_request_->y);
        response_->theta.push_back(spawn_request_->theta);

        spawn_client_->async_send_request(spawn_request_);
    }

    RCLCPP_INFO(this->get_logger(), "Spawned %d turtles.", request_->num);
}