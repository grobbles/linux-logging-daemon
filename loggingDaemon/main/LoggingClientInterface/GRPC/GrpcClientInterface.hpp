#ifndef GPRC_CLIENT_INTERFACE_HPP
#define GPRC_CLIENT_INTERFACE_HPP

#include <set>
#include <string>

#include "../../Utils//ObserverPattern/Observer.hpp"
#include "../../Utils//ObserverPattern/Subject.hpp"
#include "../../Utils/DataStorage/DataStorage.hpp"
#include "../../Utils/Logging/Logger.hpp"

#include "../LogMessageProvider.hpp"
#include "LogMessageTransporterServiceImpl/LogMessageTransporterServiceImpl.hpp"

using namespace std;

class GrpcClientInterface : public LogMessageProvider {
  private:
    const string logtag = "GrpcClientInterface";

    // LogMessageTransporterServiceImpl* serviceImpl;
    LogMessageTransporterServiceImplementation* serviceImpl;

  public:
    GrpcClientInterface();
    ~GrpcClientInterface();

    set<string> getMessages();

  private:
};

#endif // GPRC_CLIENT_INTERFACE_HPP