#ifndef TURTLESIM_SUBACTION_HPP_
#define TURTLESIM_SUBACTION_HPP_

#include "pkg_test_cpp/turtle_subscriber.hpp"
#include <memory>

// 전방 선언: 액션 서버 클래스
class TurtlesimActionServer;

class TurtlesimSubAction : public TurtleSubscriber
{
public:
  // 생성자에서 액션 서버 노드 포인터를 받음
  TurtlesimSubAction(std::shared_ptr<TurtlesimActionServer> action_server);

protected:
  // TurtlesimSubscriber의 순수 가상 함수 재정의
  void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) override;

private:
  std::shared_ptr<TurtlesimActionServer> action_server_;
};

#endif  // TURTLESIM_SUBACTION_HPP_