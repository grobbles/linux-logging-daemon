#include "LogMessageTransporterServiceImpl.hpp"

set<string> LogMessageTransporterServiceImplementation::getMessages() {
    set<string> logMessages = this->logMessageStorages->readMessages();
    return logMessages;
};