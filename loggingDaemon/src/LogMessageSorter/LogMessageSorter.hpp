#pragma once

#include <set>
#include <string>

#include "../ObserverPattern/Observer.hpp"
#include "../ObserverPattern/Subject.hpp"
#include "../Logging/Logger.hpp"
#include "LogMessageParser.hpp"

using namespace std;

class LogMessageSorter : public Observer<set<string>>, public Subject<vector<string>> {
  private:
    const string logtag = "LogMessageSorter";

  public:
    LogMessageSorter();
    ~LogMessageSorter();

    void update(set<string> LogMessages);

  private:
};