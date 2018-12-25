#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_msgs/String.h>

#include <topicImgThreadcpp/BoundingBoxArray.h>
#include <topicImgThreadcpp/BoundingBox.h>



int main(int argc, char** argv)
{
    //initialize the node
    ros::init(argc,argv,"MSG");
    ros::NodeHandle nl;
    ros::Publisher pub = nl.advertise<topicImgThreadcpp::BoundingBoxArray>("numberInterface",1000);
    ros::Rate rate(10);  //rate is object of class ROS.
    
    while (ros::ok())
    {
        topicImgThreadcpp::BoundingBox data ;
        data.Class = 0; //for person
        data.probability = 98.8;
        data.xmin = 1;
        data.ymin = 1;
        data.xmin = 10;
        data.ymax = 10;
        topicImgThreadcpp::BoundingBoxArray msg;
        msg.message.push_back(data);
        data.Class = 1; 
        data.probability = 94.8;
        data.xmin = 2;
        data.ymin = 2;
        data.xmin = 13;
        data.ymax = 14;
        msg.message.push_back(data);
       // std_msgs::Int32 msg;

        //msg.data = o;
       // ROS_INFO("%i", msg.data);
        
        pub.publish(msg);
        rate.sleep();
    }
}