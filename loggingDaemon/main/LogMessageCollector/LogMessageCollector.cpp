#include "LogMessageCollector.hpp"

LogMessageCollector::LogMessageCollector(ClientConnector* clientConnector) {
    this->clientConnector = clientConnector;

    this->logMessageCollectorThread = new LogMessageCollectorThread(clientConnector);

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