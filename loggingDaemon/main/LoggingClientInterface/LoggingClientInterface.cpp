#include "LoggingClientInterface.hpp"

LoggingClientInterface::LoggingClientInterface() {
    Log::i(logtag, "The LoggingClientInterface will be crated.");

    this->logMessageProviders.push_back(new DomainSocketClientInterface());
    this->logMessageProviders.push_back(new GrpcClientInterface());

    Log::i(logtag, "The LoggingClientInterface is created.");
}

LoggingClientInterface::~LoggingClientInterface() {
    Log::i(logtag, "The LoggingClientInterface distructor is called.");

    for (auto provider : this->logMessageProviders) {
        delete provider;
    }
    Log::i(logtag, "The LoggingClientInterface is destroyed.");
}

set<string> LoggingClientInterface::getMessages() {
    set<string> result;
    for (auto provider : this->logMessageProviders) {
        set<string> messages = provider->getMessages();
        result.insert(messages.begin(), messages.end());
    }
    return result;
}
