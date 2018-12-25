;; Auto-generated. Do not edit!


(when (boundp 'topicImgThreadcpp::msg1)
  (if (not (find-package "TOPICIMGTHREADCPP"))
    (make-package "TOPICIMGTHREADCPP"))
  (shadow 'msg1 (find-package "TOPICIMGTHREADCPP")))
(unless (find-package "TOPICIMGTHREADCPP::MSG1")
  (make-package "TOPICIMGTHREADCPP::MSG1"))

(in-package "ROS")
;;//! \htmlinclude msg1.msg.html


(defclass topicImgThreadcpp::msg1
  :super ros::object
  :slots (_na ))

(defmethod topicImgThreadcpp::msg1
  (:init
   (&key
    ((:na __na) 0)
    )
   (send-super :init)
   (setq _na (round __na))
   self)
  (:na
   (&optional __na)
   (if __na (setq _na __na)) _na)
  (:serialization-length
   ()
   (+
    ;; int64 _na
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _na
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _na (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _na) (= (length (_na . bv)) 2)) ;; bignum
              (write-long (ash (elt (_na . bv) 0) 0) s)
              (write-long (ash (elt (_na . bv) 1) -1) s))
             ((and (class _na) (= (length (_na . bv)) 1)) ;; big1
              (write-long (elt (_na . bv) 0) s)
              (write-long (if (>= _na 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _na s)(write-long (if (>= _na 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _na
#+(or :alpha :irix6 :x86_64)
      (setf _na (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _na (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get topicImgThreadcpp::msg1 :md5sum-) "478768762c0e9899a2c051362b1eb126")
(setf (get topicImgThreadcpp::msg1 :datatype-) "topicImgThreadcpp/msg1")
(setf (get topicImgThreadcpp::msg1 :definition-)
      "int64 na

")



(provide :topicImgThreadcpp/msg1 "478768762c0e9899a2c051362b1eb126")


