#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <thread>
#include <mutex>

std::mutex m;
cv::Mat image1; //shared resource

void callback(const sensor_msgs::ImageConstPtr& msg) 
{
    try
    {
        m.lock();
        image1 = cv_bridge::toCvCopy(msg,"bgr8")->image;
        //copy is necessary if you want to modify and then publish
        m.unlock();
        ROS_INFO("image recieved.");
        cv::imshow("view",image1);
        cv::waitKey(3);

    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}


void pubThread(ros::NodeHandle n)
{
        image_transport::ImageTransport it(n);
        image_transport::Publisher pub = it.advertise("imgTop2", 1);
    // cv::Mat image = cv::imread("/home/ac-optimus/Pictures/1.png", CV_LOAD_IMAGE_COLOR);
    // cv::waitKey(30);
        ros::Rate loop_rate(10);
        while (n.ok())
        {
        if (!image1.empty())
        {
            sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image1).toImageMsg();
            pub.publish(msg);
            ROS_INFO("image sent.");
        }
        else
        {
        ROS_INFO("the image was empty.");
        }
        //  ros::spinOnce();
        loop_rate.sleep();
        
    }
}


void subThread(ros::NodeHandle n)
{
    
    cv::namedWindow("view");
    cv::startWindowThread();//what is the role of thread here
    image_transport::ImageTransport it(n); 
    image_transport::Subscriber sub = it.subscribe("imgTop1", 1, callback);
    ros::spin();
    cv::destroyWindow("view");
    
}


   
int main(int argc, char** argv)
{
    ros::init(argc, argv, "subImgPub");
    ros::NodeHandle nl;
    std::thread subImg(subThread,nl);
    std::thread pubImg(pubThread, nl);
    if (pubImg.joinable())
    {
        pubImg.join();
    }
    if (subImg.joinable())
    {
        subImg.join();
    }
 }