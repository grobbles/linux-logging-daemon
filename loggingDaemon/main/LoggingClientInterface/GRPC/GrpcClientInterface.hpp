#ifndef GPRC_CLIENT_INTERFACE_HPP
#define GPRC_CLIENT_INTERFACE_HPP

#include <set>
#include <string>
#include <thread>

#include "ObserverPattern/Observer.hpp"
#include "ObserverPattern/Subject.hpp"
#include "DataStorage/DataStorage.hpp"
#include "Logging/Logger.hpp"

#include "../LogMessageProvider.hpp"
#include "LogMessageTransporterServiceImpl.hpp"

using namespace std;

class GrpcClientInterface : public LogMessageProvider {
  private:
    const string logtag = "GrpcClientInterface";

    LogMessageTransporterServiceImplementation* serviceImpl;
    unique_ptr<Server>* server;
    thread serverThread;

  public:
    GrpcClientInterface();
    ~GrpcClientInterface();

    set<string> getMessages();

  private:
    void run();
};

#endif // GPRC_CLIENT_INTERFACE_HPP