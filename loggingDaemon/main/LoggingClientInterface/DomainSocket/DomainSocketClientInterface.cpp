#include "DomainSocketClientInterface.hpp"

DomainSocketClientInterface::DomainSocketClientInterface() {
    Log::i(logtag, "The DomainSocketClientInterface constructor is called.");

    this->initialConnection = new InitialConnection(DomainSocketClientInterface::INITIAL_CONNECTION_UDS_FILE);
    this->clientConnector = new ClientConnector();

    this->initialConnection->attachObserver(*this->clientConnector);
    this->initialConnection->start();
    Log::i(logtag, "The DomainSocketClientInterface is created.");
}

DomainSocketClientInterface::~DomainSocketClientInterface() {
    delete this->initialConnection;
    delete this->clientConnector;
    Log::i(logtag, "The DomainSocketClientInterface is destroyed.");
}

set<string> DomainSocketClientInterface::getMessages() {
    set<string> result;

    vector<DataStorage<string>*> logMessageStorages = this->clientConnector->getLogMessageStorages();

    for (auto logMessageStorage : logMessageStorages) {
        set<string> logMessages = logMessageStorage->readMessages();
        result.insert(logMessages.begin(), logMessages.end());
    }
    return result;
}