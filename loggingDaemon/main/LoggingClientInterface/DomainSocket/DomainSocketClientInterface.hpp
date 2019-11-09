#ifndef DOMAIN_SOCKET_CLIENT_INTERFACE_HPP
#define DOMAIN_SOCKET_CLIENT_INTERFACE_HPP

#include <set>
#include <string>

#include "../../Utils//ObserverPattern/Observer.hpp"
#include "../../Utils//ObserverPattern/Subject.hpp"
#include "../../Utils/Logging/Logger.hpp"
#include "../../Utils/DataStorage/DataStorage.hpp"

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