/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 31-03-2016 01:18:44
 * Name: gate_monitor_service_client.h
 * Description:
 *   This file contains a sample client.
 ******************************************************************/

#include <iostream>

#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>

#include "../message.h"
#include "../proxy/gate_monitor_service.h"
#include "../proxy/gate_monitor_service_proxy_builder.h"


int 
main(int argc, char **argv) {
  try {
    ::naeem::hottentot::runtime::Logger::Init();  
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Init(argc, argv);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy runtime is initialized." << std::endl;
    }
    ::ir::ntnaeem::gate::proxy::GateMonitorService *proxy = 
      ::ir::ntnaeem::gate::proxy::GateMonitorServiceProxyBuilder::Create("127.0.0.1", 2000);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy object is created." << std::endl;
    }
    try {
      // ====================================================
      // TODO: Do whatever you want with proxy objects.
      // TODO: Delete allocated objects
      // ====================================================
    } catch (std::runtime_error &e) {
      ::naeem::hottentot::runtime::Logger::GetError() << e.what() << std::endl;
    }
    ::ir::ntnaeem::gate::proxy::GateMonitorServiceProxyBuilder::Destroy(proxy);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy object is destroyed." << std::endl;
    }
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Shutdown();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy runtime is shutdown." << std::endl;
    }
    ::naeem::hottentot::runtime::Logger::Shutdown();  
  } catch (std::exception &e) {
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Shutdown();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy runtime is shutdown." << std::endl;
    }
    ::naeem::hottentot::runtime::Logger::Shutdown();  
    ::naeem::hottentot::runtime::Logger::GetError() << e.what() << std::endl;
    return 1;
  } catch (...) {
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Shutdown();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy runtime is shutdown." << std::endl;
    }
    ::naeem::hottentot::runtime::Logger::Shutdown();  
    ::naeem::hottentot::runtime::Logger::GetError() << "Error." << std::endl;
    return 1;
  }
  return 0;
}
