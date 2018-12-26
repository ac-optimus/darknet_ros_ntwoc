//node subscribes an image from topic1 and then publishes the gray scale image on a topic2
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <thread>
#include <mutex>
#include <topicImgThreadcpp/BoundingBoxArray.h>
#include <topicImgThreadcpp/BoundingBox.h>
#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <atomic>
#include <condition_variable> // std::condition_variable
#include <unistd.h>

#define MY_PATH "/home/ac-optimus/Pictures/darknet" //location to darknet directory

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

std::mutex lockImg;
std::mutex lockImg2;
std::mutex lockBox;
cv::Mat image1; // = cv::imread("/home/ac-optimus/video/darknet_ros_ntwoc/src/topicImgThreadcpp/data/dog.jpg",CV_LOAD_IMAGE_COLOR); //shared resource
cv::Mat image2; //ouput image
topicImgThreadcpp::BoundingBoxArray msgBoxArr;



//bounding box is a shared resource.
topicImgThreadcpp::BoundingBoxArray  accessBox(bool flag, std::vector<bbox_t> box)
{
    std::lock_guard<std::mutex> lock(lockBox);   //will automatically get unlock when out of scope
    if (flag == 1) //to update with new data
    {
        topicImgThreadcpp::BoundingBoxArray BoxMsg;
        for (auto i=box.begin(); i!=box.end(); i++)
        {
            
            topicImgThreadcpp::BoundingBox msgBox;
            msgBox.Class = (*i).obj_id;                //either change the class data type to int or just let it be.
            msgBox.probability = (*i).prob;//probability
            msgBox.xmin = (*i).x ; //xmin
            msgBox.ymin = (*i).y; //ymin
            msgBox.xmax = (*i).x + (*i).w; //xmax
            msgBox.ymax = (*i).y + (*i).h; //ymax */   //can put this into a
            BoxMsg.message.push_back(msgBox);   
        }
        msgBoxArr = BoxMsg;
    }
    return msgBoxArr;
}


void print_result(std::vector<bbox_t>result_vec)
{
    std::vector<bbox_t> l =result_vec;
    
    for (auto i=l.begin(); i != l.end(); ++i )
    std::cout << "result details" << " " <<(*i).obj_id << " " << (*i).x<< " " << (*i).y << " " << (*i).w << " " << (*i).h<< " " << std::endl; 

}




//image is a shared resource
cv::Mat accessImg(int flag,const sensor_msgs::ImageConstPtr& msg) //passing pointer is a good idea
{
    std::lock_guard<std::mutex> lock(lockImg);
    //flag=1 for writing
    cv::Mat img;
    if(flag==1)
    {
        image1 = cv_bridge::toCvCopy(msg,"bgr8")->image;
        img = image1;
    }
    else if (flag == 0) //assign to image2
    {
        std::lock_guard<std::mutex> lock(lockImg2);
        img = image2;
    }
    else
    {
        img = image1;
    }
    return img;
}


cv::Mat darknetyolo(ros::NodeHandle n) 
{
   ros::Rate loop_rate(1);//1 publish per seconds
   while (n.ok())
   {
    const sensor_msgs::ImageConstPtr& msg =NULL;
    cv::Mat img = accessImg(9,msg);
    ROS_INFO("Was inside.");
    if (!img.empty())
    {    
        chdir(MY_PATH);   //change directory in this scope
        std::string  names_file = "data/coco.names";   //add the data file here
        std::string  cfg_file = "cfg/yolov3-tiny.cfg";  //configuration file
        std::string  weights_file = "yolov3-tiny.weights"; //weight files
        float const thresh = 0.20;

        auto obj_name = objects_names_from_file(names_file); //a vector of strings
        Detector detector(cfg_file, weights_file);

        std::vector<bbox_t> msgBoxyolo = detector.detect(img);
        accessBox(1,msgBoxyolo); // pass by reference
        ROS_INFO("coordinates added.");
    
        std::lock_guard<std::mutex> lock(lockImg2);
        image2 = img.clone();
        draw_boxes(image2,msgBoxyolo,obj_name);
       // cv::imshow("Output",image2);
       // cv::waitKey(30);  
        ROS_INFO("yolo at work!!");
    }
    else{
        ROS_INFO("The image was empty --yolo");
        loop_rate.sleep();
    }
    
   }
    
}

void pubBoundingBox(ros::NodeHandle n)
{
    ros::Publisher pub = n.advertise<topicImgThreadcpp::BoundingBoxArray>("msgTop",10);
    ros::Rate rate(1);
    while (n.ok())//see if node is live
    {
        std::vector<bbox_t> msg1;
        topicImgThreadcpp::BoundingBoxArray msg = accessBox(0,msg1);  //get the message
        pub.publish(msg);
        ROS_INFO("message sent.");
        rate.sleep();
    }
}


//publishing thread
void pubThread(ros::NodeHandle n)
{
        image_transport::ImageTransport it(n);
        image_transport::Publisher pub = it.advertise("imgTop2", 1);
        ros::Rate loop_rate(1);//1 publish per seconds
        while (n.ok())
        {
            //lock the resource before the usage
          //  std::lock_guard<std::mutex> lock(lockImg);//when lock is there this thread takes the ownership of the mutex object lockImg
            //lockImg.lock();
            const sensor_msgs::ImageConstPtr& msg =NULL;
            cv::Mat img = accessImg(0,msg);
            if (!img.empty())
            {    
               // image1 = greyIt(image1);
             
                sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", img).toImageMsg();
                
                pub.publish(msg);
                ROS_INFO("image sent.");
            }
            else
            {
            ROS_INFO("the image was empty.");
            }
            //  ros::spinOnce();
           // lockImg.unlock();
            loop_rate.sleep();
        
    }
}//lock automatically get released.

//callback
void callback(const sensor_msgs::ImageConstPtr& msg) 
{
    try
    {
      
        cv::Mat img = accessImg(1,msg);
        ROS_INFO("image recieved.");
        if (!img.empty())
        {
        
          //  cv::imshow("sub",img);
         //   cv::waitKey(30);
        }
    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}//lock automatically get released.


//subscribing thread
void subThread(ros::NodeHandle n)
{
    ROS_INFO("i was here man.");
    cv::namedWindow("sub");
    cv::startWindowThread();//what is the role of thread here
    image_transport::ImageTransport it(n); 
    
    image_transport::Subscriber sub = it.subscribe("imgTop1", 1, callback);
    ros::spin();
    cv::destroyWindow("sub");   
}

int main(int argc, char** argv)
{

    ros::init(argc, argv, "examples");
    ros::NodeHandle nl;
    std::thread subImg(subThread,nl);   
    std::thread pubImg(pubThread, nl);  //additional thread
    std::thread pubBox(pubBoundingBox,nl);
    std::thread yolo(darknetyolo,nl);
    if (pubBox.joinable())
    {
        pubBox.join();
    }
    if (yolo.joinable())
    {
        yolo.join();
    }
    if (pubImg.joinable())
    {
        pubImg.join();
    }
    if (subImg.joinable())
    {
        subImg.join();
    }
}