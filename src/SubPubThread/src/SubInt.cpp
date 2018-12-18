#include <ros/ros.h>
#include <std_msgs/Int32.h>

void callback(std_msgs::Int32 msg)
{
  //  int l = msg.data+2;
    ROS_INFO("I heard: [%i]", msg.data);

}

int main(int argc, char** argv)
{
    //initialize the node
    ros::init(argc,argv,"subInt");
    //node handler to handle the node
    ros::NodeHandle nl;
    ros::Subscriber sub = nl.subscribe("secondNUm",1000,callback);
    
    ros::spin();

}