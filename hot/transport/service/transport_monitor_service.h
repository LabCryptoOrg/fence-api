/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 29-03-2016 11:19:47
 * Name: transport_monitor_service.h
 * Description:
 *   This file contains definition of service interface.
 ***************************************************************/

#ifndef _IR_NTNAEEM_GATE_TRANSPORT__SERVICE__TRANSPORT_MONITOR_SERVICE_H_
#define _IR_NTNAEEM_GATE_TRANSPORT__SERVICE__TRANSPORT_MONITOR_SERVICE_H_

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
#include <naeem/hottentot/runtime/service/hot_context.h>

#include "../enqueue_report.h"
#include "../transport_message.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
namespace service {
  class TransportMonitorService {
  public:
     TransportMonitorService() {}
     virtual ~TransportMonitorService() {}
  public:
    virtual void GetCurrentStat(
      ::naeem::hottentot::runtime::types::Utf8String &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE transport
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif