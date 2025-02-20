#ifndef TURTLESIM_SERVICE_SERVER_HPP
#define TURTLESIM_SERVICE_SERVER_HPP

#include "rclcpp/node.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"
#include "turtlesim/srv/spawn.hpp"
#include <vector>
#include <cmath>
#include <iostream>

#include "pkg_test_cpp_msg/srv/multi_spawn.hpp"

class TurtlesimMultiSpawning : public rclcpp::Node {
    public:
        TurtlesimMultiSpawning();

    private:
        void callback_service(
            const std::shared_ptr<pkg_test_cpp_msg::srv::MultiSpawn::Request> request_,
            std::shared_ptr<pkg_test_cpp_msg::srv::MultiSpawn::Response> response_ 
        );

        void wait_for_services();

        void calc_position(const int n, const double r, std::vector<double>& x_vec, std::vector<double>& y_vec, std::vector<double>& theta_vec);

        rclcpp::Service<pkg_test_cpp_msg::srv::MultiSpawn>::SharedPtr server_;
        rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawn_client_;
        rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr teleport_client_;

        double center_x_ = 5.54;
        double center_y_ = 5.54;
};

#endif //TURTLESIM_SERVICE_SERVER_HPP