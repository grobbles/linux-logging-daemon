#ifndef LOG_MESSAGE_TRANSPORTER_CLIENT_IMPLEMENTATION_h
#define LOG_MESSAGE_TRANSPORTER_CLIENT_IMPLEMENTATION_h

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

#include "StringUtils/StringUtils.hpp"

#include <grpcpp/grpcpp.h>
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

#include "protoBuf/LogMessageTransporter.grpc.pb.h"
using logmessagetransporter::AcknowledgeReply;
using logmessagetransporter::LogMessageTransporter;
using logmessagetransporter::MessagesRequest;

using namespace std;

#define BUF 2048
#define UDS_FILE "/tmp/loggingServer/serverConnection.uds"

class LogMessageTransporterClientImplementation {
  public:
    LogMessageTransporterClientImplementation(std::shared_ptr<Channel> channel) : stub_(LogMessageTransporter::NewStub(channel)) {
    }

    bool sendLogMessages(vector<string> logMessage);

  private:
    std::unique_ptr<LogMessageTransporter::Stub> stub_;
};

#endif // ! LOG_MESSAGE_TRANSPORTER_CLIENT_IMPLEMENTATION_h