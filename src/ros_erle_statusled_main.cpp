#include "ros/ros.h"
#include "ros_erle_statusled/statusled.h"
#include "GPIO_BBB.h"

#define HIGH 1
#define LOW 0

#define HAL_GPIO_A_LED_PIN        61
#define HAL_GPIO_B_LED_PIN        48
#define HAL_GPIO_C_LED_PIN        117
#define HAL_GPIO_LED_ON           LOW
#define HAL_GPIO_OUTPUT 1
#define HAL_GPIO_LED_OFF          HIGH

GPIO_BBB pin;

void chatterCallback(const ros_erle_statusled::statusled::ConstPtr& msg)
{
  ROS_INFO("I heard: R:[%d], G[%d], B[%d]", msg->red, msg->green, msg->blue);
  pin.write(HAL_GPIO_A_LED_PIN, !msg->green);
  pin.write(HAL_GPIO_B_LED_PIN, !msg->blue);
  pin.write(HAL_GPIO_C_LED_PIN, !msg->red);
}

int main(int argc, char **argv)
{
  pin.init();
  pin.pinMode(HAL_GPIO_A_LED_PIN, HAL_GPIO_OUTPUT);
  pin.pinMode(HAL_GPIO_B_LED_PIN, HAL_GPIO_OUTPUT);
  pin.pinMode(HAL_GPIO_C_LED_PIN, HAL_GPIO_OUTPUT);

  ros::init(argc, argv, "statusled");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("statusled", 1000, chatterCallback);

  ros::spin();

  return 0;
}

