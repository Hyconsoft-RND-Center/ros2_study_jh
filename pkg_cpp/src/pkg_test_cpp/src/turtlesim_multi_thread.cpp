#include "pkg_test_cpp/turtlesim_multi_thread.hpp"

TurtlesimMultiThread::TurtlesimMultiThread() : Node("turtlesim_multi_threaded") {
    // Executor와 노드 초기화
    //executor_ = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();

    // auto turtlesim_publisher_ = std::make_shared<TurtlesimPublisher>();
    // auto turtlesim_subscriber_ = std::make_shared<TurtlesimSubscriber>();

    // // executor_->add_node(turtlesim_publisher_);
    // // executor_->add_node(turtlesim_subscriber_);

    // // executor_->spin();
    RCLCPP_INFO(this->get_logger(), "Muti Thread Running!");
}

TurtlesimMultiThread::~TurtlesimMultiThread() {
    // Executor 종료
    // executor_->cancel();
    RCLCPP_INFO(this->get_logger(), "Muti Thread Exit!");
}
