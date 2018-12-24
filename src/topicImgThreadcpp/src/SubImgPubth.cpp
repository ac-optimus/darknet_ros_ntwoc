#include <ros/ros.h>
#include <image_transport/image_transport.h>
//#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <thread>
#include <mutex>
#include "topicImgThreadcpp/BoundingBox.h"

#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <queue>
#include <fstream>

#include <atomic>
              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <unistd.h>

#define MY_PATH "/home/ac-optimus/Pictures/try/darknet" //working directory

//opencv
#include <opencv2/opencv.hpp>            // C++
#include "opencv2/core/version.hpp"
#ifndef CV_VERSION_EPOCH
#include "opencv2/videoio/videoio.hpp"
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_MAJOR)"" CVAUX_STR(CV_VERSION_MINOR)"" CVAUX_STR(CV_VERSION_REVISION)
#pragma comment(lib, "opencv_world" OPENCV_VERSION ".lib")

#else
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_EPOCH)""CVAUX_STR(CV_VERSION_MAJOR)""CVAUX_STR(CV_VERSION_MINOR)
#pragma comment(lib, "opencv_core" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_imgproc" OPENCV_VERSION ".lib")
#pragma comment(lib, "opencv_highgui" OPENCV_VERSION ".lib")
#endif    // CV_VERSION_EPOCH


#include "yolo_v2_class.hpp"

void print_result(std::vector<bbox_t>result_vec)
{
    std::vector<bbox_t> l =result_vec;
    
    for (auto i=l.begin(); i != l.end(); ++i )
    std::cout << "result details" << " " <<(*i).obj_id << " " << (*i).x<< " " << (*i).y << " " << (*i).w << " " << (*i).h<< " " << std::endl; 

}

std::mutex lockImg;
std::mutex m1;//for bounding box
cv::Mat image1; //shared resource
topicImgThreadcpp::BoundingBox msgBox; //boundingBox

/*
cv::Mat accessImage(bool l,const sensor_msgs::ImageConstPtr& = NULL)
{
    //for subscriber assigns a new image
    //for yolo returns the image.
    std::lock_guard<std::mutex> lock(lockImg);
    if (l == 1)
    { // retri
    try
    {
            return( cv_bridge::toCvCopy(msg,"bgr8")->image);
    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }//not sure about the location of this try catch location

    }
    else // l==0
    {
        return image1;
    }


}//this method assures less lock is there for minimalist time possible.

void accessBoundingBox(bool flag,)
{
    std::lock_guard<std::mutex> lock(lockBox);   //will automatically get unlock when out of scope
    if (flag == 1) //assign the new coordinates
    {

    }

}
//need to look into it */

void darknetyolo(void) 
{
    //takes the image and assigns the bounding box.
  
    chdir(MY_PATH);   //change directory in this scope
    std::string  names_file = "data/coco.names";   //add the data file here
    std::string  cfg_file = "cfg/yolov3-tiny.cfg";  //configuration file
    std::string  weights_file = "yolov3-tiny.weights"; //weight files
    float const thresh = 0.20;

    auto obj_name = objects_names_from_file(names_file); //a vector of strings
    Detector detector(cfg_file, weights_file);

    std::lock_guard<std::mutex> lock(lockImg);
    cv::Mat img = image1.clone();//create a copy of the image to perfom object detection on it.
    //lock the bounding box before proceeding
    std::vector<bbox_t> msgBoxyolo = detector.detect(img);
    std::lock_guard<std::mutex> lock(lockBox);   //will automatically get unlock when out of scope
    msgBox.Class = msgBoxyolo.obj_id;                //either change the class data type to int or just let it be.
    msgBox.probability = msgBoxyolo.prob;//probability
    msgBox.xmin = msgBoxyolo.x ; //xmin
    msgBox.ymin = msgBoxyolo.y //ymin
    msgBox.xmax = msgBoxyolo.x + msgBoxyolo.w; //xmax
    msgBox.ymax = msgBoxyolo.y + msgBoxyolo.h; //ymax    //can put this into a
    print_result(msgBoxyolo);
    draw_boxes(img,msgBoxyolo,obj_name);
    cv::imshow("Output",img);
    cv::waitKey(3);  //3 inspired from the main code 
    ROS_INFO("tada!!");
}


void pubCordnts(ros::NodeHandle n)
{
    ros::Publisher pubBox = n.advertise<topicImgThreadcpp::BoundingBox>("BoxCord",1000);
    ros::Rate rate(10);
    while (n.ok())
    {
        std::lock_guard<std::mutex> lock(lockBox);
        pubBox.publish(msgBox);
        ROS_INFO("message sent...");
     //   m.unlock();
        rate.sleep();
    }
}


void callback(const sensor_msgs::ImageConstPtr& msg) 
{
    try
    {
        //m.lock();
        std::lock_guard<std::mutex> lock(lockImg);

        image1 = cv_bridge::toCvCopy(msg,"bgr8")->image;
        //copy is necessary if you want to modify and then publish
      //  m.unlock();
      
        ROS_INFO("image recieved.");
        cv::imshow("view",image1);
        cv::waitKey(3);

    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
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
  //  std::thread pubImg(pubThread, nl);  //additional thread
    std::thread yolo(darknetyolo);
    std::thread BoundBoxPub(pubCordnts,nl);
 /*   if (pubImg.joinable())
    {
        pubImg.join();
    }*/
    if (subImg.joinable())
    {
        subImg.join();
    }
    if (BoundBoxPub.joinable())
    {
        BoundBoxPub.join();
    }
    if (yolo.joinable())
    {
        yolo.join();
    }
 }