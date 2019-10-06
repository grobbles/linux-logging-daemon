#include "LogMessageCollectorThread.hpp"

LogMessageCollectorThread::LogMessageCollectorThread(ClientConnector* clientConnector) {
    this->clientConnector = clientConnector;
}

LogMessageCollectorThread::~LogMessageCollectorThread() {
    Log::i(this->logtag, "Destruktor");
}

void LogMessageCollectorThread::runCollectionThread() {
    while (true) {
        set<string> cycleResult = set<string>();

        vector<LogMessageStorage*> logMessageStorages = this->clientConnector->getLogMessageStorages();
        for (auto const& logMessageStorage : logMessageStorages) {

            bool isLogMessageStorageFull;
            set<string> logMessages = set<string>();
            tie(isLogMessageStorageFull, logMessages) = logMessageStorage->readMessages();

            if (!isLogMessageStorageFull) {
                continue;
            }

            cycleResult.insert(logMessages.begin(), logMessages.end());
        }
        this->notifyObserver(cycleResult);

        // TODO reduce time
        std::this_thread::sleep_for(50ms);
    }
}