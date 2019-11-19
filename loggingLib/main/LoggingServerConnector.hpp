#pragma once

#include <arpa/inet.h>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define BUF 2048
#define UDS_FILE "/tmp/loggingServer/serverConnection.uds"

using namespace std;


#include <grpcpp/grpcpp.h>
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

#include "LogMessageTransporter.grpc.pb.h"
using logmessagetransporter::AcknowledgeReply;
using logmessagetransporter::LogMessageTransporter;
using logmessagetransporter::MessagesRequest;

class LogMessageTransporterClientImplementation {
  public:
    LogMessageTransporterClientImplementation(std::shared_ptr<Channel> channel) : stub_(LogMessageTransporter::NewStub(channel)) {
    }

    bool sendLogMessages(vector<string> logMessage) {
        MessagesRequest request;
        for (string mes : logMessage) {
            string* message = request.add_logmessages();
            message->append(mes);
        }
        request.set_size(logMessage.size());

        AcknowledgeReply reply;

        ClientContext context;

        Status status = stub_->sendLogMessages(&context, request, &reply);

        if (status.ok()) {
            return reply.result();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return false;
        }
    }

  private:
    std::unique_ptr<LogMessageTransporter::Stub> stub_;
};

class LoggingServerConnector {

  private:

  LogMessageTransporterClientImplementation* client;
    int create_socket;
    string ipcServerConnetionFile;
    mutex transferMutex;

  public:
    static LoggingServerConnector& getInstance();

    LoggingServerConnector(LoggingServerConnector const&) = delete;
    void operator=(LoggingServerConnector const&) = delete;

    void sendLogString(string loggingMessage);

  private:
    LoggingServerConnector();
    ~LoggingServerConnector();

    void createSocket();
    void connectServer(string ipcSocketFile);
    void sendPidToServer();
    void receiveIpcServerConnetionFileFromServer();
};