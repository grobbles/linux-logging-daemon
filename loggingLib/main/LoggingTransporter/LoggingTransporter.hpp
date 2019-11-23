/*
 * LoggingTransporter.hpp
 *
 *  Created on: 
 *      Author: Uwe Roder (uweroder@gmail.com)
 */
#ifndef LOGGINGTRANSPORTER_HPP
#define LOGGINGTRANSPORTER_HPP

#include <set>
#include <string>

using namespace std;

class LoggingTransporter {
  private:
    const string logtag = "LoggingTransporter";

  public:
    LoggingTransporter(){};
    virtual ~LoggingTransporter(){};

    virtual bool sendMessage(string message){
      return false;
    };
};

#endif /* LOGGINGTRANSPORTER_HPP */
