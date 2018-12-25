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


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   BoundingBox.msg
   BoundingBoxArray.msg
  # msg1.msg
 )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations

set (MY_DIR 'darknet')
include_directories(
 
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${GSTREAMER_INCLUDE_DIRS}
)
# )

catkin_package(
  DEPENDS boot GSTREAMER
 #INCLUDE_DIRS include
#  LIBRARIES topicImgThreadcpp
  CATKIN_DEPENDS message_runtime roscpp std_msgs
#  DEPENDS system_lib
)

    
## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/topicImgThreadcpp.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/topicImgThreadcpp_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_topicImgThreadcpp.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)




message("${${PROJECT_NAME}_EXPORTED_TARGETS}: " ${catkin__EXPORTED_TARGETS})   #great usage function



add_executable(main  src/imageExample.cpp 
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
darknet/data.c                    darknet/network_kernels.cu          src/yolo_v2_class.cpp
darknet/data.h                    darknet/nightmare.c                 src/yolo_v2_class.hpp
)

target_link_libraries(main ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES} )
add_dependencies(main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})




if (FALSE)


add_executable(try src/customMsg.cpp )
target_link_libraries(try ${catkin_LIBRARIES}   ${OpenCV_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(try ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(sub src/customMsgSub.cpp )
target_link_libraries(sub ${catkin_LIBRARIES}   ${OpenCV_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(PubInt src/PubInt.cpp)
target_link_libraries(PubInt ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})



add_executable(SubInt src/SubInt.cpp)
target_link_libraries(SubInt ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(subIntPub src/SubIntPub.cpp)
target_link_libraries(subIntPub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(ImgPub src/ImgPub.cpp)
target_link_libraries(ImgPub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(ImgSub src/ImgSub.cpp)
target_link_libraries(ImgSub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(subImgPub src/SubImgPub.cpp)
target_link_libraries(subImgPub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


#add_executable(example src/imageExample.cpp)
#target_link_libraries(example ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


endif()