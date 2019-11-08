#include "LogMessageStorage.hpp"

LogMessageStorage::LogMessageStorage() {
}

LogMessageStorage::~LogMessageStorage() {
    Log::i(this->logtag, "Destruktor");
}

void LogMessageStorage::update(string logMessageFromClient) {
    this->messageStorageMutex.lock();
    if (this->messageQueueSelector) {
        this->firstMessageStorage.insert(logMessageFromClient);
    } else {
        this->secondMessageStorage.insert(logMessageFromClient);
    }

    this->messageStorageMutex.unlock();
}

tuple<bool, set<string>> LogMessageStorage::readMessages() {
    this->messageStorageMutex.lock();

    bool isMessagesAvailbe;
    set<string> results;
    if (this->isEmpty()) {
        isMessagesAvailbe = false;
        results = set<string>();

    } else {
        isMessagesAvailbe = true;
        this->messageQueueSelector = !this->messageQueueSelector;

        if (!this->messageQueueSelector) {
            results = this->firstMessageStorage;
            this->firstMessageStorage = set<string>();
        } else {
            results = this->secondMessageStorage;
            this->secondMessageStorage = set<string>();
        }
    }

    this->messageStorageMutex.unlock();
    return make_tuple(isMessagesAvailbe, results);
}

bool LogMessageStorage::isEmpty() {
    bool isEmpty;
    if (this->messageQueueSelector) {
        isEmpty = firstMessageStorage.empty();
    } else {
        isEmpty = secondMessageStorage.empty();
    }
    return isEmpty;
}