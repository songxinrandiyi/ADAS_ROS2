#include "camera_sensor_handler/camera_sensor_handler.hpp"

CameraSensorHandler::CameraSensorHandler()
  : Node("camera_handler_node")
{
  subscription_ = create_subscription<sensor_msgs::msg::Image>(
    "/camera/image_raw", 100, std::bind(&CameraSensorHandler::imageCallback, this, std::placeholders::_1));
  publisher_ = this->create_publisher<sensor_interfaces::msg::InfoFromCamera>("/info_from_image", 100);
}

void CameraSensorHandler::imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
{
  // Process the image data 
  auto processed_data = processImage(msg);

  // Publish the processed data
  publisher_->publish(processed_data);
}

sensor_interfaces::msg::InfoFromCamera CameraSensorHandler::processImage(const sensor_msgs::msg::Image::SharedPtr raw_image_msg)
{
  // TODO: Replace this with your actual image processing logic
  sensor_interfaces::msg::InfoFromCamera processed_data;
  processed_data.deviation_current_lane = 0;
  processed_data.deviation_left_lane = 5.0;
  processed_data.deviation_right_lane = 5.0;

  return processed_data;
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CameraSensorHandler>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

