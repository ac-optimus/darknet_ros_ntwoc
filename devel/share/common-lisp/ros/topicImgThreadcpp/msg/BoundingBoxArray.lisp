; Auto-generated. Do not edit!


(cl:in-package topicImgThreadcpp-msg)


;//! \htmlinclude BoundingBoxArray.msg.html

(cl:defclass <BoundingBoxArray> (roslisp-msg-protocol:ros-message)
  ((message
    :reader message
    :initarg :message
    :type (cl:vector topicImgThreadcpp-msg:BoundingBox)
   :initform (cl:make-array 0 :element-type 'topicImgThreadcpp-msg:BoundingBox :initial-element (cl:make-instance 'topicImgThreadcpp-msg:BoundingBox))))
)

(cl:defclass BoundingBoxArray (<BoundingBoxArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BoundingBoxArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BoundingBoxArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name topicImgThreadcpp-msg:<BoundingBoxArray> is deprecated: use topicImgThreadcpp-msg:BoundingBoxArray instead.")))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <BoundingBoxArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader topicImgThreadcpp-msg:message-val is deprecated.  Use topicImgThreadcpp-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BoundingBoxArray>) ostream)
  "Serializes a message object of type '<BoundingBoxArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BoundingBoxArray>) istream)
  "Deserializes a message object of type '<BoundingBoxArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'message) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'message)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'topicImgThreadcpp-msg:BoundingBox))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BoundingBoxArray>)))
  "Returns string type for a message object of type '<BoundingBoxArray>"
  "topicImgThreadcpp/BoundingBoxArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BoundingBoxArray)))
  "Returns string type for a message object of type 'BoundingBoxArray"
  "topicImgThreadcpp/BoundingBoxArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BoundingBoxArray>)))
  "Returns md5sum for a message object of type '<BoundingBoxArray>"
  "f1aa11c9a83d4975fd5f1e8b9d0289f2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BoundingBoxArray)))
  "Returns md5sum for a message object of type 'BoundingBoxArray"
  "f1aa11c9a83d4975fd5f1e8b9d0289f2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BoundingBoxArray>)))
  "Returns full string definition for message of type '<BoundingBoxArray>"
  (cl:format cl:nil "BoundingBox[] message~%~%================================================================================~%MSG: topicImgThreadcpp/BoundingBox~%int64 Class~%float64 probability~%int64 xmin~%int64 ymin~%int64 xmax~%int64 ymax~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BoundingBoxArray)))
  "Returns full string definition for message of type 'BoundingBoxArray"
  (cl:format cl:nil "BoundingBox[] message~%~%================================================================================~%MSG: topicImgThreadcpp/BoundingBox~%int64 Class~%float64 probability~%int64 xmin~%int64 ymin~%int64 xmax~%int64 ymax~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BoundingBoxArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'message) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BoundingBoxArray>))
  "Converts a ROS message object to a list"
  (cl:list 'BoundingBoxArray
    (cl:cons ':message (message msg))
))
