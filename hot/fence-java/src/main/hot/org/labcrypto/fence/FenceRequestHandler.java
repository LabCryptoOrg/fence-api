/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package org.labcrypto.fence;

import java.util.List;

import org.labcrypto.hottentot.helper.*;
import org.labcrypto.hottentot.runtime.Argument;
import org.labcrypto.hottentot.runtime.Request;
import org.labcrypto.hottentot.runtime.RequestHandler;
import org.labcrypto.hottentot.runtime.Response;
import org.labcrypto.hottentot.runtime.Service;
import org.labcrypto.hottentot.runtime.config.Config;
import org.labcrypto.hottentot.runtime.exception.TcpClientConnectException;
import org.labcrypto.hottentot.runtime.exception.TcpClientReadException;
import org.labcrypto.hottentot.runtime.exception.TcpClientWriteException;


public class FenceRequestHandler extends RequestHandler {
  public FenceRequestHandler(Service service) {
    super(service);
  }
  @Override
  public Response handleRequest(Request request) throws TcpClientWriteException, TcpClientReadException, TcpClientConnectException {
    long methodId = request.getMethodId();
    FenceService fenceImpl = (AbstractFenceService) service;
    if(methodId == 2793935161L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedMessage = arg0.getData();
      Message message = new Message();
      message.deserialize(serializedMessage);
      Response response = new Response();
      long result = fenceImpl.enqueue(message);
      byte[] serializedResult = PDTSerializer.getUint64( result );
      response.setStatusCode((byte) 0);
      response.setData(serializedResult);
      response.setLength(serializedResult.length + 1);
      return response;
    }
    if(methodId == 2122157182L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedId = arg0.getData();
      long id = PDTDeserializer.getUint64(serializedId);
      Response response = new Response();
      short result = fenceImpl.getStatus(id);
      byte[] serializedResult = PDTSerializer.getUint16( result );
      response.setStatusCode((byte) 0);
      response.setData(serializedResult);
      response.setLength(serializedResult.length + 1);
      return response;
    }
    if(methodId == 2455713280L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedId = arg0.getData();
      long id = PDTDeserializer.getUint64(serializedId);
      Response response = new Response();
      fenceImpl.discard(id);
      response.setStatusCode((byte) 0);
      response.setData(new byte[]{0});
      response.setLength(0);
      return response;
    }
    if(methodId == 349651851L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedLabel = arg0.getData();
      String label = PDTDeserializer.getString(serializedLabel);
      Response response = new Response();
      boolean result = fenceImpl.hasMore(label);
      byte[] serializedResult = PDTSerializer.getBool( result );
      response.setStatusCode((byte) 0);
      response.setData(serializedResult);
      response.setLength(serializedResult.length + 1);
      return response;
    }
    if(methodId == 3680821099L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedLabel = arg0.getData();
      String label = PDTDeserializer.getString(serializedLabel);
      Message message = null;
      Response response = new Response();
      message = fenceImpl.popNext(label);
      byte[] serializedMessage;
      if(message == null){
        serializedMessage  = new byte[0];
      }else{
      serializedMessage = message.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedMessage);
      response.setLength(serializedMessage.length + 1);
      return response;
    }
    if(methodId == 529598591L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedId = arg0.getData();
      long id = PDTDeserializer.getUint64(serializedId);
      Response response = new Response();
      fenceImpl.ack(id);
      response.setStatusCode((byte) 0);
      response.setData(new byte[]{0});
      response.setLength(0);
      return response;
    }

    Response response = new Response();
    response.setStatusCode((byte) 255);
    response.setData(new byte[]{0});
    response.setLength(2);
    if(Config.isVerboseMode){
      System.out.println("WARN : method id is incorrect");
    }
    return response;
  }
}