#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "../Utils/Logging/Logger.hpp"
#include "../Utils/StringUtils/StringUtils.hpp"
#include "LogMessageObject.hpp"

using namespace std;

class LogMessageParser {
  private:
    const string logtag = "LogMessageParser";

  public:
    static LogMessageObject toObject(string logMessage);
    static string toString(LogMessageObject logMessage);

  private:
    LogMessageParser();
    ~LogMessageParser();

    static unsigned int getPidId(string pidAndThreadId);
    static unsigned int getThreadId(string pidAndThreadId);
};