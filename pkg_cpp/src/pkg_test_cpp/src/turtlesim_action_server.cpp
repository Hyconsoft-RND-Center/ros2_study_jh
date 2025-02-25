#include "pkg_test_cpp/turtlesim_action_server.hpp"
#include <cmath>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

TurtlesimActionServer::TurtlesimActionServer() : Node("turtlesim_action_server"), total_dist(0.0), is_first_time(true) {
  // cmd_vel 퍼블리셔 생성
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

  // 액션 서버 생성
    action_server = rclcpp_action::create_server<DistTurtle>(
        this,
        "dist_turtle",
        std::bind(&TurtlesimActionServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&TurtlesimActionServer::handle_cancel, this, std::placeholders::_1),
        std::bind(&TurtlesimActionServer::handle_accepted, this, std::placeholders::_1));
    
    this->declare_parameter<double>("quatile_time", quatile_time_);
    this->declare_parameter<double>("almost_goal_time", almost_goal_time_);

    std::vector<rclcpp::Parameter> params = this->get_parameters({"quatile_time", "almost_goal_time"});
    parameter_callback_handle_ = this->add_on_set_parameters_callback(
        std::bind(&TurtlesimActionServer::parameter_callback, this, std::placeholders::_1));
}

rcl_interfaces::msg::SetParametersResult TurtlesimActionServer::parameter_callback(
    const std::vector<rclcpp::Parameter> & parameters)
  {
    RCLCPP_INFO(this->get_logger(), "Parameter callback triggered.");
  
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "Parameter updated successfully";
  
    for (const auto & param : parameters) {
      if (param.get_name() == "quatile_time") {
        quatile_time_ = param.as_double();
        RCLCPP_INFO(this->get_logger(), "quatile_time updated to: %.2f", quatile_time_);
      } else if (param.get_name() == "almost_goal_time") {
        almost_goal_time_ = param.as_double();
        RCLCPP_INFO(this->get_logger(), "almost_goal_time updated to: %.2f", almost_goal_time_);
      } else {
        result.successful = false;
        result.reason = "Unknown parameter";
        RCLCPP_WARN(this->get_logger(), "Unknown parameter change attempted: %s", param.get_name().c_str());
      }
    }
  
    return result;
  }
  

void TurtlesimActionServer::update_pose(const turtlesim::msg::Pose::SharedPtr msg) {
  // 외부에서 전달받은 pose 정보로 현재 pose 업데이트
    current_pose_ = *msg;
}

float TurtlesimActionServer::calc_diff_pose() {
    if(this->is_first_time) {
        previous_pose_ = current_pose_;
        is_first_time = false;
    }

    float diff_dist = (float)std::hypot((current_pose_.x - previous_pose_.x), (current_pose_.y - previous_pose_.y));

    previous_pose_ = current_pose_;

    //std::cout << diff_dist << std::endl;

    return diff_dist;
}

rclcpp_action::GoalResponse TurtlesimActionServer::handle_goal(
    const rclcpp_action::GoalUUID & /*uuid*/,
    std::shared_ptr<const DistTurtle::Goal> goal)
{
    RCLCPP_INFO(this->get_logger(), "Goal 요청: dist=%.2f, linear_x=%.2f, angular_z=%.2f",
                goal->dist, goal->linear_x, goal->angular_z);
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}
  
rclcpp_action::CancelResponse TurtlesimActionServer::handle_cancel(
    const std::shared_ptr<GoalHandleDistTurtle> /*goal_handle*/)
{
    RCLCPP_INFO(this->get_logger(), "Goal 취소 요청");
    return rclcpp_action::CancelResponse::ACCEPT;
}
  
void TurtlesimActionServer::handle_accepted(
    const std::shared_ptr<GoalHandleDistTurtle> goal_handle)
{
    // 별도의 스레드에서 실행
    std::thread{std::bind(&TurtlesimActionServer::execute_callback, this, goal_handle)}.detach();
}

void TurtlesimActionServer::execute_callback(
    const std::shared_ptr<GoalHandleDistTurtle> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Goal 실행 시작");
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<DistTurtle::Feedback>();
    auto result = std::make_shared<DistTurtle::Result>();
  
    // goal에서 전달받은 속도 값으로 Twist 메시지 생성
    geometry_msgs::msg::Twist twist;
    twist.linear.x = goal->linear_x;
    twist.angular.z = goal->angular_z;
  
    rclcpp::Rate rate(100);  // 100Hz => 0.01초 간격
    while (rclcpp::ok()) {
      total_dist += calc_diff_pose();
      feedback->remained_dist = goal->dist - total_dist;
      publisher_->publish(twist);
      goal_handle->publish_feedback(feedback);
  
      if (feedback->remained_dist < 0.2) {
        break;
      }
      rate.sleep();
    }
  
    result->pos_x = current_pose_.x;
    result->pos_y = current_pose_.y;
    result->pos_theta = current_pose_.theta;
    result->result_dist = total_dist;
  
    // 다음 목표를 위해 변수 초기화
    total_dist = 0.0;
    is_first_time = true;
  
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "Goal 완료");
}