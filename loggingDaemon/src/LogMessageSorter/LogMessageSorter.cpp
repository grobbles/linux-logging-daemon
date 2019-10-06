#include "LogMessageSorter.hpp"

LogMessageSorter::LogMessageSorter() {
}

LogMessageSorter::~LogMessageSorter() {
}

void LogMessageSorter::update(set<string> logMessages) {
    vector<string> stringResult;
    for (auto logMessageObject : logMessages) {
        stringResult.push_back(logMessageObject);
    }
    this->notifyObserver(stringResult);
}