#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include "sensor_interfaces/msg/info_from_camera.hpp"     

class CameraHandler : public rclcpp::Node
{
public:
  CameraHandler()
    : Node("camera_handler_node")
  {
    subscription_ = create_subscription<sensor_msgs::msg::Image>(
      "/camera/image_raw", 10, std::bind(&CameraHandler::imageCallback, this, std::placeholders::_1));
  }

private:
  void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
    // Process the image data here
    // Access image properties using msg->width, msg->height, msg->encoding, etc.
  }

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CameraHandler>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
