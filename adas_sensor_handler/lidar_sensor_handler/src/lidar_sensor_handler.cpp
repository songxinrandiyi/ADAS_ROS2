#include "lidar_sensor_handler/lidar_sensor_handler.hpp"


LidarSensorHandler::LidarSensorHandler() : Node("lidar_sensor_handler")
{
  subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "/lidar/scan", 100, std::bind(&LidarSensorHandler::lidarCallback, this, std::placeholders::_1));

  lidar_info_publisher_ = this->create_publisher<sensor_interfaces::msg::InfoFromLidar>("/lidar/info", 100);
}

LidarSensorHandler::~LidarSensorHandler()
{
  // Destructor, if needed
}

void LidarSensorHandler::lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
  sensor_interfaces::msg::InfoFromLidar lidar_info_msg = processLidarData(msg);
  lidar_info_publisher_->publish(lidar_info_msg);
}

sensor_interfaces::msg::InfoFromLidar LidarSensorHandler::processLidarData(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg)
{
  sensor_interfaces::msg::InfoFromLidar lidar_info_msg;

  constexpr float car_detection_threshold = 0.5;
  bool car_detected = false;

  for (auto range : lidar_msg->ranges)
  {
    if (range < car_detection_threshold)
    {
      car_detected = true;
      break;
    }
  }

  lidar_info_msg.car_infront_detected = car_detected;

  if (car_detected)
  {
    lidar_info_msg.speed_deviation_car_infront = calculateSpeedDeviation(lidar_msg);
    lidar_info_msg.distance_car_infront = calculateDistanceToFrontCar(lidar_msg);
  }

  return lidar_info_msg;
}

float LidarSensorHandler::calculateSpeedDeviation(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg)
{
  // Replace this with your actual logic to calculate speed deviation
  // For simplicity, return a constant value
  return 2.0; // Placeholder value
}

float LidarSensorHandler::calculateDistanceToFrontCar(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg)
{
  // Replace this with your actual logic to calculate distance to the car in front
  // For simplicity, return a constant value
  return 3.0; // Placeholder value
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<LidarSensorHandler>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
