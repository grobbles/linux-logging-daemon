#ifndef LOGGING_CLIENT_INTERFACE_HPP
#define LOGGING_CLIENT_INTERFACE_HPP

#include <set>
#include <vector>
#include <string>

#include "../Utils/Logging/Logger.hpp"
#include "../Utils/ObserverPattern/Observer.hpp"
#include "../Utils/ObserverPattern/Subject.hpp"

#include "DomainSocket/DomainSocketClientInterface.hpp"
#include "GRPC/GrpcClientInterface.hpp"
#include "LogMessageProvider.hpp"

using namespace std;

class LoggingClientInterface : public LogMessageProvider {
  private:
    const string logtag = "LoggingClientInterface";

    vector<LogMessageProvider*> logMessageProviders;

  public:
    LoggingClientInterface();
    ~LoggingClientInterface();

    set<string> getMessages();

  private:
};

#endif // LOGGING_CLIENT_INTERFACE_HPP