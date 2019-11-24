/*
 * GrpcTransporter.hpp
 *
 *  Created on:
 *      Author: Uwe Roder (uweroder@gmail.com)
 */
#ifndef GRPCTRANSPORTER_HPP
#define GRPCTRANSPORTER_HPP

#include <set>
#include <string>
#include <vector>

#include "LogMessageTransporterClientImplementation.h"
#include "LoggingTransporter.hpp"

// #include "Logging/Logger.hpp"

using namespace std;

class GrpcTransporter : public LoggingTransporter {
  private:
    const string logtag = "GrpcTransporter";
    LogMessageTransporterClientImplementation* client;

  public:
    GrpcTransporter();
    ~GrpcTransporter();

    bool sendMessage(string message);
};

#endif /* GRPCTRANSPORTER_HPP */
