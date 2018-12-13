#!/usr/bin/env python
import rospy
from darknet_ros.msg import BoundingBox

def callback(data):
    rospy.loginfo((data.Class,data.probability,data.xmin,data.ymin,data.xmax,data.ymax))


def SubsCriber()
    #initialize the node
    rospy.init_node("Reciever",anonymous = True)
    rospy.Subscriber("CoOrdinates", BoundingBox,callback)
    rospy.spin()


if __name__ =="__main__":
    SubsCriber()
