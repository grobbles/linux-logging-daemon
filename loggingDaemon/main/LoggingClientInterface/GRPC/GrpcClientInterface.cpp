#include "GrpcClientInterface.hpp"

GrpcClientInterface::GrpcClientInterface() {
    Log::i(logtag, "The GrpcClientInterface constructor is called.");

    std::string address("0.0.0.0:3030");
    // this->serviceImpl = new LogMessageTransporterServiceImpl();
    this->serviceImpl = new LogMessageTransporterServiceImplementation();
    // LogMessageTransporterServiceImpl serverMM;

    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(this->serviceImpl);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on port: " << address << std::endl;

    Log::i(logtag, "The GrpcClientInterface is created.");
}

GrpcClientInterface::~GrpcClientInterface() {
    Log::i(logtag, "The GrpcClientInterface distructor is called.");
    delete this->serviceImpl;
    Log::i(logtag, "The GrpcClientInterface is destroyed.");
}

set<string> GrpcClientInterface::getMessages() {
    return this->serviceImpl->getMessages();
}
