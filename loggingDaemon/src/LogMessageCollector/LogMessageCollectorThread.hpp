#pragma once

#include <atomic>
#include <queue>
#include <set>
#include <string>

#include "../ClientConnector/ClientConnector.hpp"
#include "../ObserverPattern/Observer.hpp"
#include "../ObserverPattern/Subject.hpp"
#include "../Logging/Logger.hpp"

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