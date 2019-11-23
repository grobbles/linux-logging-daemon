/*
 * Logger.hpp
 *
 *  Created on: Apr 8, 2019
 *      Author: roder
 */

#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <sstream>

#include "LoggingServerConnector.hpp"
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

enum LogLevel { VERBOSE, DEBUG, INFO, WARN, ERROR };

class Logger {
  public:
    Logger();
    ~Logger();

    static void v(string logTag, string logMessage);
    static void d(string logTag, string logMessage);
    static void i(string logTag, string logMessage);
    static void w(string logTag, string logMessage);
    static void e(string logTag, string logMessage);

  private:
    static void stringOutput(string loggingMessage);

    static string getCurrentDate();
    static string createMetaInformation(string date, string logtag, string logLevel);
    static int getMilliseconds();
};

#endif /* LOG_H_ */
