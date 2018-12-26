# Install script for directory: /home/ac-optimus/video/l/darknet_ros_ntwoc/src/topicImgThreadcpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ac-optimus/video/l/darknet_ros_ntwoc/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/topicImgThreadcpp/msg" TYPE FILE FILES
    "/home/ac-optimus/video/l/darknet_ros_ntwoc/src/topicImgThreadcpp/msg/BoundingBox.msg"
    "/home/ac-optimus/video/l/darknet_ros_ntwoc/src/topicImgThreadcpp/msg/BoundingBoxArray.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/topicImgThreadcpp/cmake" TYPE FILE FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/build/topicImgThreadcpp/catkin_generated/installspace/topicImgThreadcpp-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/devel/include/topicImgThreadcpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/devel/share/roseus/ros/topicImgThreadcpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/devel/share/common-lisp/ros/topicImgThreadcpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/devel/share/gennodejs/ros/topicImgThreadcpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/ac-optimus/video/l/darknet_ros_ntwoc/devel/lib/python2.7/dist-packages/topicImgThreadcpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/devel/lib/python2.7/dist-packages/topicImgThreadcpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/build/topicImgThreadcpp/catkin_generated/installspace/topicImgThreadcpp.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/topicImgThreadcpp/cmake" TYPE FILE FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/build/topicImgThreadcpp/catkin_generated/installspace/topicImgThreadcpp-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/topicImgThreadcpp/cmake" TYPE FILE FILES
    "/home/ac-optimus/video/l/darknet_ros_ntwoc/build/topicImgThreadcpp/catkin_generated/installspace/topicImgThreadcppConfig.cmake"
    "/home/ac-optimus/video/l/darknet_ros_ntwoc/build/topicImgThreadcpp/catkin_generated/installspace/topicImgThreadcppConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/topicImgThreadcpp" TYPE FILE FILES "/home/ac-optimus/video/l/darknet_ros_ntwoc/src/topicImgThreadcpp/package.xml")
endif()

