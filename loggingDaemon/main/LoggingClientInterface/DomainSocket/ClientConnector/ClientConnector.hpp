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

#include "../../../Utils/DataStorage/DataStorage.hpp"
#include "../../../Utils/Logging/Logger.hpp"
#include "../../../Utils/ObserverPattern/Observer.hpp"

using namespace std;

class ClientConnector : public Observer<string> {
  private:
    string logtag = "ClientConnector";
    vector<thread*> threads;
    vector<ClientConnectorThread*> clientConnetorThreads;
    vector<DataStorage*> logMessageStorages;

  public:
    ClientConnector();
    ~ClientConnector();

    vector<DataStorage*> getLogMessageStorages();

  private:
    void update(string clientConnectionFile);

    void createNewClientConnection(string clientConnectionFile);
};

#endif /* !CLIENT_CONNECTOR_THREAD_MANAGER_HPP */