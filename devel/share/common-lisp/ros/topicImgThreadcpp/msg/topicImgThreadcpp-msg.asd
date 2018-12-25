
(cl:in-package :asdf)

(defsystem "topicImgThreadcpp-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "BoundingBox" :depends-on ("_package_BoundingBox"))
    (:file "_package_BoundingBox" :depends-on ("_package"))
    (:file "BoundingBoxArray" :depends-on ("_package_BoundingBoxArray"))
    (:file "_package_BoundingBoxArray" :depends-on ("_package"))
    (:file "msg1" :depends-on ("_package_msg1"))
    (:file "_package_msg1" :depends-on ("_package"))
  ))