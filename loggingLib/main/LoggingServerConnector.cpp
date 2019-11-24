#include "LoggingServerConnector.hpp"

LoggingServerConnector::LoggingServerConnector() {
    loggingTransporter.push_back(new DomainSocketTransporter());
    // loggingTransporter.push_back(new GrpcTransporter());
}

LoggingServerConnector::~LoggingServerConnector() {
    this->sendLogString("killed");
}

LoggingServerConnector& LoggingServerConnector::getInstance() {
    static LoggingServerConnector instance;
    return instance;
}

void LoggingServerConnector::sendLogString(string loggingMessage) {
    for (auto transporter : this->loggingTransporter) {
        transporter->sendMessage(loggingMessage);
    }
}