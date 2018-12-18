#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>


void callback(const sensor_msgs::ImageConstPtr& msg) //why const here and a refference pass
{
    try
    {
        cv::imshow("ImageRecieved",cv_bridge::toCvShare(msg,"bgr8")->image);
        cv::waitKey(30);
        ROS_INFO("image recieved.");
        
    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }

}

int main(int argc, char** argv)
{
    //intilize and name the node
    ros::init(argc,argv,"image_subscriber");
    ros::NodeHandle nh;
    
    cv::startWindowThread();//what is the role of thread here
    image_transport::ImageTransport it(nh); //didnt go a bit of it
    image_transport::Subscriber sub = it.subscribe("imgTop2", 1, callback);
    ros::spin();
    cv::destroyWindow("view");
    
}