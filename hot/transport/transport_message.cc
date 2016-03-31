/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 31-03-2016 01:18:44
 * Name: transport_message.cc
 * Description:
 *   This file contains implementation of TransportMessage class.
 ******************************************************************/

#include <iostream>
#include <string.h>

#include <naeem/hottentot/runtime/hot_ptr.h>

#include "transport_message.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
  TransportMessage::TransportMessage(const TransportMessage &other) {
    masterMId_ = other.masterMId_;
    slaveId_ = other.slaveId_;
    slaveMId_ = other.slaveMId_;
    relMId_ = other.relMId_;
    relLabel_ = other.relLabel_;
    label_ = other.label_;
    content_ = other.content_;
  }
  TransportMessage::TransportMessage(TransportMessage *other) {
    masterMId_ = other->masterMId_;
    slaveId_ = other->slaveId_;
    slaveMId_ = other->slaveMId_;
    relMId_ = other->relMId_;
    relLabel_ = other->relLabel_;
    label_ = other->label_;
    content_ = other->content_;
  }
  unsigned char *
  TransportMessage::Serialize(uint32_t *length_ptr) {
    uint32_t totalLength = 0;
    uint32_t length0 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr0;
    ptr0 = masterMId_.Serialize(&length0);
    totalLength += length0;
    uint32_t length1 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr1;
    ptr1 = slaveId_.Serialize(&length1);
    totalLength += length1;
    uint32_t length2 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr2;
    ptr2 = slaveMId_.Serialize(&length2);
    totalLength += length2;
    uint32_t length3 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr3;
    ptr3 = relMId_.Serialize(&length3);
    totalLength += length3;
    uint32_t length4 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr4;
    ptr4 = relLabel_.Serialize(&length4);
    if (length4 < 128) {
      totalLength += 1 + length4;
    } else if (length4 < 256) {
      totalLength += 2 + length4;
    } else if (length4 < 256 * 256) {
      totalLength += 3 + length4;
    } else if (length4 < 256 * 256 * 256) {
      totalLength += 4 + length4;
    }
    uint32_t length5 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr5;
    ptr5 = label_.Serialize(&length5);
    if (length5 < 128) {
      totalLength += 1 + length5;
    } else if (length5 < 256) {
      totalLength += 2 + length5;
    } else if (length5 < 256 * 256) {
      totalLength += 3 + length5;
    } else if (length5 < 256 * 256 * 256) {
      totalLength += 4 + length5;
    }
    uint32_t length6 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr6;
    ptr6 = content_.Serialize(&length6);
    if (length6 < 128) {
      totalLength += 1 + length6;
    } else if (length6 < 256) {
      totalLength += 2 + length6;
    } else if (length6 < 256 * 256) {
      totalLength += 3 + length6;
    } else if (length6 < 256 * 256 * 256) {
      totalLength += 4 + length6;
    }
    unsigned char *data = new unsigned char[totalLength];
    uint32_t c = 0;
    unsigned char *data0 = ptr0.Get();
    for (uint32_t i = 0; i < length0; i++) {
      data[c++] = data0[i];
    }
    unsigned char *data1 = ptr1.Get();
    for (uint32_t i = 0; i < length1; i++) {
      data[c++] = data1[i];
    }
    unsigned char *data2 = ptr2.Get();
    for (uint32_t i = 0; i < length2; i++) {
      data[c++] = data2[i];
    }
    unsigned char *data3 = ptr3.Get();
    for (uint32_t i = 0; i < length3; i++) {
      data[c++] = data3[i];
    }
    if (length4 < 128) {
      data[c] = length4;
      c += 1;
    } else if (length4 < 256) {
      data[c] = 0x81;
      data[c + 1] = length4;
      c += 2;
    } else if (length4 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length4 / 256;
      data[c + 2] = length4 % 256;
      c += 3;
    } else if (length4 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length4 / (256 * 256);
      data[c + 2] = (length4 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length4 % (256 * 256);
      c += 4;
    }
    unsigned char *data4 = ptr4.Get();
    for (uint32_t i = 0; i < length4; i++) {
      data[c++] = data4[i];
    }
    if (length5 < 128) {
      data[c] = length5;
      c += 1;
    } else if (length5 < 256) {
      data[c] = 0x81;
      data[c + 1] = length5;
      c += 2;
    } else if (length5 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length5 / 256;
      data[c + 2] = length5 % 256;
      c += 3;
    } else if (length5 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length5 / (256 * 256);
      data[c + 2] = (length5 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length5 % (256 * 256);
      c += 4;
    }
    unsigned char *data5 = ptr5.Get();
    for (uint32_t i = 0; i < length5; i++) {
      data[c++] = data5[i];
    }
    if (length6 < 128) {
      data[c] = length6;
      c += 1;
    } else if (length6 < 256) {
      data[c] = 0x81;
      data[c + 1] = length6;
      c += 2;
    } else if (length6 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length6 / 256;
      data[c + 2] = length6 % 256;
      c += 3;
    } else if (length6 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length6 / (256 * 256);
      data[c + 2] = (length6 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length6 % (256 * 256);
      c += 4;
    }
    unsigned char *data6 = ptr6.Get();
    for (uint32_t i = 0; i < length6; i++) {
      data[c++] = data6[i];
    }
    if (c != totalLength) {
      std::cout << "Struct Serialization: Inconsistency in length of serialized byte array." << std::endl;
      exit(1);
    };
    if (length_ptr) {
      *length_ptr = totalLength;
    }
    return data;
  }
  void
  TransportMessage::Deserialize(unsigned char *data, uint32_t length) {
    uint32_t c = 0, elength = 0;
    masterMId_.Deserialize(data + c, 8);
    c += 8;
    slaveId_.Deserialize(data + c, 4);
    c += 4;
    slaveMId_.Deserialize(data + c, 8);
    c += 8;
    relMId_.Deserialize(data + c, 8);
    c += 8;
    if ((data[c] & 0x80) == 0) {
      elength = data[c];
      c++;
    } else {
      uint8_t ll = data[c] & 0x0f;
      c++;
      if (ll == 1) {
        elength = data[c];
        c += 1;
      } else if (ll == 2) {
        elength = data[c] * 256 + data[c + 1];
        c += 2;
      } else if (ll == 3) {
        elength = data[c] * 256 * 256 + data[c + 1] * 256 + data[c + 2];
        c += 3;
      }
    }
    relLabel_.Deserialize(data + c, elength);
    c += elength;
    if ((data[c] & 0x80) == 0) {
      elength = data[c];
      c++;
    } else {
      uint8_t ll = data[c] & 0x0f;
      c++;
      if (ll == 1) {
        elength = data[c];
        c += 1;
      } else if (ll == 2) {
        elength = data[c] * 256 + data[c + 1];
        c += 2;
      } else if (ll == 3) {
        elength = data[c] * 256 * 256 + data[c + 1] * 256 + data[c + 2];
        c += 3;
      }
    }
    label_.Deserialize(data + c, elength);
    c += elength;
    if ((data[c] & 0x80) == 0) {
      elength = data[c];
      c++;
    } else {
      uint8_t ll = data[c] & 0x0f;
      c++;
      if (ll == 1) {
        elength = data[c];
        c += 1;
      } else if (ll == 2) {
        elength = data[c] * 256 + data[c + 1];
        c += 2;
      } else if (ll == 3) {
        elength = data[c] * 256 * 256 + data[c + 1] * 256 + data[c + 2];
        c += 3;
      }
    }
    content_.Deserialize(data + c, elength);
    c += elength;
    if (c != length) {
      std::cout << "Struct Deserialization: Inconsistency in length of deserialized byte array." << std::endl;
      exit(1);
    };
  }
} // END OF NAMESPACE transport
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir