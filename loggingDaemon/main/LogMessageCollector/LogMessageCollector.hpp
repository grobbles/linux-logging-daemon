#ifndef LOG_MESSAGE_COLLECTOR_H
#define LOG_MESSAGE_COLLECTOR_H

#include <atomic>
#include <queue>
#include <set>
#include <string>

#include "../LoggingClientInterface/LogMessageProvider.hpp"
#include "ObserverPattern/Observer.hpp"
#include "ObserverPattern/Subject.hpp"

using namespace std;

#define CYCLE_TIME 50ms

class LogMessageCollector : public Subject<set<string>>, Observer<set<string>> {
  private:
    const string logtag = "LogMessageCollector";

    LogMessageProvider* logMessageProvider;
    thread logMessageCollectorThread;

    set<string> messageStorage;

  public:
    LogMessageCollector(LogMessageProvider* logMessageProvider);
    ~LogMessageCollector();

  private:
    void run();
};

#endif // ! LOG_MESSAGE_COLLECTOR_H