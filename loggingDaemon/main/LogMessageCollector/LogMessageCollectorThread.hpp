#pragma once

#include <atomic>
#include <queue>
#include <set>
#include <string>

#include "../LoggingClientInterface/LogMessageProvider.hpp"
#include "../Utils/ObserverPattern/Observer.hpp"
#include "../Utils/ObserverPattern/Subject.hpp"
#include "../Utils/Logging/Logger.hpp"

using namespace std;

class LogMessageCollectorThread : public Subject<set<string>> {

  private:
    const string logtag = "LogMessageCollectorThread";
    LogMessageProvider* logMessageProvider;

  public:
    LogMessageCollectorThread(LogMessageProvider* logMessageProvider);
    ~LogMessageCollectorThread();

    void runCollectionThread();
};