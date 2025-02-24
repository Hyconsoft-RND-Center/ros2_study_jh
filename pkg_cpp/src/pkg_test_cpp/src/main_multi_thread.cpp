#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors/multi_threaded_executor.hpp"

#include "pkg_test_cpp/turtlesim_multi_thread.hpp"
#include "pkg_test_cpp/turtlesim_publisher.hpp"
#include "pkg_test_cpp/turtlesim_subscriber.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    
    // TurtlesimMultiThread 노드 생성
    auto multi_node_ = std::make_shared<TurtlesimMultiThread>();
    auto publish_node_ = std::make_shared<TurtlesimPublisher>();
    auto subscribe_node_ = std::make_shared<TurtlesimSubscriber>();

    auto executor_ = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
    
    executor_->add_node(multi_node_);
    executor_->add_node(publish_node_);
    executor_->add_node(subscribe_node_);
    executor_->spin();

    rclcpp::shutdown();

    return 0;
}
