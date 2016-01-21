# ros-erle-statusled
A ROS package to control [Erle-Brain 2](http://erlerobotics.com/blog/erle-brain-2/)'s status LEDs.

Quick setup:
```bash
# Within a catkin directory
cd src
git clone https://github.com/erlerobot/ros_erle_statusled
cd ..; catkin_make
source devel/setup.bash
rosrun ros_erle_statusled statusleds.py 
```

Test it by typing the following in a different terminal:
```bash
rostopic pub /statusleds std_msgs/String "blue"
```

Support forums and chats
------------------------

Please ask your questions not related to bugs/feauture requests on:
- [Erle Robotics Forum](http://forum.erlerobotics.com/)

Erle-Brain 1 support
-----
Refer to the branch https://github.com/erlerobot/ros_erle_statusled/tree/erle-brain1

Links
-----

  - [Erle Robotics](www.erlerobotics.com)
  - [Erle-Brain](https://erlerobotics.com/blog/product/erle-brain-v2/)
