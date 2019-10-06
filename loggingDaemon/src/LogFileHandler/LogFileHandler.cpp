#include "LogFileHandler.hpp"

LogFileHandler::LogFileHandler(string logFilePath, string logFileName) {
    this->logFilePath = logFilePath;
    this->logFileName = logFileName;

    // TODO move to own class
    struct stat st;
    if (stat(logFilePath.c_str(), &st) != 0) {
        if (mkdir(logFilePath.c_str(), 0777) == -1) {
            Log::e(this->logtag, "The directory (" + logFilePath + ") could not be create");
        }
    } else {
        Log::i(this->logtag, "The path (" + logFilePath + ") is pesent");
    }

    string date = createDate();
    string logFileNameResult = date + "_" + logFileName;
    this->file = ofstream(logFilePath + logFileNameResult);
}

LogFileHandler::~LogFileHandler() {
    Log::i(this->logtag, "Destruktor");
    this->file.close();
}

string LogFileHandler::createDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    string year = numberToStringWithFixedLength(localTime->tm_year + 1900, 4);
    string mouth = numberToStringWithFixedLength(localTime->tm_mon + 1, 2);
    string day = numberToStringWithFixedLength(localTime->tm_mday, 2);
    string hour = numberToStringWithFixedLength(localTime->tm_hour, 2);
    string minutes = numberToStringWithFixedLength(localTime->tm_min, 2);

    string date = year + "-" + mouth + "-" + day + "---" + hour + "-" + minutes;
    return date;
}
string LogFileHandler::numberToStringWithFixedLength(const int i, const int length) {
    std::ostringstream ostr;
    if (i < 0) {
        ostr << '-';
    }

    ostr << std::setfill('0') << std::setw(length) << (i < 0 ? -i : i);
    return ostr.str();
}

void LogFileHandler::update(vector<string> logMessages) {
    if (!this->file.is_open()) {
        Log::i(this->logtag, "error the file is not open ");
        return;
    }

    for (auto logMessage : logMessages) {
        if (logMessage.back() != '\n') {
            logMessage.push_back('\n');
        }
        this->file << logMessage;
        this->file.flush();
    }
}