#ifndef LOGGING_SERVER_CONNECTOR_H
#define LOGGING_SERVER_CONNECTOR_H

#include <iostream>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "LoggingTransporter/DomainSocketTransporter.hpp"
#include "LoggingTransporter/GrpcTransporter.hpp"
#include "LoggingTransporter/LoggingTransporter.hpp"

using namespace std;

#define UDS_FILE "/tmp/loggingServer/serverConnection.uds"

class LoggingServerConnector {

  private:
    LogMessageTransporterClientImplementation* client;
    int create_socket;
    string ipcServerConnetionFile;
    mutex transferMutex;

    vector<LoggingTransporter*> loggingTransporter;

  public:
    static LoggingServerConnector& getInstance();

    LoggingServerConnector(LoggingServerConnector const&) = delete;
    void operator=(LoggingServerConnector const&) = delete;

    void sendLogString(string loggingMessage);

  private:
    LoggingServerConnector();
    ~LoggingServerConnector();
};

#endif // ! LOGGING_SERVER_CONNECTOR_H