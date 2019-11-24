#include "LogMessageTransporterServiceImpl.hpp"

LogMessageTransporterServiceImplementation::LogMessageTransporterServiceImplementation() {
    Log::i(logtag, "The LogMessageTransporterServiceImplementation constructor is called.");

    this->logMessageStorages = new DataStorage<string>();

    Log::i(logtag, "The LogMessageTransporterServiceImplementation is created.");
}

LogMessageTransporterServiceImplementation::~LogMessageTransporterServiceImplementation() {
    Log::i(logtag, "The LogMessageTransporterServiceImplementation distructor is called.");
    Log::i(logtag, "The LogMessageTransporterServiceImplementation is destroyed.");
};

Status LogMessageTransporterServiceImplementation::sendLogMessages(ServerContext* context, const MessagesRequest* request, AcknowledgeReply* reply) {
    request->logmessages_size();
    for (int index = 0; index < request->logmessages_size(); index++) {
        this->logMessageStorages->update(request->logmessages(index));
    }

    reply->set_result(true);
    return Status::OK;
}

set<string> LogMessageTransporterServiceImplementation::getMessages() {
    set<string> logMessages = this->logMessageStorages->readMessages();
    return logMessages;
};