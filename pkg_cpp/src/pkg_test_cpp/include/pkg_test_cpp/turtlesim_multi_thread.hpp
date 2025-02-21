#ifndef TURTLESIM_MULTI_THREADED_HPP
#define TURTLESIM_MULTI_THREADED_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors/multi_threaded_executor.hpp"
#include "pkg_test_cpp/turtlesim_publisher.hpp"
#include "pkg_test_cpp/turtlesim_subscriber.hpp"

namespace pkg_test_cpp {

class TurtlesimMultiThread : public rclcpp::Node {
    public:
        TurtlesimMultiThread();
        ~TurtlesimMultiThread();

        // Executor를 public으로 설정
        std::shared_ptr<rclcpp::executors::MultiThreadedExecutor> executor_;

    private:
        std::shared_ptr<TurtlesimPublisher> publisher_;
        std::shared_ptr<TurtlesimSubscriber> subscriber_;
};

} // namespace pkg_test_cpp

#endif // TURTLESIM_MULTI_THREADED_HPP
