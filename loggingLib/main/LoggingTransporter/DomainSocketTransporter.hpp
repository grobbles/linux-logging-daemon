/*
 * DomainSocketTransporter.hpp
 *
 *  Created on:
 *      Author: Uwe Roder (uweroder@gmail.com)
 */
#ifndef DOMAINSOCKETTRANSPORTER_HPP
#define DOMAINSOCKETTRANSPORTER_HPP

#include <arpa/inet.h>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <set>
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

#include "LoggingTransporter.hpp"

using namespace std;

class DomainSocketTransporter : public LoggingTransporter {
  private:
    const string logtag = "DomainSocketTransporter";
    int create_socket;
    string ipcServerConnetionFile;
    mutex transferMutex;

  public:
    DomainSocketTransporter();
    ~DomainSocketTransporter();

    bool sendMessage(string message);

  private:
    void createSocket();
    void connectServer(string ipcSocketFile);
    void sendPidToServer();
    void receiveIpcServerConnetionFileFromServer();
};

#endif /* DOMAINSOCKETTRANSPORTER_HPP */
