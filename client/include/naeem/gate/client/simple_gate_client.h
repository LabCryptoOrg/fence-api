#ifndef _NAEEM_GATE__CLIENT__SIMPLE_GATE_CLIENT_H_
#define _NAEEM_GATE__CLIENT__SIMPLE_GATE_CLIENT_H_

#include "gate_client.h"


namespace naeem {
namespace gate {
namespace client {
  class SimpleGateClient : public GateClient {
  public:
    SimpleGateClient(std::string host, uint16_t port)
      : GateClient(host, port) {
    }
    virtual ~SimpleGateClient() {
    }
  public:
    virtual void Init(int argc, char **argv);
    virtual void Shutdown();
    virtual uint64_t SubmitMessage(std::string label, unsigned char *data, uint32_t length);
  };
}
}
}

#endif