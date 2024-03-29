/*
 * Logger.cpp
 *
 *  Created on: Apr 8, 2019
 *      Author: roder
 */

#include "Logger.h"

void Logger::v(string logTag, string logmessage) {
    string metaInfos = createMetaInformation(getCurrentDate(), logTag, "VERBOSE");

    stringOutput(metaInfos + logmessage);
}

void Logger::d(string logTag, string logmessage) {
    string metaInfos = createMetaInformation(getCurrentDate(), logTag, "DEBUG");

    stringOutput(metaInfos + logmessage);
}

void Logger::i(string logTag, string logmessage) {
    string metaInfos = createMetaInformation(getCurrentDate(), logTag, "INFO");

    stringOutput(metaInfos + logmessage);
}

void Logger::w(string logTag, string logmessage) {
    string metaInfos = createMetaInformation(getCurrentDate(), logTag, "WARNING");
    stringOutput(metaInfos + logmessage);
}

void Logger::e(string logTag, string logmessage) {
    string metaInfos = createMetaInformation(getCurrentDate(), logTag, "ERROR");

    stringOutput(metaInfos + logmessage);
}

void Logger::stringOutput(string loggingMessage) {
    LoggingServerConnector& loggingProcessor = LoggingServerConnector::getInstance();

    loggingProcessor.sendLogString(loggingMessage + "\n");
}

string Logger::getCurrentDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    int milli = getMilliseconds();

    char date[30];
    sprintf(date, "%4.4d.%2.2d.%2.2d - %2.2d:%2.2d:%2.2d.%6.6d", localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday, localTime->tm_hour,
            localTime->tm_min, localTime->tm_sec, milli);
    string result = string(date);
    return result;
}

int Logger::getMilliseconds() {
    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec;
    return milli;
}

string Logger::createMetaInformation(string date, string logtag, string logLevel) {
    char logMessage[140];

    unsigned int threadId = (unsigned int)pthread_self();

    sprintf(logMessage, "[%s][%5.5d->%u][%4.4s][%30.30s] ", date.c_str(), getpid(), threadId, logLevel.c_str(), logtag.c_str());
    return logMessage;
}
