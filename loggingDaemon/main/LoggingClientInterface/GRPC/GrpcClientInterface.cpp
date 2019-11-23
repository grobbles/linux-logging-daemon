#include "GrpcClientInterface.hpp"

GrpcClientInterface::GrpcClientInterface() {
    Log::i(logtag, "The GrpcClientInterface constructor is called.");

    std::string address("0.0.0.0:50051");
    // this->serviceImpl = new LogMessageTransporterServiceImplementation();

    // ServerBuilder builder;
    // builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    // builder.RegisterService(this->serviceImpl);

    // this->server = unique_ptr<Server>(builder.BuildAndStart());

    this->serverThread = thread(&GrpcClientInterface::run, this);
    serverThread.detach();

    Log::i(logtag, "The GrpcClientInterface is created and Server listening on port " + address);
}

GrpcClientInterface::~GrpcClientInterface() {
    Log::i(logtag, "The GrpcClientInterface distructor is called.");
    delete this->serviceImpl;
    delete this->server;
    Log::i(logtag, "The GrpcClientInterface is destroyed.");
}

set<string> GrpcClientInterface::getMessages() {
    return this->serviceImpl->getMessages();
}

void GrpcClientInterface::run(){
        std::string address("0.0.0.0:50051");
    this->serviceImpl = new LogMessageTransporterServiceImplementation();

    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(this->serviceImpl);
    unique_ptr<Server> server(builder.BuildAndStart());
    server->Wait();
}