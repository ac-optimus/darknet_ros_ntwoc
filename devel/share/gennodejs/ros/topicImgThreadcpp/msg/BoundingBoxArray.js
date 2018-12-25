// Auto-generated. Do not edit!

// (in-package topicImgThreadcpp.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let BoundingBox = require('./BoundingBox.js');

//-----------------------------------------------------------

class BoundingBoxArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BoundingBoxArray
    // Serialize message field [message]
    // Serialize the length for message field [message]
    bufferOffset = _serializer.uint32(obj.message.length, buffer, bufferOffset);
    obj.message.forEach((val) => {
      bufferOffset = BoundingBox.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BoundingBoxArray
    let len;
    let data = new BoundingBoxArray(null);
    // Deserialize message field [message]
    // Deserialize array length for message field [message]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.message = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.message[i] = BoundingBox.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 48 * object.message.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'topicImgThreadcpp/BoundingBoxArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f1aa11c9a83d4975fd5f1e8b9d0289f2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    BoundingBox[] message
    
    ================================================================================
    MSG: topicImgThreadcpp/BoundingBox
    int64 Class
    float64 probability
    int64 xmin
    int64 ymin
    int64 xmax
    int64 ymax
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BoundingBoxArray(null);
    if (msg.message !== undefined) {
      resolved.message = new Array(msg.message.length);
      for (let i = 0; i < resolved.message.length; ++i) {
        resolved.message[i] = BoundingBox.Resolve(msg.message[i]);
      }
    }
    else {
      resolved.message = []
    }

    return resolved;
    }
};

module.exports = BoundingBoxArray;
