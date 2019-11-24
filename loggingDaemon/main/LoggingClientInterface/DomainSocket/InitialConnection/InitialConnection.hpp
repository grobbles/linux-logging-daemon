#ifndef INITIAL_CONNECTION_H
#define INITIAL_CONNECTION_H

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <thread>
#include <unistd.h>

#include "ObserverPattern/Subject.hpp"
#include "Logging/Logger.hpp"
#include "ServerException.hpp"

using namespace std;

#define BUF 1024
#define UDS_PATH "/tmp/loggingServer/" // UDS = unix domain socket

class InitialConnection : public Subject<string> {
  private:
    string logtag = "InitialConnection";

    const string CLIENT_UDS_PATH = "/tmp/loggingServer/";

    string ipcFile;

    int serverSocket;
    socklen_t addrlen;

    struct sockaddr_un address;
    thread initialConnectionThread;

  public:
    InitialConnection(string ipcFile);
    ~InitialConnection();

    void start();

  private:
    void run();
};

#endif // INITIAL_CONNECTION_H