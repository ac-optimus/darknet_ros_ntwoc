# darknet_ros
Robotics Operating System Package for Yolo v3 based on darknet.

## Abstract:
The repo provides two packages :

``` yoloDarknetRosNode``` : 
A ROS package for darknet Yolo v3 based on [AlexeyAB Darknet](https://github.com/AlexeyAB/darknet). The main node in the package named ```yoloBoundingBOxMessenger``` subscribes to a topic of ros_image and publishes object detected output on two different topics. Where it publishes modified object detected image on one topic while on the other it publishes the bounding box message, containing the object detected box details.  All the implementation are done using cpp multithreading. 

```video_stream_opencv ```: 
The package is taken [from](http://wiki.ros.org/video_stream_opencv). It publishes rosimage on ```/camera/raw_image``` topic, where frames are taken from the webcamera. 

### Usage : 
1. Make a new workspace or add the packages to your workspace's src directory.([create ros workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)).
2. run catkin_make at the location ~/yourWorkspace.
3. run ```rosrun yoloDarknetRosNode main``` to kick start the ```yoloBoundingBOxMessenger``` node.
4. run ```rosrun yoloDarknetRosNode sub``` to activate the ```subs``` node that will subscribe to the bounding box message.
4. to publish the image that can be accessed by the ```yoloBoundingBOxMessenger``` node run either of one : <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; a. run the test ```image_publisher``` node by : ```rosrun yoloDarknetRosNode ImgSub``` <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; b. run the other package provided by : ```roslaunch video_stream_opencv camera.launch``` <br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     to get the image feed from your webcam. For more detailed usage of video_stream_opencv package [look](http://wiki.ros.org/video_stream_opencv).
```
Note with method b change the topic in main.cpp file from "imgTop1" to "camera/raw_image".
```
![ezgif com-video-to-gif](https://user-images.githubusercontent.com/26172160/50568113-529e0a80-0d73-11e9-83e7-87d7279767d2.gif)

![ezgif com-crop](https://user-images.githubusercontent.com/26172160/50567917-aeb35f80-0d70-11e9-920d-339c6b81e6f8.gif)

## Results :
```
Each detection takes ~0.068-0.077s which makes peak fps to ~14 on nvidia GEFORCE 930M(2GB RAM), i5 6th gen cpu system with 8GB RAM.
```
### Requirement:  
* **Linux GCC>=4.9**
* **darknet**
* **ROS Kinetic**
* **CUDA 10.0**
* **2.x.x < OPENCV <= 3.4.0**.

Helpful Links - 
1. [AlexeyAB Darknet](https://github.com/AlexeyAB/darknet)
2. [Yolo v3 Paper](https://pjreddie.com/media/files/papers/YOLOv3.pdf)
3. [ROS](http://www.ros.org/)
