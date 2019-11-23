#ifndef LOGGING_SERVER_CONNECTOR_H
#define LOGGING_SERVER_CONNECTOR_H

#include <arpa/inet.h>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define BUF 2048
#define UDS_FILE "/tmp/loggingServer/serverConnection.uds"

using namespace std;

#include "LogMessageTransporterClientImplementation.h"

class LoggingServerConnector {

  private:

  LogMessageTransporterClientImplementation* client;
    int create_socket;
    string ipcServerConnetionFile;
    mutex transferMutex;

  public:
    static LoggingServerConnector& getInstance();

    LoggingServerConnector(LoggingServerConnector const&) = delete;
    void operator=(LoggingServerConnector const&) = delete;

    void sendLogString(string loggingMessage);

  private:
    LoggingServerConnector();
    ~LoggingServerConnector();

    void createSocket();
    void connectServer(string ipcSocketFile);
    void sendPidToServer();
    void receiveIpcServerConnetionFileFromServer();
};

#endif // ! LOGGING_SERVER_CONNECTOR_H