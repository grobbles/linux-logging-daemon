#ifndef LOG_MESSAGE_HPP
#define LOG_MESSAGE_HPP

#include <string>

using namespace std;

class LogMessage {
  public:
    string date;
    unsigned int pidId;
    unsigned int threadId;
    string logLevel;
    string logTag;
    string logMessage;

  public:
    LogMessage(string logMessage);

    LogMessage(string date, unsigned int pidId, unsigned int threadId, string logLevel, string logTag, string logMessage);
    ~LogMessage();
};

#endif // !LOG_MESSAGE_HPP