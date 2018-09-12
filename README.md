# darknet_ros
Robotics Operating System Package for Yolo v3 based on darknet with optimized tracking using Kalman Filter and Optical Flow.

## Abstract:
To develop a ROS package for darknet Yolo v3 based on [AlexeyAB Darknet](https://github.com/AlexeyAB/darknet) and implement optimized object tracking using Kalman Filter and Optical Flow.

### Sub-Projects -
#### Robotics Operating System
* Structuring Publishers and Subscribers for ROS.
* Creating custom messages based on Bounding Box output by Yolo v3.

#### C++ Multithreading Implementation
* Fetch Thread - Subscribe to Image ROS Topic and get the image in OpenCV Format.
* Detect Thread - Create Yolo Object Detector based on [AlexeyAB Darknet](https://github.com/AlexeyAB/darknet).  
* Publish Thread - Publish the output from Yolo Object Detector as a ROSTopic of BoundingBoxes

#### Tracking Optimization
* Kalman Filter Implementation - To predict and smooth out bounding box outputs.
* Optical Flow Implementation - To improve object detection and tracking.

#### Documentation
* Develop user-based tutorials for the package.
* Publicise ROS pacakge on ROS Discourse.
* Develop demo examples demonstrating object detections.

#### Future Developments 
* Multiple ROS Image topic support (i.e Multiple Camera Support)
* 

Prerequisites : C++ Programming Skills, Robotics Operating System, Multithreading-Mutex Concepts, CMake.
Helpful Links - 
1. [AlexeyAB Darknet](https://github.com/AlexeyAB/darknet)
2. [Yolo v3 Paper](https://pjreddie.com/media/files/papers/YOLOv3.pdf)
3. [Kalman Filter OpenCV](https://docs.opencv.org/3.4.1/dd/d6a/classcv_1_1KalmanFilter.html)
4. [Optical Flow OpenCV](https://docs.opencv.org/3.4/d7/d8b/tutorial_py_lucas_kanade.html)

Selection Procedure:(Complete one of the following tasks to work on the project.)
1. Develop an object-oriented C++ application using mutex concepts.
2. Develop a custom message example publisher and subscriber for ROS.
3. Setup darknet and run object detection example on video feed.
