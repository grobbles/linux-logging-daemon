#include "LogMessageParser.hpp"

LogMessageParser::LogMessageParser() {
}

LogMessageParser::~LogMessageParser() {
}

LogMessageObject LogMessageParser::toObject(const string logMessage) {
    vector<string> LogMessageElememtList = StringUtils::split(logMessage, ']');

    vector<string> b;
    for (auto v : LogMessageElememtList) {
        v = StringUtils::removeCharactor(v, '[');
        v = StringUtils::trim(v);
        b.push_back(v);
    }

    string date = b[0];
    string piAndThreadId = b[1];
    string level = b[2];
    string tag = b[3];
    string message = b[4];

    unsigned int pidId = getPidId(piAndThreadId);
    unsigned int threadId = getThreadId(piAndThreadId);

    return LogMessageObject(date, pidId, threadId, level, tag, message);
}

unsigned int LogMessageParser::getPidId(string pidAndThreadId) {
    vector<string> elememtList = StringUtils::split(pidAndThreadId, '>');
    for (auto v : elememtList) {
        v = StringUtils::removeCharactor(v, '-');
        v = StringUtils::trim(v);
    }
    unsigned int pidId;
    std::istringstream iss(elememtList[0]);
    iss >> pidId;
    if (iss.fail()) {
        // something wrong happened
    }
    return pidId;
}

unsigned int LogMessageParser::getThreadId(string pidAndThreadId) {
    vector<string> elememtList = StringUtils::split(pidAndThreadId, '>');
    for (auto v : elememtList) {
        v = StringUtils::removeCharactor(v, '-');
        v = StringUtils::trim(v);
    }
    unsigned int threadId;
    std::istringstream iss(elememtList[1]);
    iss >> threadId;
    if (iss.fail()) {
        // something wrong happened
    }
    return threadId;
}

string LogMessageParser::toString(LogMessageObject logMessage) {
    string message;
    message.append("[" + logMessage.date + "]");
    message.append("[" + to_string(logMessage.pidId) + "->" + to_string(logMessage.threadId) + "]");
    message.append("[" + logMessage.logLevel + "]");
    message.append("[" + logMessage.logTag + "]");
    message.append("[" + logMessage.logMessage + "]");
    return message;
}