
#pragma once

#include "../Utils//ObserverPattern/Subject.hpp"
#include "../Utils/Logging/Logger.hpp"
#include "ServerConnector.hpp"
#include "thread"

#include <string>

using namespace std;

class ServerConnectorThreadManager : public Subject<string>, Observer<string> {
  private:
    string logtag = "ServerConnectorThreadManager";
    ServerConnector* serverConnertor;
    thread serverConnectorThread;

  public:
    ServerConnectorThreadManager(string ipcServerConnectionFile);
    ~ServerConnectorThreadManager();

    void run();

    void update(string clientConnectionFile);
};