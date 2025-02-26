#include "rclcpp/rclcpp.hpp"
#include "pkg_test_cpp/turtlesim_action_server.hpp"
#include "pkg_test_cpp/turtlesim_subaction.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  // 액션 서버와 pose 업데이트용 서브 액션 노드 생성
  auto action_server = std::make_shared<TurtlesimActionServer>();
  auto sub_action = std::make_shared<TurtlesimSubAction>(action_server);

  // MultiThreadedExecutor를 사용해 두 노드를 동시에 실행
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(action_server);
  executor.add_node(sub_action);

  executor.spin();
  rclcpp::shutdown();

  return 0;
}