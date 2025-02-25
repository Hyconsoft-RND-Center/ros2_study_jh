#ifndef TURTLESIM_ACTION_SERVER_HPP
#define TURTLESIM_ACTION_SERVER_HPP

#include "rclcpp/node.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "turtlesim/msg/pose.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"

#include "pkg_test_cpp_msg/action/dist_turtle.hpp"

class TurtlesimActionServer : public rclcpp::Node {
    public:
        using DistTurtle = pkg_test_cpp_msg::action::DistTurtle;
        using GoalHandleDistTurtle = rclcpp_action::ServerGoalHandle<DistTurtle>;

        TurtlesimActionServer();

        void update_pose(const turtlesim::msg::Pose::SharedPtr msg);

    private:
        rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const DistTurtle::Goal> goal);
        rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleDistTurtle> goal_handle);
        void handle_accepted(const std::shared_ptr<GoalHandleDistTurtle> goal_handle);
        void execute_callback(const std::shared_ptr<GoalHandleDistTurtle> goal_handle);
        rcl_interfaces::msg::SetParametersResult parameter_callback(const std::vector<rclcpp::Parameter>& params);

        float calc_diff_pose();

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        rclcpp_action::Server<DistTurtle>::SharedPtr action_server;
        
        float total_dist;
        bool is_first_time;
        double quatile_time_;
        double almost_goal_time_;
        //파라미터 콜백
        OnSetParametersCallbackHandle::SharedPtr parameter_callback_handle_;
        turtlesim::msg::Pose current_pose_;
        turtlesim::msg::Pose previous_pose_;
};

#endif //TURTLESIM_ACTION_SERVER_HPP