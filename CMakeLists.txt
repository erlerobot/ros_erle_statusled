cmake_minimum_required(VERSION 2.8.3)
project(ros_erle_statusled)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs genmsg)

## Declare ROS messages and services
add_message_files(DIRECTORY msg FILES statusled.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(ros_erle_statusled_client src/ros_erle_statusled_client.cpp)
target_link_libraries(ros_erle_statusled_client ${catkin_LIBRARIES})
add_dependencies(ros_erle_statusled_client ros_erle_statusled_generate_messages_cpp)

add_executable(ros_erle_statusled_server src/ros_erle_statusled_server.cpp src/GPIO_BBB.cpp)
target_link_libraries(ros_erle_statusled_server ${catkin_LIBRARIES})
add_dependencies(ros_erle_statusled_server ros_erle_statusled_generate_messages_cpp)
