#!/usr/bin/python
import rospy
import sys
from ros_erle_statusled.msg import *

red = 0
blue = 0

def talker():
    pub = rospy.Publisher("statusled", statusled, queue_size=10)
    rospy.init_node("statusled", anonymous=True)
    msg = statusled()
    msg.blue = blue
    msg.red = red
    msg.green = True
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()

def usage():
    return "%s [red blue]"%sys.argv[0]

if __name__ == "__main__":

    if len(sys.argv) == 3:
        red = int(sys.argv[1])
        blue = int(sys.argv[2])
    else:
        print usage()
        sys.exit(1)
    talker();
