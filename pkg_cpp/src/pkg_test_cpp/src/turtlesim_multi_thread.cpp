#include "pkg_test_cpp/turtlesim_multi_thread.hpp"

namespace pkg_test_cpp {

TurtlesimMultiThread::TurtlesimMultiThread() : Node("turtlesim_multi_threaded") {
    // Executor와 노드 초기화
    executor_ = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
    publisher_ = std::make_shared<TurtlesimPublisher>();
    subscriber_ = std::make_shared<TurtlesimSubscriber>();

    // Executor에 노드 추가
    executor_->add_node(publisher_);
    executor_->add_node(subscriber_);
}

TurtlesimMultiThread::~TurtlesimMultiThread() {
    // Executor 종료
    executor_->cancel();
}

} // namespace pkg_test_cpp
