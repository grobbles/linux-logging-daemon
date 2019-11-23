
#include "LogMessageTransporterClientImplementation.h"

bool LogMessageTransporterClientImplementation::sendLogMessages(vector<string> logMessage) {
    MessagesRequest request;

        string dfg = "sdsdf   ";
    StringUtils::trim("sdf");
    for (string mes : logMessage) {
        string* message = request.add_logmessages();
        message->append(mes);
    }
    request.set_size(logMessage.size());

    AcknowledgeReply reply;

    ClientContext context;

    Status status = stub_->sendLogMessages(&context, request, &reply);

    if (status.ok()) {
        return reply.result();
    } else {
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return false;
    }
}