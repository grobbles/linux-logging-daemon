#ifndef LOGGING_PROCESSOR_HPP
#define LOGGING_PROCESSOR_HPP

#include "../DirectoryUtils/DirectoryUtils.hpp"

#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

using namespace std;

class LoggingProcessor {

  private:
    string logFilePath;
    string applicationName;

    bool isSyslogEnable = false;
    bool isTerminalEnable = false;
    bool isFilelogEnable = false;

    std::ofstream file;

  public:
    static LoggingProcessor& getInstance();
    void setProperies(string logFilePath, string applicationName);

    LoggingProcessor(LoggingProcessor const&) = delete;
    void operator=(LoggingProcessor const&) = delete;
    void handleLogString(string logMessage);

    void enableSyslog();
    void enableTerminal();
    void enableFilelog();

  private:
    LoggingProcessor();
    ~LoggingProcessor();

    string createDate();
    string numberToStringWithFixedLength(const int i, const int length);
};

#endif // LOGGING_PROCESSOR_HPP