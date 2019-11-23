#ifndef LOG_MESSAGE_PARSER_HPP
#define LOG_MESSAGE_PARSER_HPP

#include <sstream>
#include <string>
#include <vector>

#include "Logging/Logger.hpp"
#include "StringUtils/StringUtils.hpp"
#include "LogMessage.hpp"

using namespace std;

class LogMessageParser {
  private:
    const string logtag = "LogMessageParser";

  public:
    static LogMessage toObject(string logMessage);
    static string toString(LogMessage logMessage);

  private:
    LogMessageParser();
    ~LogMessageParser();

    static unsigned int getPidId(string pidAndThreadId);
    static unsigned int getThreadId(string pidAndThreadId);
};

#endif // !LOG_MESSAGE_PARSER_HPP