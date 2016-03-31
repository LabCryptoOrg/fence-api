/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 31-03-2016 01:18:44
 * Name: enqueue_report.cc
 * Description:
 *   This file contains implementation of EnqueueReport class.
 ******************************************************************/

#include <iostream>
#include <string.h>

#include <naeem/hottentot/runtime/hot_ptr.h>

#include "enqueue_report.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
  EnqueueReport::EnqueueReport(const EnqueueReport &other) {
    masterMId_ = other.masterMId_;
    slaveMId_ = other.slaveMId_;
    failed_ = other.failed_;
    errorMessage_ = other.errorMessage_;
  }
  EnqueueReport::EnqueueReport(EnqueueReport *other) {
    masterMId_ = other->masterMId_;
    slaveMId_ = other->slaveMId_;
    failed_ = other->failed_;
    errorMessage_ = other->errorMessage_;
  }
  unsigned char *
  EnqueueReport::Serialize(uint32_t *length_ptr) {
    uint32_t totalLength = 0;
    uint32_t length0 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr0;
    ptr0 = masterMId_.Serialize(&length0);
    totalLength += length0;
    uint32_t length1 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr1;
    ptr1 = slaveMId_.Serialize(&length1);
    totalLength += length1;
    uint32_t length2 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr2;
    ptr2 = failed_.Serialize(&length2);
    totalLength += length2;
    uint32_t length3 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr3;
    ptr3 = errorMessage_.Serialize(&length3);
    if (length3 < 128) {
      totalLength += 1 + length3;
    } else if (length3 < 256) {
      totalLength += 2 + length3;
    } else if (length3 < 256 * 256) {
      totalLength += 3 + length3;
    } else if (length3 < 256 * 256 * 256) {
      totalLength += 4 + length3;
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
    if (length3 < 128) {
      data[c] = length3;
      c += 1;
    } else if (length3 < 256) {
      data[c] = 0x81;
      data[c + 1] = length3;
      c += 2;
    } else if (length3 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length3 / 256;
      data[c + 2] = length3 % 256;
      c += 3;
    } else if (length3 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length3 / (256 * 256);
      data[c + 2] = (length3 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length3 % (256 * 256);
      c += 4;
    }
    unsigned char *data3 = ptr3.Get();
    for (uint32_t i = 0; i < length3; i++) {
      data[c++] = data3[i];
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
  EnqueueReport::Deserialize(unsigned char *data, uint32_t length) {
    uint32_t c = 0, elength = 0;
    masterMId_.Deserialize(data + c, 8);
    c += 8;
    slaveMId_.Deserialize(data + c, 8);
    c += 8;
    failed_.Deserialize(data + c, 1);
    c += 1;
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
    errorMessage_.Deserialize(data + c, elength);
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