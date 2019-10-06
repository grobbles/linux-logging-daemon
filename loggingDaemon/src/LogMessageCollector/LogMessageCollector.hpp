#pragma once

#include <atomic>
#include <queue>
#include <set>
#include <string>

#include "../ClientConnector/ClientConnector.hpp"
#include "../ObserverPattern/Observer.hpp"
#include "../ObserverPattern/Subject.hpp"
#include "LogMessageCollectorThread.hpp"

using namespace std;

class LogMessageCollector : public Subject<set<string>>, Observer<set<string>> {
  private:
    const string logtag = "LogMessageCollector";
    LogMessageCollectorThread* logMessageCollectorThread;
    ClientConnector* clientConnector;

    set<string> messageStorage;

  public:
    LogMessageCollector(ClientConnector* clientConnector);
    ~LogMessageCollector();

    void update(set<string> logMessages);
};