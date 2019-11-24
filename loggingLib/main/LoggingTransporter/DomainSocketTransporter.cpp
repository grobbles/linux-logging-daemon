
#include "DomainSocketTransporter.hpp"

DomainSocketTransporter::DomainSocketTransporter() {
    this->createSocket();
    this->connectServer(UDS_FILE);
    this->sendPidToServer();
    this->receiveIpcServerConnetionFileFromServer();

    this->createSocket();
    this->connectServer(this->ipcServerConnetionFile);
}

DomainSocketTransporter::~DomainSocketTransporter() {
}

void DomainSocketTransporter::createSocket() {
    this->create_socket = socket(PF_LOCAL, SOCK_STREAM, 0);
    if (this->create_socket > 0) {
        std::cout << "The socket is created." << std::endl;
    }
}

void DomainSocketTransporter::connectServer(string ipcSocketFile) {
    std::cout << "Try to connected with the server over file " + ipcSocketFile << std::endl;
    struct sockaddr_un address;

    address.sun_family = AF_LOCAL;
    strcpy(address.sun_path, ipcSocketFile.c_str());

    if (connect(this->create_socket, (struct sockaddr*)&address, sizeof(address)) == 0) {
        std::cout << "The socket is connected with the server." << std::endl;
    }
}

void DomainSocketTransporter::sendPidToServer() {
    std::string clientPid = std::to_string(getpid());
    std::cout << "The Client pid is: " + clientPid << std::endl;

    send(this->create_socket, clientPid.c_str(), clientPid.size(), 0);
}

void DomainSocketTransporter::receiveIpcServerConnetionFileFromServer() {
    char* buffer = (char*)malloc(BUF);

    int size;
    do {
        size = recv(this->create_socket, buffer, BUF - 1, 0);
    } while (size == 0);

    this->ipcServerConnetionFile = string(buffer).substr(0, size);
    std::cout << "The client receve message from server : " + this->ipcServerConnetionFile << std::endl;

    close(create_socket);
    usleep(5000);
}

bool DomainSocketTransporter::sendMessage(string message) {
    send(create_socket, message.c_str(), message.size(), 0);

    char* buffer = (char*)malloc(BUF);
    int size;
    do {
        size = recv(this->create_socket, buffer, BUF - 1, 0);
    } while (size == 0);
    return "ack" == string(buffer).substr(0, size);
}