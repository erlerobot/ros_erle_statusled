#!/usr/bin/env python
import rospy
import RPi.GPIO as GPIO
from std_msgs.msg import String

def callback(data):
    if data.data == "orange":
	GPIO.output(24, False)
    elif data.data == "blue":
	GPIO.output(25, False)
    elif data.data == "orange_off":
        GPIO.output(24, True)
    elif data.data == "blue_off":
        GPIO.output(25, True)
    else:
    	rospy.loginfo(rospy.get_caller_id() + "Sorry, only 'blue' or 'orange' supported, switching off everything (I heard %s).", data.data)
	GPIO.output(24, True)
	GPIO.output(25, True)
    
def listener():
    # run simultaneously.
    rospy.init_node('erle_statusleds', anonymous=True)
    rospy.Subscriber("statusleds", String, callback)
    # Init corresponding GPIOs
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(24, GPIO.OUT) 
    GPIO.setup(25, GPIO.OUT) 
    # Init them
    GPIO.output(24, True)
    GPIO.output(25, True)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
