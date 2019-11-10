#include "LogMessageCollector.hpp"

LogMessageCollector::LogMessageCollector(LogMessageProvider* logMessageProvider) {
    this->logMessageProvider = logMessageProvider;

    thread collectorThread = thread(&LogMessageCollector::run, this);
    collectorThread.detach();
}

LogMessageCollector::~LogMessageCollector() {
    Log::i(this->logtag, "Destruktor");
}

void LogMessageCollector::run() {
    while (true) {
        try {
            set<string> messages = this->logMessageProvider->getMessages();
            this->notifyObserver(messages);

            std::this_thread::sleep_for(CYCLE_TIME);

        } catch (const std::exception& e) {
            Log::e(this->logtag, "catch exception: " + string(e.what()));
        }
    }
}