#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>


std::vector<std::string> ImgLst()
{
  chdir(DARKNET_PATH); 
  std::vector<std::string> list ;
  std::ifstream file;
  std::string line;
  
  file.open("../data/input.txt");
  while (file)
  {
    std::getline(file,line);
//    ROS_INFO("adding: [%s]",line.data.c_str());
    std::cout << "adding: "<<line<<std::endl;
    list.push_back(line);
  }
  file.close();
  return list;
}
   
int main(int argc, char** argv)
{
    std::cout << std::system("ls") << std::endl;
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);


    std::vector<std::string> inputImgs = ImgLst();

      std::cout << "accessing images from file: "<<"../data/input/txt"<<std::endl;
    
    for (auto i=inputImgs.begin(); i != inputImgs.end(); ++i )
    {
      
//        ROS_INFO("sending: [%s] ",(*i).data.c_str()); 
        std::cout << "sending: "<<*i << std::endl;      



        image_transport::Publisher pub = it.advertise("imgTop1", 1);
        cv::Mat image = cv::imread((*i), CV_LOAD_IMAGE_COLOR);
        cv::waitKey(30);
        sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
        int count = 0;
        ros::Rate loop_rate(1);
        while (nh.ok())
        {
          pub.publish(msg);
          ROS_INFO("image sent.");
        if (count > 50 )
        {
          break;
        }
        count+=1;
        //  ros::spinOnce();
          loop_rate.sleep();
        }
        //ros::spin();
        //not needed in publisher, it is used in subscriber as it simply reruns the callback function
    }
    
 }