#ifndef TURTLESIM_MULTI_THREADED_HPP
#define TURTLESIM_MULTI_THREADED_HPP

#include "rclcpp/rclcpp.hpp"
// #include "rclcpp/executors/multi_threaded_executor.hpp"

// // #include "pkg_test_cpp/turtlesim_publisher.hpp"
// // #include "pkg_test_cpp/turtlesim_subscriber.hpp"

class TurtlesimMultiThread : public rclcpp::Node {
    public:
        TurtlesimMultiThread();
        ~TurtlesimMultiThread();

        //std::shared_ptr<rclcpp::executors::MultiThreadedExecutor> executor_;

    private:       
        // std::shared_ptr<TurtlesimPublisher> turtle_publisher_;
        // std::shared_ptr<TurtlesimSubscriber> turtle_subscriber_;
};

#endif // TURTLESIM_MULTI_THREADED_HPP
