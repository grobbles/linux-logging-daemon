#ifndef CLIENT_CONNECTOR_HPP
#define CLIENT_CONNECTOR_HPP

#include <arpa/inet.h>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <pthread.h>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <thread>
#include <unistd.h>
#include <vector>

#include "Logging/Logger.hpp"
#include "ObserverPattern/Subject.hpp"

using namespace std;

class ClientConnectorThread : public Subject<string> {
  private:
    string logtag = "ClientConnectorThread";
    string clientPid;
    string ipcClientConnectionFile;

    int create_socket;
    int new_socket;
    socklen_t addrlen;

    struct sockaddr_un address;

  public:
    ClientConnectorThread(string ipcClientConnectionFile);
    ~ClientConnectorThread();

    void createIpcSocket();
    void runClientConnectionThread();

  private:
    bool isClientDead(string message);
};

#endif /* !CLIENT_CONNECTOR_HPP */