#ifndef TURTLESIM_ACTION_SERVER_HPP
#define TURTLESIM_ACTION_SERVER_HPP

#include "rclcpp/node.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "pkg_test_cpp_msg/action/dist_turtle.hpp"

class TurtlesimActionServer : public rclcpp::Node {
    public:
        using DistTurtle = pkg_test_cpp_msg::action::DistTurtle;
        using GoalHandleDistTurtle = rclcpp_action::ServerGoalHandle<DistTurtle>;

        TurtlesimActionServer();

    private:
        rclcpp_action::Server<DistTurtle>::SharedPtr action_server_;
        

        void execute_callback(
            const std::shared_ptr<GoalHandleDistTurtle> goal_handle
        );

};

#endif //TURTLESIM_ACTION_SERVER_HPP