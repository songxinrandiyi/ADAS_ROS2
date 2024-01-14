#ifndef CAR_CONTROLLER__CAR_CONTROLLER_HPP_
#define CAR_CONTROLLER__CAR_CONTROLLER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "output_interfaces/msg/control_output.hpp"
#include "sensor_interfaces/msg/info_from_camera.hpp"
#include "sensor_interfaces/msg/info_from_lidar.hpp"
#include "driver_interfaces/msg/input_from_driver.hpp"

class CarController : public rclcpp::Node
{
public:
  CarController();

private:
  void inputFromDriverCallback(const driver_interfaces::msg::InputFromDriver::SharedPtr msg);
  void infoFromCameraCallback(const sensor_interfaces::msg::InfoFromCamera::SharedPtr msg);
  void infoFromLidarCallback(const sensor_interfaces::msg::InfoFromLidar::SharedPtr msg);
  void publishControlOutput(float steering_angle, float acceleration);

  rclcpp::Subscription<driver_interfaces::msg::InputFromDriver>::SharedPtr subscription_driver_;
  rclcpp::Subscription<sensor_interfaces::msg::InfoFromCamera>::SharedPtr subscription_camera_;
  rclcpp::Subscription<sensor_interfaces::msg::InfoFromLidar>::SharedPtr subscription_lidar_;
  rclcpp::Publisher<output_interfaces::msg::ControlOutput>::SharedPtr control_output_publisher_;

  // Add more member variables and methods as needed
};

#endif  // CAR_CONTROLLER__CAR_CONTROLLER_HPP_
