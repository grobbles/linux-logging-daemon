#pragma once

#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <string>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

#include "../Utils//ObserverPattern/Observer.hpp"
#include "../Utils/Logging/Logger.hpp"
#include "../Utils/DirectoryUtils/DirectoryUtils.hpp"

using namespace std;

class LogFileHandler : public Observer<vector<string>> {
  private:
    string logtag = "LogFileHandler";
    string logFilePath;
    string logFileName;

    std::ofstream file;

  public:
    LogFileHandler(string logFilePath, string logFileName);
    ~LogFileHandler();

    void update(vector<string> logMessages);

  private:
    string createDate();
    string numberToStringWithFixedLength(const int i, const int length);
};