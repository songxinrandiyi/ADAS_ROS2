#ifndef LIDAR_SENSOR_HANDLER_HPP_
#define LIDAR_SENSOR_HANDLER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_interfaces/msg/info_from_lidar.hpp"

class LidarSensorHandler : public rclcpp::Node
{
public:
  LidarSensorHandler();
  ~LidarSensorHandler();

private:
  void lidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
  sensor_interfaces::msg::InfoFromLidar processLidarData(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg);
  float calculateSpeedDeviation(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg);
  float calculateDistanceToFrontCar(const sensor_msgs::msg::LaserScan::SharedPtr lidar_msg);

  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
  rclcpp::Publisher<sensor_interfaces::msg::InfoFromLidar>::SharedPtr lidar_info_publisher_;
};

#endif  // LIDAR_SENSOR_HANDLER_HPP_
