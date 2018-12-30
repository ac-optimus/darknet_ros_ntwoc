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
#include <semaphore.h>
#include <ctime>
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

#define SIZE_IMG 400
#define SIZE_YOLO 20
#define SIZE_YOLOimg 20

cv::Mat buffImg[SIZE_IMG];
sem_t lockImg,forSub,forPub;
int ret = sem_init(&lockImg,0,1);
int ret1 = sem_init(&forSub,0,0);
int ret2 = sem_init(&forPub, 0, SIZE_IMG);
int in=0, out = 0; 

topicImgThreadcpp::BoundingBoxArray  buffmsg[SIZE_YOLO];
sem_t lockMsg, Foryolo, ForPub;
int re = sem_init(&lockMsg,0,1);
int re1 = sem_init(&Foryolo,0,SIZE_YOLO);
int re2 = sem_init(&ForPub,0,0);
int In=0, Out=0;

cv::Mat buffImgyolo[SIZE_YOLOimg];
sem_t yoloUp, Pubyolo, lockImgyolo;
int r = sem_init(&yoloUp,0,SIZE_YOLOimg);
int r1 = sem_init(&Pubyolo,0,0);
int r2 = sem_init(&lockImgyolo,0,1);
int i=0, o=0;


//bounding box is a shared resource.
topicImgThreadcpp::BoundingBoxArray  accessBox( std::vector<bbox_t> box)
{
        topicImgThreadcpp::BoundingBoxArray BoxMsg;
        for (auto i=box.begin(); i!=box.end(); i++)
        {
            topicImgThreadcpp::BoundingBox msgBox;
            msgBox.Class = (*i).obj_id;     //0 if for person
            msgBox.probability = (*i).prob;//probability
            msgBox.xmin = (*i).x ; //xmin
            msgBox.ymin = (*i).y; //ymin
            msgBox.xmax = (*i).x + (*i).w; //xmax
            msgBox.ymax = (*i).y + (*i).h; //ymax 
            BoxMsg.message.push_back(msgBox);   
        }
        return BoxMsg;   
}

cv::Mat darknetyolo(ros::NodeHandle n) 
{
   ros::Rate loop_rate(10);//10 publish per seconds
   chdir(MY_PATH);   //change directory in this scope
   std::string  names_file = "data/coco.names";    //data file 
   std::string  cfg_file = "cfg/yolov3-tiny.cfg";  //configuration file
   std::string  weights_file = "yolov3-tiny.weights"; //weight files
   float const thresh = 0.20;
   auto obj_name = objects_names_from_file(names_file); //a vector of strings
   Detector detector(cfg_file, weights_file);
   while (n.ok())
   {
    sem_wait(&forSub);
    sem_wait(&lockImg);
  //  ROS_INFO("The value of out for darknet was: [%d]",out);
    cv::Mat img = buffImg[out];
    out = (out+1)%SIZE_IMG;
    sem_post(&lockImg);
    sem_post(&forPub);
    ROS_INFO("image accessed from the buffer, FIFO.");

    if (!img.empty())
    {    
       // int start = clock();
        std::vector<bbox_t> msgBoxyolo = detector.detect(img);
       // int req = clock() - start;
        //ROS_INFO("THE TIME TAKEN WAS: %f",(float)req/CLOCKS_PER_SEC);
        sem_wait(&Foryolo);
        sem_wait(&lockMsg);
        buffmsg[In] = accessBox(msgBoxyolo);
        In = (In+1) % SIZE_YOLO;
        sem_post(&lockMsg);
        sem_post(&ForPub);
        ROS_INFO("box added to message buffer.");
    
        draw_boxes(img,msgBoxyolo,obj_name);

        sem_wait(&yoloUp);
        sem_wait(&lockImgyolo);
        buffImgyolo[i] = img;
        i = (i+1) %  SIZE_YOLOimg;
        sem_post(&lockImgyolo);
        sem_post(&Pubyolo); 
        ROS_INFO("modified image added to another buffer.");
    }
    else{
        ROS_INFO("The image was empty --yolo");
        loop_rate.sleep();
    }
    
   }
    
}

//bounding box message publisher
void pubBoundingBox(ros::NodeHandle n)
{
    ros::Publisher pub = n.advertise<topicImgThreadcpp::BoundingBoxArray>("msgTop",10);
    ros::Rate rate(1);
    while (n.ok())//see if node is live
    {
        
        sem_wait(&ForPub);
        sem_wait(&lockMsg);
        topicImgThreadcpp::BoundingBoxArray msg =  buffmsg[Out];  //get the message
        Out = (Out+1) % SIZE_YOLO;
        sem_post(&lockMsg);
        sem_post(&Foryolo);

        pub.publish(msg);
        ROS_INFO("Bounding box message sent.");
        rate.sleep();
    }
}


//modified publishing image thread
void pubThread(ros::NodeHandle n)
{
        image_transport::ImageTransport it(n);
        image_transport::Publisher pub = it.advertise("imgTop2", 1);
        ros::Rate loop_rate(10);//a max 10 publish per seconds
        while (n.ok())
        {
            cv::Mat img ;
            sem_wait(&Pubyolo);
            sem_wait(&lockImgyolo);
            img = buffImgyolo[o];
            o = (o+1) %  SIZE_YOLOimg;
            sem_post(&lockImgyolo);
            sem_post(&yoloUp);

            ROS_INFO("modified image accessed from the buffer.");

            if (!img.empty())
            {    
                sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", img).toImageMsg();
                
                pub.publish(msg);
                ROS_INFO("modified image sent.");
            }
            else
            {
            ROS_INFO("the image was empty.");
            }
            loop_rate.sleep();
        
    }
}

//callback
void callback(const sensor_msgs::ImageConstPtr& msg) 
{
    try
    {
        sem_wait(&forPub);
        sem_wait(&lockImg);
      //  ROS_INFO("The value for subscriber was: [%d]",in);
        buffImg[in] = cv_bridge::toCvCopy(msg,"bgr8")->image;
        in = (in+1) % SIZE_IMG;
        ROS_INFO("image recieved by the node.");
        sem_post(&lockImg);
        sem_post(&forSub);

    }
    catch (cv_bridge::Exception& e)
    {
         ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}


//image subscribing thread
void subThread(ros::NodeHandle n)
{
   
    cv::namedWindow("sub");
    cv::startWindowThread();
    image_transport::ImageTransport it(n); 
    image_transport::Subscriber sub = it.subscribe("imgTop1", 1, callback);
    ros::spin();
    cv::destroyWindow("sub");   
}

int main(int argc, char** argv)
{

    ros::init(argc, argv, "yoloBoundingBOxMessenger");
    ros::NodeHandle nl;
    std::thread subImg(subThread,nl);   
    std::thread pubImg(pubThread, nl);  //additional thread to publish the new modified image.
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