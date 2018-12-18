#include <ros/ros.h>
#include <std_msgs/Int32.h>

//publisher a integer

int main(int argc, char** argv)
{
    //initialize the node
    ros::init(argc,argv,"numPub");
    ros::NodeHandle nl;
    ros::Publisher pub = nl.advertise<std_msgs::Int32>("numberInterface",1000);
    ros::Rate rate(10);  //rate is object of class ROS.
    int o=0;
    while (ros::ok())
    {
        std_msgs::Int32 msg;

        msg.data = o;
        ROS_INFO("%i", msg.data);
        o = o+1;
        pub.publish(msg);
        rate.sleep();
    }
    
}