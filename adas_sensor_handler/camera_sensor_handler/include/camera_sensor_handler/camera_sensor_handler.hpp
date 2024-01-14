#ifndef CAMERA_HANDLER_HPP_
#define CAMERA_HANDLER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.hpp"
#include "sensor_interfaces/msg/info_from_camera.hpp"

class CameraSensorHandler : public rclcpp::Node
{
public:
  CameraSensorHandler();

private:
  void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
  sensor_interfaces::msg::InfoFromCamera processImage(const sensor_msgs::msg::Image::SharedPtr raw_image_msg);

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
  rclcpp::Publisher<sensor_interfaces::msg::InfoFromCamera>::SharedPtr publisher_;
};

#endif  // CAMERA_HANDLER_HPP_
