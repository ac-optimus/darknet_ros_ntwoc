#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <thread>
int l;
void callback(std_msgs::Int32 msg)
{
    l = msg.data;
    ROS_INFO("I recieved: [%i]", msg.data);
}

void puBlish(ros::NodeHandle n)
{
  ros::Publisher pub = n.advertise<std_msgs::Int32>("secondNUm", 1000);
    ros::Rate rate(10);
    
   while (ros::ok())
    {
        std_msgs::Int32 msg1;
        msg1.data = l;
        ROS_INFO("published %i", msg1.data);
        pub.publish(msg1);
        rate.sleep();
        
    }
}

void suBscr(ros::NodeHandle nl)
{
    ros::Subscriber sub = nl.subscribe("numberInterface",1000,callback);
    ros::spin();
}

int main(int argc, char** argv)
{
    //initialize the node
    ros::init(argc,argv,"subIntPub");
    //node handler to handle the node
    ros::NodeHandle nl;
    std::thread publ(puBlish,nl);
    std::thread subs(suBscr,nl);
    if (subs.joinable())
    {
        subs.join();
    }
    if (publ.joinable())
    {
        publ.join();

    }   
}


