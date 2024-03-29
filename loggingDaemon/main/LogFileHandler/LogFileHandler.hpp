#ifndef LOG_FILE_HANDLER_HPP
#define LOG_FILE_HANDLER_HPP

#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <string>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

#include "ObserverPattern/Observer.hpp"
#include "DirectoryUtils/DirectoryUtils.hpp"
#include "Logging/Logger.hpp"

using namespace std;

class LogFileHandler : public Observer<set<string>> {
  private:
    string logtag = "LogFileHandler";
    string logFilePath;
    string logFileName;

    std::ofstream file;

  public:
    LogFileHandler(string logFilePath, string logFileName);
    ~LogFileHandler();

    void update(set<string> logMessages);

  private:
    string createDate();
    string numberToStringWithFixedLength(const int i, const int length);
};

#endif // !LOG_FILE_HANDLER_HPP