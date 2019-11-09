#include "LogMessageCollector.hpp"

LogMessageCollector::LogMessageCollector(LogMessageProvider* logMessageProvider) {
    this->logMessageProvider = logMessageProvider;

    this->logMessageCollectorThread = new LogMessageCollectorThread(logMessageProvider);

    this->logMessageCollectorThread->attachObserver(*this);

    thread collectorThread = thread(&LogMessageCollectorThread::runCollectionThread, this->logMessageCollectorThread);
    collectorThread.detach();
}

LogMessageCollector::~LogMessageCollector() {
    Log::i(this->logtag, "Destruktor");
    delete this->logMessageCollectorThread;
}

void LogMessageCollector::update(set<string> logMessages) {
    this->notifyObserver(logMessages);
}