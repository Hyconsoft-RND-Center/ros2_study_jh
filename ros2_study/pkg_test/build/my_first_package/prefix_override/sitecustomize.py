import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hycon/workspace/ros2_study/pkg_test/install/my_first_package'
