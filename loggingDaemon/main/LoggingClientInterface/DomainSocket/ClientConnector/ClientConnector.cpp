#include "ClientConnector.hpp"

ClientConnector::ClientConnector() {
    Log::i(this->logtag, "The ClientConnector class is created.");
}

ClientConnector::~ClientConnector() {
    Log::i(this->logtag, "The ClientConnector class is destroyed.");
}

void ClientConnector::update(string clientConnectionFile) {
    this->createNewClientConnection(clientConnectionFile);
}

void ClientConnector::createNewClientConnection(string clientConnectionFile) {
    Log::i(this->logtag, "It will be create a new client connection with socket file: " + clientConnectionFile);

    ClientConnectorThread* clientConnectorThread = new ClientConnectorThread(clientConnectionFile);

    DataStorage* logMessageStorage = new DataStorage();

    clientConnectorThread->attachObserver(*logMessageStorage);

    this->clientConnetorThreads.push_back(clientConnectorThread);
    this->logMessageStorages.push_back(logMessageStorage);

    thread t = thread(&ClientConnectorThread::runClientConnectionThread, clientConnectorThread);
    t.detach();

    this->threads.push_back(&t);
}

vector<DataStorage*> ClientConnector::getLogMessageStorages() {
    return this->logMessageStorages;
}