/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 LabCrypto Org.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
 
#ifndef _ORG_LABCRYPTO__FENCE__CLIENT__RECEIVER_THREAD_H_
#define _ORG_LABCRYPTO__FENCE__CLIENT__RECEIVER_THREAD_H_

#include <string>
#include <mutex>

#include "runtime.h"


namespace org {
namespace labcrypto {
namespace fence {
namespace client {
  class ReceiverThread {
  public:
    ReceiverThread (
      std::string gateHost,
      uint16_t gatePort,
      std::string popLabel,
      std::string workDirPath,
      Runtime *runtime
    ) : gatePort_(gatePort),
        gateHost_(gateHost),
        popLabel_(popLabel),
        workDirPath_(workDirPath),
        terminated_(false),
        threadTerminated_(false),
        runtime_(runtime) {
    }
    virtual ~ReceiverThread() {}
  public:
    virtual void Start();
    virtual void Shutdown();
    static void* ThreadBody(void *);
  private:
    uint16_t gatePort_;
    std::string gateHost_;
    std::string popLabel_;
    std::string workDirPath_;
    bool terminated_;
    bool threadTerminated_;
    std::mutex terminationLock_;
    Runtime *runtime_;
  };
}
}
}
}

#endif