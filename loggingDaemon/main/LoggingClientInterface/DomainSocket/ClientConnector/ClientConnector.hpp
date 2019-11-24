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

#include "DataStorage/DataStorage.hpp"
#include "Logging/Logger.hpp"
#include "ObserverPattern/Observer.hpp"
#include "ObserverPattern/Subject.hpp"

using namespace std;

class ClientConnector : public Observer<string>, Subject<string> {
  private:
    string logtag = "ClientConnector";
    vector<thread*> threads;
    vector<ClientConnectorThread*> clientConnetorThreads;
    vector<DataStorage<string>*> logMessageStorages;

  public:
    ClientConnector();
    ~ClientConnector();

    vector<DataStorage<string>*> getLogMessageStorages();

  private:
    void update(string clientConnectionFile);

    void createNewClientConnection(string clientConnectionFile);
};

#endif /* !CLIENT_CONNECTOR_THREAD_MANAGER_HPP */