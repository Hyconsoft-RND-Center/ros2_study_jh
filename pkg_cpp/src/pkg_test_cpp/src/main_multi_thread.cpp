#include "rclcpp/rclcpp.hpp"
#include "pkg_test_cpp/turtlesim_multi_thread.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    
    // TurtlesimMultiThread 노드 생성
    auto node = std::make_shared<pkg_test_cpp::TurtlesimMultiThread>();

    // Executor 실행
    node->executor_->spin();

    rclcpp::shutdown();
    return 0;
}
