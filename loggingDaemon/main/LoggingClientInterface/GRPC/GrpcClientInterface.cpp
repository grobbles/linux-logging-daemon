#include "GrpcClientInterface.hpp"

GrpcClientInterface::GrpcClientInterface() {
    Log::i(logtag, "The LoggingClientInterface constructor is called.");
    Log::i(logtag, "The LoggingClientInterface is created.");
}

GrpcClientInterface::~GrpcClientInterface() {
    Log::i(logtag, "The LoggingClientInterface distructor is called.");
    Log::i(logtag, "The LoggingClientInterface is destroyed.");
}

set<string> GrpcClientInterface::getMessages() {
    set<string> result;

    return result;
}
