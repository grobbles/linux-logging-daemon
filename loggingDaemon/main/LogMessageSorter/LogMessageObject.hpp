#pragma once

#include <string>

using namespace std;

class LogMessageObject {
  public:
    string date;
    unsigned int pidId;
    unsigned int threadId;
    string logLevel;
    string logTag;
    string logMessage;

  public:
    LogMessageObject(string logMessage);

    LogMessageObject(string date, unsigned int pidId, unsigned int threadId, string logLevel, string logTag, string logMessage);
    ~LogMessageObject();
};