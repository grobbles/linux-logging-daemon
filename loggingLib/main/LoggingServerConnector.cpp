#include "LoggingServerConnector.hpp"

LoggingServerConnector::LoggingServerConnector() {
    this->createSocket();
    this->connectServer(UDS_FILE);
    this->sendPidToServer();
    this->receiveIpcServerConnetionFileFromServer();

    this->createSocket();
    this->connectServer(this->ipcServerConnetionFile);
    std::string address("0.0.0.0:3030");

    this->client = new LogMessageTransporterClientImplementation(grpc::CreateChannel(address, grpc::InsecureChannelCredentials()));
}

LoggingServerConnector::~LoggingServerConnector() {
    this->sendLogString("killed");
}

LoggingServerConnector& LoggingServerConnector::getInstance() {
    static LoggingServerConnector instance;
    return instance;
}

void LoggingServerConnector::createSocket() {
    this->create_socket = socket(PF_LOCAL, SOCK_STREAM, 0);
    if (this->create_socket > 0) {
        std::cout << "The socket is created." << std::endl;
    }
}

void LoggingServerConnector::connectServer(string ipcSocketFile) {
    std::cout << "Try to connected with the server over file " + ipcSocketFile << std::endl;
    struct sockaddr_un address;

    address.sun_family = AF_LOCAL;
    strcpy(address.sun_path, ipcSocketFile.c_str());

    if (connect(this->create_socket, (struct sockaddr*)&address, sizeof(address)) == 0) {
        std::cout << "The socket is connected with the server." << std::endl;
    }
}

void LoggingServerConnector::sendPidToServer() {
    std::string clientPid = std::to_string(getpid());
    std::cout << "The Client pid is: " + clientPid << std::endl;

    send(this->create_socket, clientPid.c_str(), clientPid.size(), 0);
}

void LoggingServerConnector::receiveIpcServerConnetionFileFromServer() {
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

void LoggingServerConnector::sendLogString(string loggingMessage) {
    vector<string> mes;
    mes.push_back("Test Message : " + loggingMessage);

    bool response = this->client->sendLogMessages(mes);
    // this->transferMutex.lock();
    send(create_socket, loggingMessage.c_str(), loggingMessage.size(), 0);
    // std::cout << "send message to server : " + loggingMessage << std::endl;
    // this->transferMutex.unlock();
}