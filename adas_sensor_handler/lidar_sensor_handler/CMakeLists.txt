cmake_minimum_required(VERSION 3.8)
project(lidar_sensor_handler)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(sensor_interfaces REQUIRED)   

include_directories(include)

# Add the executable
add_executable(lidar_sensor_handler src/lidar_sensor_handler.cpp)

# Link against cv_bridge and any other dependencies
ament_target_dependencies(lidar_sensor_handler
  rclcpp
  sensor_msgs  
  sensor_interfaces
)

# Install
install(TARGETS 
lidar_sensor_handler
  DESTINATION lib/${PROJECT_NAME})


ament_package()
