# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "pythonSubPub: 1 messages, 0 services")

set(MSG_I_FLAGS "-IpythonSubPub:/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(pythonSubPub_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" NAME_WE)
add_custom_target(_pythonSubPub_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pythonSubPub" "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(pythonSubPub
  "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pythonSubPub
)

### Generating Services

### Generating Module File
_generate_module_cpp(pythonSubPub
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pythonSubPub
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(pythonSubPub_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(pythonSubPub_generate_messages pythonSubPub_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" NAME_WE)
add_dependencies(pythonSubPub_generate_messages_cpp _pythonSubPub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pythonSubPub_gencpp)
add_dependencies(pythonSubPub_gencpp pythonSubPub_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pythonSubPub_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(pythonSubPub
  "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pythonSubPub
)

### Generating Services

### Generating Module File
_generate_module_eus(pythonSubPub
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pythonSubPub
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(pythonSubPub_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(pythonSubPub_generate_messages pythonSubPub_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" NAME_WE)
add_dependencies(pythonSubPub_generate_messages_eus _pythonSubPub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pythonSubPub_geneus)
add_dependencies(pythonSubPub_geneus pythonSubPub_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pythonSubPub_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(pythonSubPub
  "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pythonSubPub
)

### Generating Services

### Generating Module File
_generate_module_lisp(pythonSubPub
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pythonSubPub
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(pythonSubPub_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(pythonSubPub_generate_messages pythonSubPub_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" NAME_WE)
add_dependencies(pythonSubPub_generate_messages_lisp _pythonSubPub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pythonSubPub_genlisp)
add_dependencies(pythonSubPub_genlisp pythonSubPub_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pythonSubPub_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(pythonSubPub
  "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pythonSubPub
)

### Generating Services

### Generating Module File
_generate_module_nodejs(pythonSubPub
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pythonSubPub
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(pythonSubPub_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(pythonSubPub_generate_messages pythonSubPub_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" NAME_WE)
add_dependencies(pythonSubPub_generate_messages_nodejs _pythonSubPub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pythonSubPub_gennodejs)
add_dependencies(pythonSubPub_gennodejs pythonSubPub_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pythonSubPub_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(pythonSubPub
  "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pythonSubPub
)

### Generating Services

### Generating Module File
_generate_module_py(pythonSubPub
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pythonSubPub
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(pythonSubPub_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(pythonSubPub_generate_messages pythonSubPub_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ac-optimus/darknet_ros_ntwoc/src/pythonSubPub/msg/BoundingBox.msg" NAME_WE)
add_dependencies(pythonSubPub_generate_messages_py _pythonSubPub_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pythonSubPub_genpy)
add_dependencies(pythonSubPub_genpy pythonSubPub_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pythonSubPub_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pythonSubPub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pythonSubPub
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(pythonSubPub_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pythonSubPub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pythonSubPub
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(pythonSubPub_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pythonSubPub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pythonSubPub
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(pythonSubPub_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pythonSubPub)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pythonSubPub
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(pythonSubPub_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pythonSubPub)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pythonSubPub\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pythonSubPub
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(pythonSubPub_generate_messages_py std_msgs_generate_messages_py)
endif()