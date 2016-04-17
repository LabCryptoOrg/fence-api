/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package ir.ntnaeem.gate.hotgen;

import ir.ntnaeem.hottentot.runtime.Argument;
import ir.ntnaeem.hottentot.runtime.Proxy;
import ir.ntnaeem.hottentot.runtime.Request;
import ir.ntnaeem.hottentot.runtime.Response;
import ir.ntnaeem.hottentot.runtime.TcpClient;
import ir.ntnaeem.hottentot.runtime.exception.HottentotRuntimeException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientConnectException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientReadException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientWriteException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientCloseException;
import ir.ntnaeem.hottentot.runtime.factory.ProtocolFactory;
import ir.ntnaeem.hottentot.runtime.factory.TcpClientFactory;
import ir.ntnaeem.hottentot.runtime.protocol.Protocol;
import ir.ntnaeem.hottentot.serializerHelper.PDTSerializer;
import ir.ntnaeem.hottentot.serializerHelper.PDTDeserializer;
import ir.ntnaeem.hottentot.type.*;
import java.util.List;

public class GateServiceProxy extends AbstractGateService implements Proxy {
	
  private String host;
  private int port;

  public GateServiceProxy(String host, int port) {
    this.host = host;
    this.port = port;
  }
  public long enqueue(Message message) { 
    //serialize message
    byte[] serializedMessage = message.serialize();

    //make request
    Request request = new Request();
    request.setServiceId(58024360L);
    request.setMethodId(1548427490L);
    request.setArgumentCount((byte) 1);
    request.setType(Request.RequestType.InvokeStateless);
    Argument arg0 = new Argument();
    arg0.setDataLength(serializedMessage.length);
    arg0.setData(serializedMessage);
    request.addArgument(arg0);
    int dataLength = 0;
    //calculate data length for every argument
    //calulate messageDataLength
    int messageDataLength= serializedMessage.length;
    int messageDataLengthByteArrayLength = 1;
    if (messageDataLength >= 0x80) {
      if (messageDataLength <= 0xff) {
        //ex 0x81 0xff
        messageDataLengthByteArrayLength = 2;
      } else if (messageDataLength <= 0xffff) {
        //ex 0x82 0xff 0xff
        messageDataLengthByteArrayLength = 3;
      } else if (messageDataLength <= 0xffffff) {
        //ex 0x83 0xff 0xff 0xff
        messageDataLengthByteArrayLength = 4;
      }
    }
    dataLength += messageDataLength + messageDataLengthByteArrayLength;
    //arg count(1) + request type(1) + method ID(4) + service ID(4) = 10;
    request.setLength(10 + dataLength);
    //connect to server
    TcpClient tcpClient = TcpClientFactory.create();
    try{
      tcpClient.connect(host, port);
    } catch (TcpClientConnectException e) {
      throw new HottentotRuntimeException(e);
    }
    //serialize request according to HTNP
    Protocol protocol = ProtocolFactory.create();
    byte[] serializedRequest = protocol.serializeRequest(request);
    //send request
    try {
      tcpClient.write(serializedRequest);
    } catch (TcpClientWriteException e) {
      throw new HottentotRuntimeException(e);
    }
    //read response from server
    byte[] buffer = new byte[256];
    while (!protocol.isResponseComplete()) {
      byte[] dataChunkRead;
      try {
        dataChunkRead = tcpClient.read();
      } catch (TcpClientReadException e) {
        throw new HottentotRuntimeException(e);
      }
      protocol.processDataForResponse(dataChunkRead);
    }
    Response response = protocol.getResponse();
    //close everything
     try { 
       tcpClient.close(); 
    } catch (TcpClientCloseException e) { 
      e.printStackTrace(); 
    } 
    //deserialize uint64part from response
    if (response.getStatusCode() == -1) {
      //TODO
    }
    _Int64 ret = new _Int64();
    ret.deserialize(response.getData());
    return ret.getValue();
  }
  public short getStatus(long id) { 
    //serialize id
    _Int64 idWrapper = new _Int64(id);
    byte[] serializedId = idWrapper.serialize();

    //make request
    Request request = new Request();
    request.setServiceId(58024360L);
    request.setMethodId(118643832L);
    request.setArgumentCount((byte) 1);
    request.setType(Request.RequestType.InvokeStateless);
    Argument arg0 = new Argument();
    arg0.setDataLength(serializedId.length);
    arg0.setData(serializedId);
    request.addArgument(arg0);
    int dataLength = 0;
    //calculate data length for every argument
    //calulate idDataLength
    int idDataLength= serializedId.length;
    int idDataLengthByteArrayLength = 1;
    if (idDataLength >= 0x80) {
      if (idDataLength <= 0xff) {
        //ex 0x81 0xff
        idDataLengthByteArrayLength = 2;
      } else if (idDataLength <= 0xffff) {
        //ex 0x82 0xff 0xff
        idDataLengthByteArrayLength = 3;
      } else if (idDataLength <= 0xffffff) {
        //ex 0x83 0xff 0xff 0xff
        idDataLengthByteArrayLength = 4;
      }
    }
    dataLength += idDataLength + idDataLengthByteArrayLength;
    //arg count(1) + request type(1) + method ID(4) + service ID(4) = 10;
    request.setLength(10 + dataLength);
    //connect to server
    TcpClient tcpClient = TcpClientFactory.create();
    try{
      tcpClient.connect(host, port);
    } catch (TcpClientConnectException e) {
      throw new HottentotRuntimeException(e);
    }
    //serialize request according to HTNP
    Protocol protocol = ProtocolFactory.create();
    byte[] serializedRequest = protocol.serializeRequest(request);
    //send request
    try {
      tcpClient.write(serializedRequest);
    } catch (TcpClientWriteException e) {
      throw new HottentotRuntimeException(e);
    }
    //read response from server
    byte[] buffer = new byte[256];
    while (!protocol.isResponseComplete()) {
      byte[] dataChunkRead;
      try {
        dataChunkRead = tcpClient.read();
      } catch (TcpClientReadException e) {
        throw new HottentotRuntimeException(e);
      }
      protocol.processDataForResponse(dataChunkRead);
    }
    Response response = protocol.getResponse();
    //close everything
     try { 
       tcpClient.close(); 
    } catch (TcpClientCloseException e) { 
      e.printStackTrace(); 
    } 
    //deserialize uint16part from response
    if (response.getStatusCode() == -1) {
      //TODO
    }
    _Int16 ret = new _Int16();
    ret.deserialize(response.getData());
    return ret.getValue();
  }
  public void discard(long id) { 
    //serialize id
    _Int64 idWrapper = new _Int64(id);
    byte[] serializedId = idWrapper.serialize();

    //make request
    Request request = new Request();
    request.setServiceId(58024360L);
    request.setMethodId(3250188767L);
    request.setArgumentCount((byte) 1);
    request.setType(Request.RequestType.InvokeStateless);
    Argument arg0 = new Argument();
    arg0.setDataLength(serializedId.length);
    arg0.setData(serializedId);
    request.addArgument(arg0);
    int dataLength = 0;
    //calculate data length for every argument
    //calulate idDataLength
    int idDataLength= serializedId.length;
    int idDataLengthByteArrayLength = 1;
    if (idDataLength >= 0x80) {
      if (idDataLength <= 0xff) {
        //ex 0x81 0xff
        idDataLengthByteArrayLength = 2;
      } else if (idDataLength <= 0xffff) {
        //ex 0x82 0xff 0xff
        idDataLengthByteArrayLength = 3;
      } else if (idDataLength <= 0xffffff) {
        //ex 0x83 0xff 0xff 0xff
        idDataLengthByteArrayLength = 4;
      }
    }
    dataLength += idDataLength + idDataLengthByteArrayLength;
    //arg count(1) + request type(1) + method ID(4) + service ID(4) = 10;
    request.setLength(10 + dataLength);
    //connect to server
    TcpClient tcpClient = TcpClientFactory.create();
    try{
      tcpClient.connect(host, port);
    } catch (TcpClientConnectException e) {
      throw new HottentotRuntimeException(e);
    }
    //serialize request according to HTNP
    Protocol protocol = ProtocolFactory.create();
    byte[] serializedRequest = protocol.serializeRequest(request);
    //send request
    try {
      tcpClient.write(serializedRequest);
    } catch (TcpClientWriteException e) {
      throw new HottentotRuntimeException(e);
    }
  }
  public boolean hasMore(String label) { 
    //serialize label
    _String labelWrapper = new _String(label);
    byte[] serializedLabel = labelWrapper.serialize();

    //make request
    Request request = new Request();
    request.setServiceId(58024360L);
    request.setMethodId(2484924834L);
    request.setArgumentCount((byte) 1);
    request.setType(Request.RequestType.InvokeStateless);
    Argument arg0 = new Argument();
    arg0.setDataLength(serializedLabel.length);
    arg0.setData(serializedLabel);
    request.addArgument(arg0);
    int dataLength = 0;
    //calculate data length for every argument
    //calulate labelDataLength
    int labelDataLength= serializedLabel.length;
    int labelDataLengthByteArrayLength = 1;
    if (labelDataLength >= 0x80) {
      if (labelDataLength <= 0xff) {
        //ex 0x81 0xff
        labelDataLengthByteArrayLength = 2;
      } else if (labelDataLength <= 0xffff) {
        //ex 0x82 0xff 0xff
        labelDataLengthByteArrayLength = 3;
      } else if (labelDataLength <= 0xffffff) {
        //ex 0x83 0xff 0xff 0xff
        labelDataLengthByteArrayLength = 4;
      }
    }
    dataLength += labelDataLength + labelDataLengthByteArrayLength;
    //arg count(1) + request type(1) + method ID(4) + service ID(4) = 10;
    request.setLength(10 + dataLength);
    //connect to server
    TcpClient tcpClient = TcpClientFactory.create();
    try{
      tcpClient.connect(host, port);
    } catch (TcpClientConnectException e) {
      throw new HottentotRuntimeException(e);
    }
    //serialize request according to HTNP
    Protocol protocol = ProtocolFactory.create();
    byte[] serializedRequest = protocol.serializeRequest(request);
    //send request
    try {
      tcpClient.write(serializedRequest);
    } catch (TcpClientWriteException e) {
      throw new HottentotRuntimeException(e);
    }
    //read response from server
    byte[] buffer = new byte[256];
    while (!protocol.isResponseComplete()) {
      byte[] dataChunkRead;
      try {
        dataChunkRead = tcpClient.read();
      } catch (TcpClientReadException e) {
        throw new HottentotRuntimeException(e);
      }
      protocol.processDataForResponse(dataChunkRead);
    }
    Response response = protocol.getResponse();
    //close everything
     try { 
       tcpClient.close(); 
    } catch (TcpClientCloseException e) { 
      e.printStackTrace(); 
    } 
    //deserialize boolpart from response
    if (response.getStatusCode() == -1) {
      //TODO
    }
    _Boolean ret = new _Boolean();
    ret.deserialize(response.getData());
    return ret.getValue();
  }
  public Message popNext(String label) { 
    //serialize label
    _String labelWrapper = new _String(label);
    byte[] serializedLabel = labelWrapper.serialize();

    //make request
    Request request = new Request();
    request.setServiceId(58024360L);
    request.setMethodId(3070562612L);
    request.setArgumentCount((byte) 1);
    request.setType(Request.RequestType.InvokeStateless);
    Argument arg0 = new Argument();
    arg0.setDataLength(serializedLabel.length);
    arg0.setData(serializedLabel);
    request.addArgument(arg0);
    int dataLength = 0;
    //calculate data length for every argument
    //calulate labelDataLength
    int labelDataLength= serializedLabel.length;
    int labelDataLengthByteArrayLength = 1;
    if (labelDataLength >= 0x80) {
      if (labelDataLength <= 0xff) {
        //ex 0x81 0xff
        labelDataLengthByteArrayLength = 2;
      } else if (labelDataLength <= 0xffff) {
        //ex 0x82 0xff 0xff
        labelDataLengthByteArrayLength = 3;
      } else if (labelDataLength <= 0xffffff) {
        //ex 0x83 0xff 0xff 0xff
        labelDataLengthByteArrayLength = 4;
      }
    }
    dataLength += labelDataLength + labelDataLengthByteArrayLength;
    //arg count(1) + request type(1) + method ID(4) + service ID(4) = 10;
    request.setLength(10 + dataLength);
    //connect to server
    TcpClient tcpClient = TcpClientFactory.create();
    try{
      tcpClient.connect(host, port);
    } catch (TcpClientConnectException e) {
      throw new HottentotRuntimeException(e);
    }
    //serialize request according to HTNP
    Protocol protocol = ProtocolFactory.create();
    byte[] serializedRequest = protocol.serializeRequest(request);
    //send request
    try {
      tcpClient.write(serializedRequest);
    } catch (TcpClientWriteException e) {
      throw new HottentotRuntimeException(e);
    }
    //read response from server
    byte[] buffer = new byte[256];
    while (!protocol.isResponseComplete()) {
      byte[] dataChunkRead;
      try {
        dataChunkRead = tcpClient.read();
      } catch (TcpClientReadException e) {
        throw new HottentotRuntimeException(e);
      }
      protocol.processDataForResponse(dataChunkRead);
    }
    Response response = protocol.getResponse();
    //close everything
     try { 
       tcpClient.close(); 
    } catch (TcpClientCloseException e) { 
      e.printStackTrace(); 
    } 
    //deserialize Messagepart from response
    Message message= null;
    if (response.getStatusCode() == -1) {
      //TODO
    }
    message= new Message();
    message.deserialize(response.getData());
    return message;
  }
  public void ack(long id) { 
    //serialize id
    _Int64 idWrapper = new _Int64(id);
    byte[] serializedId = idWrapper.serialize();

    //make request
    Request request = new Request();
    request.setServiceId(58024360L);
    request.setMethodId(3312297367L);
    request.setArgumentCount((byte) 1);
    request.setType(Request.RequestType.InvokeStateless);
    Argument arg0 = new Argument();
    arg0.setDataLength(serializedId.length);
    arg0.setData(serializedId);
    request.addArgument(arg0);
    int dataLength = 0;
    //calculate data length for every argument
    //calulate idDataLength
    int idDataLength= serializedId.length;
    int idDataLengthByteArrayLength = 1;
    if (idDataLength >= 0x80) {
      if (idDataLength <= 0xff) {
        //ex 0x81 0xff
        idDataLengthByteArrayLength = 2;
      } else if (idDataLength <= 0xffff) {
        //ex 0x82 0xff 0xff
        idDataLengthByteArrayLength = 3;
      } else if (idDataLength <= 0xffffff) {
        //ex 0x83 0xff 0xff 0xff
        idDataLengthByteArrayLength = 4;
      }
    }
    dataLength += idDataLength + idDataLengthByteArrayLength;
    //arg count(1) + request type(1) + method ID(4) + service ID(4) = 10;
    request.setLength(10 + dataLength);
    //connect to server
    TcpClient tcpClient = TcpClientFactory.create();
    try{
      tcpClient.connect(host, port);
    } catch (TcpClientConnectException e) {
      throw new HottentotRuntimeException(e);
    }
    //serialize request according to HTNP
    Protocol protocol = ProtocolFactory.create();
    byte[] serializedRequest = protocol.serializeRequest(request);
    //send request
    try {
      tcpClient.write(serializedRequest);
    } catch (TcpClientWriteException e) {
      throw new HottentotRuntimeException(e);
    }
  }

  public void destroy() {
    //TODO
  }
}
