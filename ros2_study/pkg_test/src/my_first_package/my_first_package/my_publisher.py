import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist

class TurtsimPublisher(Node):

    def __init__(self):
        super().__init__('turtlesim_publisher')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = Twist()
        msg.linear.x = 2.0
        msg.angular.z = 2.0
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    turtlsim_publisher = TurtsimPublisher()
    rclpy.spin(turtlsim_publisher)

    turtlsim_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()