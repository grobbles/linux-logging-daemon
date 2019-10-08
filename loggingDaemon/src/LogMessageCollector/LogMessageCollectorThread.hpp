#pragma once

#include <atomic>
#include <queue>
#include <set>
#include <string>

#include "../ClientConnector/ClientConnector.hpp"
#include "../Utils//ObserverPattern/Observer.hpp"
#include "../Utils//ObserverPattern/Subject.hpp"
#include "../Utils/Logging/Logger.hpp"

using namespace std;

class LogMessageCollectorThread : public Subject<set<string>> {

  private:
    const string logtag = "LogMessageCollectorThread";
    ClientConnector* clientConnector;

  public:
    LogMessageCollectorThread(ClientConnector* clientConnector);
    ~LogMessageCollectorThread();

    void runCollectionThread();
};