// Auto-generated. Do not edit!

// (in-package topicImgThreadcpp.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class msg1 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.na = null;
    }
    else {
      if (initObj.hasOwnProperty('na')) {
        this.na = initObj.na
      }
      else {
        this.na = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type msg1
    // Serialize message field [na]
    bufferOffset = _serializer.int64(obj.na, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type msg1
    let len;
    let data = new msg1(null);
    // Deserialize message field [na]
    data.na = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'topicImgThreadcpp/msg1';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '478768762c0e9899a2c051362b1eb126';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 na
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new msg1(null);
    if (msg.na !== undefined) {
      resolved.na = msg.na;
    }
    else {
      resolved.na = 0
    }

    return resolved;
    }
};

module.exports = msg1;
