#include "pkg_test_cpp/turtlesim_action_server.hpp"

TurtlesimActionServer::TurtlesimActionServer() : Node("turtlesim_action_server") {
    action_server_ = rclcpp_action::create_server<DistTurtle>(
        this,
        "dist_turtle",
        [](const rclcpp_action::GoalUUID&, std::shared_ptr<const DistTurtle::Goal>) {
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        },
        [](const std::shared_ptr<GoalHandleDistTurtle>) {
            return rclcpp_action::CancelResponse::ACCEPT;
        },
        std::bind(&TurtlesimActionServer::execute_callback, this, std::placeholders::_1)
    );

    RCLCPP_INFO(this->get_logger(), "Turtlesim Action Server has started.");
}

void TurtlesimActionServer::execute_callback(
    const std::shared_ptr<GoalHandleDistTurtle> goal_handle_) {

        RCLCPP_INFO(this->get_logger(), "Executing goal...");

        auto feedback_msg = std::make_shared<DistTurtle::Feedback>();

        for (int i = 0; i < 10; ++i) {
            feedback_msg->remined_dist = static_cast<float>(10 - i);
            goal_handle_->publish_feedback(feedback_msg);
            RCLCPP_INFO(this->get_logger(), "Feddback : remined_dist = %.2f", feedback_msg->remined_dist);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        auto result = std::make_shared<DistTurtle::Result>();
        goal_handle_->succeed(result);

        RCLCPP_INFO(this->get_logger(), "Action complted successfully");

        return;
}