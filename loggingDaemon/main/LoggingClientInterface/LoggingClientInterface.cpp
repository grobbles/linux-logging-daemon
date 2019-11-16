#include "LoggingClientInterface.hpp"

LoggingClientInterface::LoggingClientInterface() {
    this->logMessageProviders.push_back(new DomainSocketClientInterface());
    this->logMessageProviders.push_back(new GrpcClientInterface());
}

LoggingClientInterface::~LoggingClientInterface() {
    for (auto provider : this->logMessageProviders) {
        delete provider;
    }
}

set<string> LoggingClientInterface::getMessages() {
    set<string> result;
    for (auto provider : this->logMessageProviders) {
        set<string> messages = provider->getMessages();
        result.insert(messages.begin(), messages.end());
        delete provider;
    }
    return set<string>();
}
