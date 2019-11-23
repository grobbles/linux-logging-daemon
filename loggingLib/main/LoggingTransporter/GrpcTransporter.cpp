
#include "GrpcTransporter.hpp"

GrpcTransporter::GrpcTransporter() {
    std::string address("127.0.0.1:50051");
    this->client = new LogMessageTransporterClientImplementation(grpc::CreateChannel(address, grpc::InsecureChannelCredentials()));
}

GrpcTransporter::~GrpcTransporter() {
}

bool GrpcTransporter::sendMessage(string message) {
    vector<string> mes;
    mes.push_back("Test Message : " + message);
    bool response = this->client->sendLogMessages(mes);
    return response;
}