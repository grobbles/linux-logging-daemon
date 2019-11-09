#include "LogMessageCollectorThread.hpp"

LogMessageCollectorThread::LogMessageCollectorThread(LogMessageProvider* logMessageProvider) {
    this->logMessageProvider = logMessageProvider;
}

LogMessageCollectorThread::~LogMessageCollectorThread() {
    Log::i(this->logtag, "Destruktor");
}

void LogMessageCollectorThread::runCollectionThread() {
    while (true) {
        set<string> messages = this->logMessageProvider->getMessages();
        this->notifyObserver(messages);

        std::this_thread::sleep_for(50ms);
    }
}