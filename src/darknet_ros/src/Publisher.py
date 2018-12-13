#!/usr/bin/env python
import rospy
from darknet_ros.msg import BoundingBox

def DarknetOutput():
    #sample helper function.
    message = BoundingBox()
    message.Class = "dog"
    message.probability = 83.3
    message.xmin = 0
    message.xmax = 10
    message.ymin = 0
    message.ymax = 10
    return message


def PubliSher():
    #intialize the node
    rospy.init_node("Sender",anonymous = True)

    #create the publisher
    pub = rospy.Publisher("CoOrdinates", BoundingBox)
    rate = rospy.Rate(10)#10 messages per second
    msg = DarknetOutput()#assigns the message to be sent
    
    while not rospy.is_shutdown():
        rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()


if __name__ == "__main__":
    try:
        PubliSher()
    except rospy.ROSInterruptException :
        pass