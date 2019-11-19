#ifndef LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H
#define LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H

#include <set>
#include <string>

#include "../../../Utils//ObserverPattern/Observer.hpp"
#include "../../../Utils//ObserverPattern/Subject.hpp"
#include "../../../Utils/DataStorage/DataStorage.hpp"
#include "../../../Utils/Logging/Logger.hpp"

#include "../../../Utils/DataStorage/DataStorage.hpp"
#include "../../LogMessageProvider.hpp"

#include <grpcpp/grpcpp.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

#include "LogMessageTransporter.grpc.pb.h"
using logmessagetransporter::AcknowledgeReply;
using logmessagetransporter::LogMessageTransporter;
using logmessagetransporter::MessagesRequest;

using namespace std;

class LogMessageTransporterServiceImplementation final : public LogMessageTransporter::Service {

    const string logtag = "LogMessageTransporterServiceImpl";

    DataStorage<string>* logMessageStorages;
    Status sendLogMessages(ServerContext* context, const MessagesRequest* request, AcknowledgeReply* reply) override {
        request->logmessages_size();
        for (int index = 0; index < request->logmessages_size(); index++) {
            Log::i(logtag, " receive : " + request->logmessages(index));
        }

        reply->set_result(true);

        return Status::OK;
    }

  public:
    LogMessageTransporterServiceImplementation() {
        Log::i(logtag, "The LogMessageTransporterServiceImplementation constructor is called.");

        this->logMessageStorages = new DataStorage<string>();

        Log::i(logtag, "The LogMessageTransporterServiceImplementation is created.");
    }

    ~LogMessageTransporterServiceImplementation() {
        Log::i(logtag, "The LogMessageTransporterServiceImplementation distructor is called.");
        Log::i(logtag, "The LogMessageTransporterServiceImplementation is destroyed.");
    };

    set<string> getMessages();
};

// class LogMessageTransporterServiceImpl final : LogMessageTransporter::Service {
//   private:
//     const string logtag = "LogMessageTransporterServiceImpl";
//     DataStorage<string>* logMessageStorages;

//   public:
//     LogMessageTransporterServiceImpl() {
//         this->logMessageStorages = new DataStorage<string>();
//     }

//     ~LogMessageTransporterServiceImpl(){};

//     grpc::Status sendLogMessages(ServerContext* context, const MessagesRequest* request, AcknowledgeReply* response) {
//         for (auto message : request->logmessages()) {
//             this->logMessageStorages->update(message);
//         }

//         response->set_result(true);

//         return grpc::Status::OK;
//     };

//     set<string> getMessages();
// };

#endif // LOG_MESSAGE_TRANSPORTER_SERVICE_IMPL_H