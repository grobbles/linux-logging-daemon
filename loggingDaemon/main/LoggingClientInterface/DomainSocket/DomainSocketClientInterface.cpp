#include "DomainSocketClientInterface.hpp"

DomainSocketClientInterface::DomainSocketClientInterface() {

    this->initialConnection = new InitialConnection(DomainSocketClientInterface::INITIAL_CONNECTION_UDS_FILE);
    this->clientConnector = new ClientConnector();

    this->initialConnection->attachObserver(*this->clientConnector);

    this->initialConnection->start();
}

DomainSocketClientInterface::~DomainSocketClientInterface() {
    delete this->initialConnection;
    delete this->clientConnector;
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
