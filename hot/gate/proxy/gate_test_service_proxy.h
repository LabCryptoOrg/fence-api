/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 31-03-2016 01:18:44
 * Name: gate_test_service_proxy.h
 * Description:
 *   This file contains definition of the proxy class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_GATE__PROXY__GATE_TEST_SERVICE_PROXY_H_
#define _IR_NTNAEEM_GATE__PROXY__GATE_TEST_SERVICE_PROXY_H_

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/proxy/proxy.h>

#include "gate_test_service.h"
#include "../enums.h"


namespace ir {
namespace ntnaeem {
namespace gate {
class Message;
namespace proxy {
  class GateTestServiceProxy : public GateTestService, 
    public ::naeem::hottentot::runtime::proxy::Proxy {
  public:
    GateTestServiceProxy(std::string host, uint32_t port) 
      : ::naeem::hottentot::runtime::proxy::Proxy(host, port) {}
    virtual ~GateTestServiceProxy() {}
  public:
    virtual void EnqueueAsIncomingMessage(
      ::ir::ntnaeem::gate::Message &message, 
      ::naeem::hottentot::runtime::types::UInt64 &out
    );
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif