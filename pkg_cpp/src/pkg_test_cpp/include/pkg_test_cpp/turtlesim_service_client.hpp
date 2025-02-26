#include "rclcpp/rclcpp.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"

class TurtlesimClinetService : public rclcpp::Node {
    public:
        TurtlesimClinetService();
    private:
        void send_service_request();
        rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr service_client_;
};