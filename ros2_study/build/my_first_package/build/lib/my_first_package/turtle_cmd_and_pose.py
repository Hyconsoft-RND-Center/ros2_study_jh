import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose

class CmdAndPose(Node):

    def __init__(self):
        super().__init__('turtle_cmd_pose')
        self.sub_pose = self.create_subscription(Pose, '/turtle1/pse', self.callback_pose, 10)

    def callback_pose(self, msg):
        print(msg)

def main(args=None):
    rclpy.init(args=args)

    turtle_cmd_pose_node = CmdAndPose()
    rclpy.spin(turtle_cmd_pose_node)

    turtle_cmd_pose_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()