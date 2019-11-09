#pragma once

#include <atomic>
#include <queue>
#include <set>
#include <string>


#include "../LoggingClientInterface/LogMessageProvider.hpp"
#include "../Utils//ObserverPattern/Observer.hpp"
#include "../Utils//ObserverPattern/Subject.hpp"
#include "LogMessageCollectorThread.hpp"

using namespace std;

class LogMessageCollector : public Subject<set<string>>, Observer<set<string>> {
  private:
    const string logtag = "LogMessageCollector";
    LogMessageCollectorThread* logMessageCollectorThread;
    LogMessageProvider* logMessageProvider;

    set<string> messageStorage;

  public:
    LogMessageCollector(LogMessageProvider* logMessageProvider);
    ~LogMessageCollector();

    void update(set<string> logMessages);
};