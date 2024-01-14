cmake_minimum_required(VERSION 3.8)
project(car_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(output_interfaces REQUIRED)
find_package(sensor_interfaces REQUIRED)
find_package(driver_interfaces REQUIRED)

include_directories(include)

add_executable(car_controller
  src/car_controller.cpp
)

ament_target_dependencies(car_controller
  rclcpp
  output_interfaces
  sensor_interfaces
  driver_interfaces
)

install(TARGETS car_controller
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
