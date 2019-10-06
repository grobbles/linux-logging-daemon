#pragma once

#ifndef LOG_MESSAGE_STORAGE_HPP
#define LOG_MESSAGE_STORAGE_HPP

#include <atomic>
#include <queue>
#include <string>

#include "../ObserverPattern/Observer.hpp"

using namespace std;

class LogMessageStorage : public Observer<string> {

  private:
    string logtag = "LogMessageStorage";
    set<string> firstMessageStorage;
    set<string> secondMessageStorage;
    std::mutex messageStorageMutex;
    atomic<bool> messageQueueSelector;

  public:
    LogMessageStorage();
    ~LogMessageStorage();

    bool isEmpty();
    void update(string logMessageFromClient);
    tuple<bool, set<string>> readMessages();
};

#endif // LOG_MESSAGE_STORAGE_HPP