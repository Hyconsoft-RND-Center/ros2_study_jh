import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hycon/workspace/hycon_git/ros2_study_jh/install/my_first_package'
