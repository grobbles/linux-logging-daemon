#include "ClientConnectorThread.hpp"

ClientConnectorThread::ClientConnectorThread(string ipcClientConnectionFile) {
    this->ipcClientConnectionFile = ipcClientConnectionFile;
    this->createIpcSocket();
    Log::v(this->logtag, "The ClientConnectorThread is created.");
}

ClientConnectorThread::~ClientConnectorThread() {
    Log::v(this->logtag, "The ClientConnectorThread is destroyed.");
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

    char* buffer = (char*)malloc(2048);
    new_socket = accept(create_socket, (struct sockaddr*)&address, &addrlen);
    if (new_socket > 0) {
        Log::i(this->logtag, "The client is connected with server.");
    }

    string acknowledge = "ack";
    const char* acknowledgeBuffer = acknowledge.c_str();
    const int acknowledgeSize = acknowledge.size();

    while (1) {
        try {
            ssize_t size = recv(new_socket, buffer, 2048 - 1, 0);
            if (size == 0) {
                break;
            }
            string logMessageFromClient = string(buffer).substr(0, size);

            send(new_socket, acknowledgeBuffer, acknowledgeSize, 0);

            if (isClientDead(logMessageFromClient)) {
                break;
            }

            if (logMessageFromClient.back() != '\n') {
                logMessageFromClient.push_back('\n');
            }
            this->notifyObserver(logMessageFromClient);

        } catch (const std::exception& e) {
            Log::e(this->logtag, "catch exception: " + string(e.what()));
        }
    }

    Log::i(this->logtag, "The client is deaded!!!!");
    close(new_socket);
    std::this_thread::yield();
}

bool ClientConnectorThread::isClientDead(string message) {
    string clientKilled = "killed";
    return message.substr(0, clientKilled.size()) == clientKilled;
}