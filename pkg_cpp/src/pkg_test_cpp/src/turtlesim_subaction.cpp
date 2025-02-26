#include "pkg_test_cpp/turtlesim_subaction.hpp"
#include "pkg_test_cpp/turtlesim_action_server.hpp"

TurtlesimSubAction::TurtlesimSubAction(std::shared_ptr<TurtlesimActionServer> action_server)
: TurtleSubscriber("turtlesim_subaction"), action_server_(action_server)
{
}

void TurtlesimSubAction::pose_callback(const turtlesim::msg::Pose::SharedPtr msg)
{
  // 구독한 pose 정보를 액션 서버에 업데이트
  if (action_server_) {
    action_server_->update_pose(msg);
  }
}
