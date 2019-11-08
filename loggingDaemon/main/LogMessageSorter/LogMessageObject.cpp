#include "LogMessageObject.hpp"

LogMessageObject::LogMessageObject(string logMessage) {
}

LogMessageObject::LogMessageObject(string date, unsigned int pidId, unsigned int threadId, string logLevel, string logTag, string logMessage) {
    this->date = date;
    this->pidId = pidId;
    this->threadId = threadId;
    this->logLevel = logLevel;
    this->logTag = logTag;
    this->logMessage = logMessage;
}

LogMessageObject::~LogMessageObject() {
}