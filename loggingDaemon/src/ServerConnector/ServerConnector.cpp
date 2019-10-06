#include "ServerConnector.hpp"

ServerConnector::ServerConnector(string ipcServerConnectionFile) {
    this->ipcServerConnectionFile = ipcServerConnectionFile;
    Log::v(this->logtag, "create ServerConnector with " + this->ipcServerConnectionFile);
}

ServerConnector::~ServerConnector() {
    Log::i(this->logtag, "Destruktor");
    close(this->create_socket);
}

void ServerConnector::create() {
    if ((create_socket = socket(AF_LOCAL, SOCK_STREAM, 0)) <= 0) {
        Log::e(this->logtag, "The socket could not be created.");
        throw ServerException("The socket could not be created");
    }
    Log::v(this->logtag, "The socket is created.");

    unlink(this->ipcServerConnectionFile.c_str());
    address.sun_family = AF_LOCAL;
    strcpy(address.sun_path, this->ipcServerConnectionFile.c_str());
    if (bind(create_socket, (struct sockaddr*)&address, sizeof(address)) != 0) {
        Log::e(this->logtag, "The port is blocked.");
        throw ServerException("The port is blocked.");
    }

    listen(create_socket, 5);
    addrlen = sizeof(struct sockaddr_in);
}

void ServerConnector::run() {
    this->clientConnectionThread();
}

void ServerConnector::clientConnectionThread() {
    char* buffer = (char*)malloc(BUF);

    while (1) {
        new_socket = accept(create_socket, (struct sockaddr*)&address, &addrlen);
        if (new_socket > 0) {
            Log::i(this->logtag, "The client is connected with server.");
        }

        ssize_t size = recv(new_socket, buffer, BUF - 1, 0);
        if (size == -1) {
            std::this_thread::sleep_for(50ms);
            continue;
        }

        string clientPid = string(buffer).substr(0, size);

        Log::i(this->logtag, "The PID received from the client is :  " + clientPid + "  with size: " + std::to_string(size));

        string serverConnectionFile = "/tmp/logServerTo" + clientPid + ".uds";

        send(new_socket, serverConnectionFile.c_str(), serverConnectionFile.size(), 0);
        Log::i(this->logtag, "The server will create clientConnectionFile :  " + serverConnectionFile);

        this->notifyObserver(serverConnectionFile);

        close(new_socket);
    }
}