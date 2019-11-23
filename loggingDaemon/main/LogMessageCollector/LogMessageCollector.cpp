#include "LogMessageCollector.hpp"

LogMessageCollector::LogMessageCollector(LogMessageProvider* logMessageProvider) {
    this->logMessageProvider = logMessageProvider;

    this->logMessageCollectorThread = thread(&LogMessageCollector::run, this);
    this->logMessageCollectorThread.detach();
}

LogMessageCollector::~LogMessageCollector() {
    Log::i(this->logtag, "Destruktor");
}

void LogMessageCollector::run() {
    Log::i(logtag, "The LogMessageCollector thread is running.");

    while (1) {
        try {
            std::this_thread::sleep_for(500ms);

            set<string> messages = this->logMessageProvider->getMessages();
            this->notifyObserver(messages);

        } catch (const std::exception& e) {
            Log::e(this->logtag, "catch exception: " + string(e.what()));
        }
    }
}