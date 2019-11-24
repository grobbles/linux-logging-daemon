#ifndef DOMAIN_SOCKET_CLIENT_INTERFACE_HPP
#define DOMAIN_SOCKET_CLIENT_INTERFACE_HPP

#include <set>
#include <string>

#include "ObserverPattern/Observer.hpp"
#include "ObserverPattern/Subject.hpp"
#include "DataStorage/DataStorage.hpp"
#include "Logging/Logger.hpp"

#include "../LogMessageProvider.hpp"
#include "ClientConnector/ClientConnector.hpp"
#include "InitialConnection/InitialConnection.hpp"

using namespace std;

class DomainSocketClientInterface : public LogMessageProvider {
  private:
    const string logtag = "DomainSocketClientInterface";
    const string INITIAL_CONNECTION_UDS_FILE = "/tmp/loggingServer/serverConnection.uds";

    InitialConnection* initialConnection;
    ClientConnector* clientConnector;

  public:
    DomainSocketClientInterface();
    ~DomainSocketClientInterface();

    set<string> getMessages();

  private:
};

#endif // DOMAIN_SOCKET_CLIENT_INTERFACE_HPP