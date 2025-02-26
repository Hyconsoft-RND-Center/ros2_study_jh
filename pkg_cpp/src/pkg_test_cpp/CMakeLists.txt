cmake_minimum_required(VERSION 3.8)
project(pkg_test_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pkg_test_cpp_msg REQUIRED)
find_package(rcl_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(include)

add_executable(turtlesim_subscriber src/main_subscriber.cpp src/turtlesim_subscriber.cpp)
ament_target_dependencies(turtlesim_subscriber rclcpp turtlesim)

add_executable(turtlesim_publisher src/main_publisher.cpp src/turtlesim_publisher.cpp)
ament_target_dependencies(turtlesim_publisher rclcpp geometry_msgs)

add_executable(turtlesim_cmd_and_pose src/main_cmd_and_pose.cpp src/turtlesim_cmd_and_pose.cpp)
ament_target_dependencies(turtlesim_cmd_and_pose rclcpp turtlesim geometry_msgs pkg_test_cpp_msg)

add_executable(turtlesim_service_server src/main_service_server.cpp src/turtlesim_service_server.cpp)
ament_target_dependencies(turtlesim_service_server rclcpp pkg_test_cpp_msg turtlesim)

add_executable(turtlesim_action_server src/main_action_server.cpp src/turtlesim_action_server.cpp src/turtle_subscriber.cpp src/turtlesim_subaction.cpp)
ament_target_dependencies(turtlesim_action_server rcl_interfaces rclcpp pkg_test_cpp_msg rclcpp_action geometry_msgs turtlesim)

add_executable(turtlesim_multi_thread src/main_multi_thread.cpp src/turtlesim_multi_thread.cpp src/turtlesim_publisher.cpp src/turtlesim_subscriber.cpp)
ament_target_dependencies(turtlesim_multi_thread rclcpp pkg_test_cpp_msg geometry_msgs turtlesim)

add_executable(turtlesim_service_client src/turtlesim_service_client.cpp src/main_service_client.cpp)
ament_target_dependencies(turtlesim_service_client rclcpp turtlesim)

install(
  TARGETS turtlesim_multi_thread
  turtlesim_subscriber 
  turtlesim_publisher 
  turtlesim_cmd_and_pose 
  turtlesim_service_server 
  turtlesim_action_server 
  turtlesim_service_client
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
