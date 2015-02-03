#include "ros/ros.h"
#include "ros_erle_statusled/statusled.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_erle_statusled_client");
  if (argc != 3){
    ROS_INFO("usage: ros_erle_statusled_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::Publisher led_pub = n.advertise<ros_erle_statusled::statusled>("statusled", 1000);
  ros_erle_statusled::statusled msg;

  msg.blue = false;
  msg.red = true;
  msg.green = true;

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok()){

    led_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }  
  return 0;
}
