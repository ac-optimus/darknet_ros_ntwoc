#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_msgs/String.h>

#include <yoloDarknetRosNode/BoundingBoxArray.h>
#include <yoloDarknetRosNode/BoundingBox.h>




void callback(const yoloDarknetRosNode::BoundingBoxArray::ConstPtr& msg) //why const here and a refference pass
{
    try
    {
        for (int i=0; i< msg->message.size(); i++)
        {
            const yoloDarknetRosNode::BoundingBox &data = msg->message[i];
            ROS_INFO_STREAM("Class: " << data.Class << " | Probability: " << data.probability <<  " | xmin: "<<  data.xmin << "| ymin: " <<  data.ymin << " | xmax:" <<  data.xmax << " | ymax: "<< data.ymax );
        }
        ROS_INFO("message recieved.");
    
    }
    catch (...)
    {
         ROS_ERROR("some error.");
    }

}


int main(int argc, char** argv)
{
    ros::init(argc,argv,"subs");
    ros::NodeHandle nl;
    ros::Subscriber sub = nl.subscribe("msgTop", 1, callback);
    ros::spin();    
}