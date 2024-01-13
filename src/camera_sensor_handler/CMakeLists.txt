cmake_minimum_required(VERSION 3.8)
project(camera_sensor_handler)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_interfaces REQUIRED)   

# Add the executable
add_executable(camera_node src/CameraHandler.cpp)
ament_target_dependencies(camera_node rclcpp sensor_msgs)

# Link against cv_bridge and any other dependencies
ament_target_dependencies(camera_node
  rclcpp
  cv_bridge
  OpenCV
  sensor_msgs  
  sensor_interfaces
)

# Install
install(TARGETS 
  camera_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()


