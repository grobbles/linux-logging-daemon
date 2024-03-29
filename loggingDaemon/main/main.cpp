
#include "ArgumentParser/ArgumentParser.hpp"
#include "DirectoryUtils/DirectoryUtils.hpp"
#include "Logging/Logger.hpp"
#include "Logging/LoggingProcessor.hpp"

#include "LogFileHandler/LogFileHandler.hpp"
#include "LogMessageCollector/LogMessageCollector.hpp"
#include "LoggingClientInterface/LoggingClientInterface.hpp"
#include "DataStorage/DataStorage.hpp"
#include "SignalHandler/KillSignalHandler.hpp"

#include <sys/stat.h>
#include <sys/types.h>

#define UDS_FILE "/tmp/loggingServer/serverConnection.uds" // UDS = unix domain socket
#define UDS_PATH "/tmp/loggingServer/"                     // UDS = unix domain socket
#define DEFAULT_APP_NAME "LoggingServer"
#define DEFAULT_LOG_PATH "/home/uwe/LoggingServer/"
#define DEFAULT_CLIENT_LOG_FILE_NAME "Clients.log"

using namespace std;

string configLogging(const string applicationName, ArgumentParser parser) {
    string logFilePath;
    if (parser.exitsCommandOption("--logFilePath")) {
        logFilePath = parser.getCommandOption("--logFilePath");
    } else {
        logFilePath = DEFAULT_LOG_PATH;
    }

    LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    loggingProcessor.setProperies(logFilePath, applicationName);
    loggingProcessor.enableTerminal();
    loggingProcessor.enableFilelog();
    loggingProcessor.enableSyslog();

    return logFilePath;
}

int main(const int argc, const char** argv) {

    string logtag = "main";
    string clientLogFileName = DEFAULT_CLIENT_LOG_FILE_NAME;
    string applicationName = DEFAULT_APP_NAME;

    ArgumentParser parser(argc, argv);
    string logFilePath = configLogging(applicationName, parser);

    struct stat st;
    if (stat(UDS_PATH, &st) != 0) {
        if (mkdir(UDS_PATH, 0777) == -1) {
            Log::e(logtag, "Error: The path could not be created. ");
        }
    } else {
        Log::i(logtag, "The path is present. ");
    }

    try {
        KillSignalHandler killSignalHandler;

        LoggingClientInterface* loggingClientInterface = new LoggingClientInterface();
        LogMessageCollector* logMessageCollector = new LogMessageCollector(loggingClientInterface);
        LogFileHandler* logFileHandler = new LogFileHandler(logFilePath, clientLogFileName);

        logMessageCollector->attachObserver(*logFileHandler);

        while (!killSignalHandler.isKillSignalReceived()) {
            std::this_thread::sleep_for(100ms);
        }

        delete loggingClientInterface;
        delete logMessageCollector;
        delete logFileHandler;

        if (!DirectoryUtils::remove(UDS_PATH)) {
            Log::i(logtag, "The path UDS_PATH could not be deleted!");
        }
        return EXIT_SUCCESS;

    } catch (KillSignalException& e) {
        Log::e(logtag, "KillSignalHandler: ");
        std::cerr << "KillSignalHandler: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}