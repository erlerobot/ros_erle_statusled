cmake_minimum_required(VERSION 2.8.3)
project(ros_erle_statusled)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs genmsg)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS std_msgs)

catkin_install_python(PROGRAMS
  scripts/statusleds.py
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/scripts
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}/scripts
)

