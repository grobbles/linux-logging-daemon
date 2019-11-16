#ifndef LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H
#define LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H

#include <set>
#include <string>

#include "../../../Utils//ObserverPattern/Observer.hpp"
#include "../../../Utils//ObserverPattern/Subject.hpp"
#include "../../../Utils/DataStorage/DataStorage.hpp"
#include "../../../Utils/Logging/Logger.hpp"

#include "../../LogMessageProvider.hpp"

#include <grpcpp/grpcpp.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

#include "protoBuf/LogMessageTransporter.grpc.pb.h"
using logmessagetransporter::Acknowledge;
using logmessagetransporter::LogMessageTransporter;
using logmessagetransporter::Messages;

using namespace std;

class LogMessageTransporterServiceImpl : public LogMessageProvider, public LogMessageTransporter::Service {
  private:
    const string logtag = "LogMessageTransporterServiceImpl";

  public:
    LogMessageTransporterServiceImpl(){};
    ~LogMessageTransporterServiceImpl(){};

    Status sendLogMessages(ServerContext* context, const Messages* request, Acknowledge* reply) override {
        request->logmessages();
        // for (int index = 0; index < request->logmessages_size(); index++) {
        //     cout << " receive : " << request->logmessages(index) << std::endl;
        // }

        reply->set_result(true);

        return grpc::Status::OK;
    }

    // set<string> getMessages();

  private:
};

#endif // LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H