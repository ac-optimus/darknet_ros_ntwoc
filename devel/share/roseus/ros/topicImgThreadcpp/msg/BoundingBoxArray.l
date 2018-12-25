;; Auto-generated. Do not edit!


(when (boundp 'topicImgThreadcpp::BoundingBoxArray)
  (if (not (find-package "TOPICIMGTHREADCPP"))
    (make-package "TOPICIMGTHREADCPP"))
  (shadow 'BoundingBoxArray (find-package "TOPICIMGTHREADCPP")))
(unless (find-package "TOPICIMGTHREADCPP::BOUNDINGBOXARRAY")
  (make-package "TOPICIMGTHREADCPP::BOUNDINGBOXARRAY"))

(in-package "ROS")
;;//! \htmlinclude BoundingBoxArray.msg.html


(defclass topicImgThreadcpp::BoundingBoxArray
  :super ros::object
  :slots (_message ))

(defmethod topicImgThreadcpp::BoundingBoxArray
  (:init
   (&key
    ((:message __message) (let (r) (dotimes (i 0) (push (instance topicImgThreadcpp::BoundingBox :init) r)) r))
    )
   (send-super :init)
   (setq _message __message)
   self)
  (:message
   (&rest __message)
   (if (keywordp (car __message))
       (send* _message __message)
     (progn
       (if __message (setq _message (car __message)))
       _message)))
  (:serialization-length
   ()
   (+
    ;; topicImgThreadcpp/BoundingBox[] _message
    (apply #'+ (send-all _message :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; topicImgThreadcpp/BoundingBox[] _message
     (write-long (length _message) s)
     (dolist (elem _message)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; topicImgThreadcpp/BoundingBox[] _message
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _message (let (r) (dotimes (i n) (push (instance topicImgThreadcpp::BoundingBox :init) r)) r))
     (dolist (elem- _message)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get topicImgThreadcpp::BoundingBoxArray :md5sum-) "f1aa11c9a83d4975fd5f1e8b9d0289f2")
(setf (get topicImgThreadcpp::BoundingBoxArray :datatype-) "topicImgThreadcpp/BoundingBoxArray")
(setf (get topicImgThreadcpp::BoundingBoxArray :definition-)
      "BoundingBox[] message

================================================================================
MSG: topicImgThreadcpp/BoundingBox
int64 Class
float64 probability
int64 xmin
int64 ymin
int64 xmax
int64 ymax
")



(provide :topicImgThreadcpp/BoundingBoxArray "f1aa11c9a83d4975fd5f1e8b9d0289f2")


