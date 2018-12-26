cmake_minimum_required(VERSION 2.8.3)
project(topicImgThreadcpp)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11 -pthread)

set(OPENCV 1)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  image_transport
  cv_bridge
  std_msgs
  sensor_msgs
  message_generation
)


find_package(Boost REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)

find_package(OpenCV)
add_message_files(
   FILES
   BoundingBox.msg
   BoundingBoxArray.msg
  # msg1.msg
 )
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

set (MY_DIR 'darknet')
include_directories(
 
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${GSTREAMER_INCLUDE_DIRS}
)

catkin_package(
  DEPENDS boot GSTREAMER
 #INCLUDE_DIRS include
#  LIBRARIES topicImgThreadcpp
  CATKIN_DEPENDS message_runtime roscpp std_msgs
#  DEPENDS system_lib
)

message("${${PROJECT_NAME}_EXPORTED_TARGETS}: " ${catkin__EXPORTED_TARGETS})   #great usage function

add_executable(main  src/main.cpp darknet/yolo_v2_class.hpp
darknet/activation_kernels.cu     darknet/deconvolutional_kernels.cu  darknet/normalization_layer.c
darknet/activation_layer.c        darknet/deconvolutional_layer.c     darknet/normalization_layer.h
darknet/activation_layer.h        darknet/deconvolutional_layer.h     darknet/option_list.c
darknet/activations.c             darknet/demo.c                      darknet/option_list.h
darknet/activations.h             darknet/demo.h                      darknet/parser.c
darknet/art.c                     darknet/detection_layer.c           darknet/parser.h
darknet/avgpool_layer.c           darknet/detection_layer.h           darknet/region_layer.c
darknet/avgpool_layer.h           darknet/detector.c                  darknet/region_layer.h
darknet/avgpool_layer_kernels.cu  darknet/dice.c                      darknet/reorg_layer.c
darknet/batchnorm_layer.c         darknet/dropout_layer.c             darknet/reorg_layer.h
darknet/batchnorm_layer.h         darknet/dropout_layer.h             darknet/reorg_old_layer.c
darknet/blas.c                    darknet/dropout_layer_kernels.cu    darknet/reorg_old_layer.h
darknet/blas.h                    darknet/gemm.c                      darknet/rnn.c
darknet/blas_kernels.cu           darknet/gemm.h                      darknet/rnn_layer.c
darknet/box.c                     darknet/getopt.c                    darknet/rnn_layer.h
darknet/box.h                     darknet/getopt.h                    darknet/rnn_vid.c
darknet/captcha.c                                                     darknet/route_layer.c
darknet/cifar.c                   darknet/gettimeofday.h              darknet/route_layer.h
darknet/classifier.c              darknet/go.c                        darknet/shortcut_layer.c
darknet/classifier.h              darknet/gru_layer.c                 darknet/shortcut_layer.h
darknet/coco.c                    darknet/gru_layer.h                 darknet/softmax_layer.c
darknet/col2im.c                  darknet/http_stream.cpp             darknet/softmax_layer.h
darknet/col2im.h                  darknet/http_stream.h               darknet/stb_image.h
darknet/col2im_kernels.cu         darknet/im2col.c                    darknet/stb_image_write.h
darknet/compare.c                 darknet/im2col.h                    darknet/super.c
darknet/connected_layer.c         darknet/im2col_kernels.cu           darknet/swag.c
darknet/connected_layer.h         darknet/image.c                     darknet/tag.c
darknet/convolutional_kernels.cu  darknet/image.h                     darknet/tree.c
darknet/convolutional_layer.c     darknet/layer.c                     darknet/tree.h
darknet/convolutional_layer.h     darknet/layer.h                     darknet/unistd.h
darknet/cost_layer.c              darknet/list.c                      darknet/upsample_layer.c
darknet/cost_layer.h              darknet/list.h                      darknet/upsample_layer.h
darknet/cpu_gemm.c                darknet/local_layer.c               darknet/utils.c
darknet/crnn_layer.c              darknet/local_layer.h               darknet/utils.h
darknet/crnn_layer.h              darknet/matrix.c                    darknet/voxel.c
darknet/crop_layer.c              darknet/matrix.h                    darknet/writing.c
darknet/crop_layer.h              darknet/maxpool_layer.c             darknet/yolo.c
darknet/crop_layer_kernels.cu     darknet/maxpool_layer.h             
darknet/cuda.c                    darknet/maxpool_layer_kernels.cu    darknet/yolo_layer.c
darknet/cuda.h                    darknet/network.c                   darknet/yolo_layer.h
                                  darknet/network.h                   
darknet/data.c                    darknet/network_kernels.cu          darknet/yolo_v2_class.cpp
darknet/data.h                    darknet/nightmare.c                 
)

target_link_libraries(main ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES} )
add_dependencies(main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ImgPub src/ImgPub.cpp)
target_link_libraries(ImgPub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(sub src/customMsgSub.cpp )
target_link_libraries(sub ${catkin_LIBRARIES}   ${OpenCV_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


if (FALSE)
add_executable(try src/testCodes/customMsg.cpp )
target_link_libraries(try ${catkin_LIBRARIES}   ${OpenCV_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(try ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


add_executable(PubInt src/testCodes/PubInt.cpp)
target_link_libraries(PubInt ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})



add_executable(SubInt src/testCodes/SubInt.cpp)
target_link_libraries(SubInt ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(subIntPub src/testCodes/SubIntPub.cpp)
target_link_libraries(subIntPub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(ImgSub src/testCodes/ImgSub.cpp)
target_link_libraries(ImgSub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(subImgPub src/testCodes/SubImgPub.cpp)
target_link_libraries(subImgPub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

endif()