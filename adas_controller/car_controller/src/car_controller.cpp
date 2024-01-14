#include "car_controller/car_controller.hpp"

CarController::CarController()
  : Node("car_controller")
{
  subscription_driver_ = create_subscription<driver_interfaces::msg::InputFromDriver>(
    "/input_from_driver", 10, std::bind(&CarController::inputFromDriverCallback, this, std::placeholders::_1));

  subscription_camera_ = create_subscription<sensor_interfaces::msg::InfoFromCamera>(
    "/info_from_camera", 10, std::bind(&CarController::infoFromCameraCallback, this, std::placeholders::_1));

  subscription_lidar_ = create_subscription<sensor_interfaces::msg::InfoFromLidar>(
    "/info_from_lidar", 10, std::bind(&CarController::infoFromLidarCallback, this, std::placeholders::_1));

  control_output_publisher_ = create_publisher<output_interfaces::msg::ControlOutput>("/control_output", 10);

  // Initialize other variables and set up your controller logic
}

void CarController::inputFromDriverCallback(const driver_interfaces::msg::InputFromDriver::SharedPtr msg)
{
  // Process input from driver and implement control logic
  // For simplicity, let's assume maintaining speed and using a default steering angle
  float default_steering_angle = 0.0;
  float default_acceleration = 0.0;
  publishControlOutput(default_steering_angle, default_acceleration);
}

void CarController::infoFromCameraCallback(const sensor_interfaces::msg::InfoFromCamera::SharedPtr msg)
{
  // Process camera information and implement control logic
  // For simplicity, let's assume using a default steering angle
  float default_steering_angle = 0.0;
  float acceleration = msg->deviation_current_lane;  // Use camera information for acceleration
  publishControlOutput(default_steering_angle, acceleration);
}

void CarController::infoFromLidarCallback(const sensor_interfaces::msg::InfoFromLidar::SharedPtr msg)
{
  // Process Lidar information and implement control logic
  // For simplicity, let's assume using a default steering angle
  float default_steering_angle = 0.0;
  float acceleration = 0.0;  // Assume no acceleration change based on Lidar info
  publishControlOutput(default_steering_angle, acceleration);
}

void CarController::publishControlOutput(float steering_angle, float acceleration)
{
  auto control_output_msg = output_interfaces::msg::ControlOutput();
  control_output_msg.steering_angle = steering_angle;
  control_output_msg.acceleration = acceleration;
  control_output_publisher_->publish(control_output_msg);
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CarController>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

