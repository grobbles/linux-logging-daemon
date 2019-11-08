#include "ServerConnectorThreadManager.hpp"

ServerConnectorThreadManager::ServerConnectorThreadManager(string ipcServerConnectionFile) {
    this->serverConnertor = new ServerConnector(ipcServerConnectionFile);
    serverConnertor->create();
    this->serverConnertor->attachObserver(*this);

    Log::i(this->logtag, "The ServerConnectorThreadManager is created.");
}

ServerConnectorThreadManager::~ServerConnectorThreadManager() {
    Log::i(this->logtag, "Destruktor");
    delete &this->serverConnectorThread;
}

void ServerConnectorThreadManager::run() {
    Log::i(this->logtag, "The ServerConnector thread is started.");

    this->serverConnectorThread = thread(&ServerConnector::run, this->serverConnertor);
    this->serverConnectorThread.detach();
}

void ServerConnectorThreadManager::update(string clientConnectionFile) {
    this->notifyObserver(clientConnectionFile);
}