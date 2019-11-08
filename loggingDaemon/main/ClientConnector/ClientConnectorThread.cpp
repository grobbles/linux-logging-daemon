#include "ClientConnectorThread.hpp"

ClientConnectorThread::ClientConnectorThread(string ipcClientConnectionFile) {
    this->ipcClientConnectionFile = ipcClientConnectionFile;
    this->createIpcSocket();
}

ClientConnectorThread::~ClientConnectorThread() {
    Log::i(this->logtag, "Destruktor");
}

void ClientConnectorThread::createIpcSocket() {
    if ((create_socket = socket(AF_LOCAL, SOCK_STREAM, 0)) > 0) {
        Log::v(this->logtag, "The socket is created with ipc socket file: " + this->ipcClientConnectionFile);
    }

    unlink(this->ipcClientConnectionFile.c_str());
    address.sun_family = AF_LOCAL;
    strcpy(address.sun_path, this->ipcClientConnectionFile.c_str());
    if (bind(create_socket, (struct sockaddr*)&address, sizeof(address)) != 0) {
        Log::v(this->logtag, "The port is blocked.");
    }

    listen(create_socket, 5);
    addrlen = sizeof(struct sockaddr_in);
}

void ClientConnectorThread::runClientConnectionThread() {
    Log::i(this->logtag, "The server wait of client.");

    char* buffer = (char*)malloc(1024);
    new_socket = accept(create_socket, (struct sockaddr*)&address, &addrlen);
    if (new_socket > 0) {
        Log::i(this->logtag, "The client is connected with server.");
    }

    while (1) {
        ssize_t size = recv(new_socket, buffer, 1024 - 1, 0);
        if (size == 0) {
            break;
        }
        string logMessageFromClient = string(buffer).substr(0, size);

        if (isClientDead(logMessageFromClient)) {
            break;
        }

        if (logMessageFromClient.back() != '\n') {
            logMessageFromClient.push_back('\n');
        }

        this->notifyObserver(logMessageFromClient);
    }

    Log::i(this->logtag, "The client is deaded!!!!");
    close(new_socket);
    std::this_thread::yield();
}

bool ClientConnectorThread::isClientDead(string message) {
    string clientKilled = "killed";
    return message.substr(0, clientKilled.size()) == clientKilled;
}