#ifndef LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H
#define LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H

#include <set>
#include <string>

#include "DataStorage/DataStorage.hpp"
#include "Logging/Logger.hpp"

#include "DataStorage/DataStorage.hpp"

#include <grpcpp/grpcpp.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

#include "protoBuf/LogMessageTransporter.grpc.pb.h"
using logmessagetransporter::AcknowledgeReply;
using logmessagetransporter::LogMessageTransporter;
using logmessagetransporter::MessagesRequest;

using namespace std;

class LogMessageTransporterServiceImplementation final : public LogMessageTransporter::Service {

  private:
    const string logtag = "LogMessageTransporterServiceImpl";
    DataStorage<string>* logMessageStorages;

  public:
    LogMessageTransporterServiceImplementation();
    ~LogMessageTransporterServiceImplementation();

    Status sendLogMessages(ServerContext* context, const MessagesRequest* request, AcknowledgeReply* reply) override;

    set<string> getMessages();
};

#endif // ! LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H