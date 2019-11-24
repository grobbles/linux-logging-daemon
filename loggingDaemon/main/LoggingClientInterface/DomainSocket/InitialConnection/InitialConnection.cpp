#include "InitialConnection.hpp"

InitialConnection::InitialConnection(string ipcFile) {
    this->ipcFile = ipcFile;
    Log::v(this->logtag, "The InitialConnection is created with " + this->ipcFile);
}

InitialConnection::~InitialConnection() {
    close(this->serverSocket);
    Log::v(this->logtag, "The InitialConnection is destroyed.");
}

void InitialConnection::start() {
    if ((serverSocket = socket(AF_LOCAL, SOCK_STREAM, 0)) <= 0) {
        Log::e(this->logtag, "The socket could not be created.");
        throw ServerException("The socket could not be created");
    }
    Log::v(this->logtag, "The socket is created.");

    unlink(this->ipcFile.c_str());
    address.sun_family = AF_LOCAL;
    strcpy(address.sun_path, this->ipcFile.c_str());
    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) != 0) {
        Log::e(this->logtag, "The port is blocked.");
        throw ServerException("The port is blocked.");
    }

    listen(serverSocket, 5);
    addrlen = sizeof(struct sockaddr_in);

    this->initialConnectionThread = thread(&InitialConnection::run, this);
    this->initialConnectionThread.detach();
}

void InitialConnection::run() {
    Log::i(logtag, "The InitialConnection thread is running.");

    char* buffer = (char*)malloc(BUF);

    while (1) {
        try {
            Log::i(logtag, "The InitialConnection thread wait of client connection.");

            int connectionSocket = accept(serverSocket, (struct sockaddr*)&address, &addrlen);
            if (connectionSocket > 0) {
                Log::i(this->logtag, "The client is connected with server.");
            }

            ssize_t size = recv(connectionSocket, buffer, BUF - 1, 0);
            if (size == -1) {
                std::this_thread::sleep_for(50ms);
                continue;
            }

            string clientPid = string(buffer).substr(0, size);

            Log::i(this->logtag, "The PID received from the client is :  " + clientPid + "  with size: " + std::to_string(size));

            string serverConnectionFile = InitialConnection::CLIENT_UDS_PATH + "logServerTo" + clientPid + ".uds";

            send(connectionSocket, serverConnectionFile.c_str(), serverConnectionFile.size(), 0);
            Log::i(this->logtag, "The server will create clientConnectionFile :  " + serverConnectionFile);

            this->notifyObserver(serverConnectionFile);

            close(connectionSocket);
        } catch (const std::exception& e) {
            Log::e(this->logtag, "catch exception: " + string(e.what()));
        }
    }
}