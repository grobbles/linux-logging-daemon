#pragma once

#include <atomic>
#include <queue>
#include <set>
#include <string>

#include "../LoggingClientInterface/LogMessageProvider.hpp"
#include "../Utils//ObserverPattern/Observer.hpp"
#include "../Utils//ObserverPattern/Subject.hpp"

using namespace std;

#define CYCLE_TIME 50ms

class LogMessageCollector : public Subject<set<string>>, Observer<set<string>> {
  private:
    const string logtag = "LogMessageCollector";

    LogMessageProvider* logMessageProvider;

    set<string> messageStorage;

  public:
    LogMessageCollector(LogMessageProvider* logMessageProvider);
    ~LogMessageCollector();

  private:
    void run();
};