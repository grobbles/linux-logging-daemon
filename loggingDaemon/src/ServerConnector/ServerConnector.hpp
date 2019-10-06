#pragma once

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

#include "ServerException.hpp"
#include "../ObserverPattern/Subject.hpp"
#include "../Logging/Logger.hpp"


using namespace std;

#define BUF 1024

class ServerConnector : public Subject<string> {
  private:
    string logtag = "ServerConnector";
    string ipcServerConnectionFile;

    int create_socket;
    int new_socket;
    socklen_t addrlen;

    struct sockaddr_un address;

  public:
    ServerConnector(string ipcServerConnectionFile);
    ~ServerConnector();

    void create();
    void run();

  private:
    void clientConnectionThread();
};
