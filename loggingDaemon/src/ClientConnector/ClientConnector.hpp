#pragma once

#ifndef CLIENT_CONNECTOR_THREAD_MANAGER_HPP
#define CLIENT_CONNECTOR_THREAD_MANAGER_HPP

#include <chrono>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <mutex>
#include <pthread.h>
#include <thread>
#include <vector>

#include "ClientConnectorThread.hpp"
#include "LogMessageStorage.hpp"

#include "../Logging/Logger.hpp"
#include "../ObserverPattern/Observer.hpp"

using namespace std;

class ClientConnector : public Observer<string> {
  private:
    string logtag = "ClientConnector";
    vector<thread*> threads;
    vector<ClientConnectorThread*> clientConnetorThreads;
    vector<LogMessageStorage*> logMessageStorages;

  public:
    ClientConnector();
    ~ClientConnector();

    vector<LogMessageStorage*> getLogMessageStorages();

  private:
    void update(string clientConnectionFile);

    void createNewClientConnection(string clientConnectionFile);
};
#endif /* !CLIENT_CONNECTOR_THREAD_MANAGER_HPP */