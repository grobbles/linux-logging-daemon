
#include "Utils/ArgumentParser/ArgumentParser.hpp"
#include "Utils/DirectoryUtils/DirectoryUtils.hpp"
#include "Utils/Logging/Logger.hpp"
#include "Utils/Logging/LoggingProcessor.hpp"

#include "ClientConnector/ClientConnector.hpp"
#include "LogFileHandler/LogFileHandler.hpp"
#include "LogMessageCollector/LogMessageCollector.hpp"
#include "LogMessageSorter/LogMessageSorter.hpp"
#include "ServerConnector/ServerConnectorThreadManager.hpp"
#include "Utils/SignalHandler/KillSignalHandler.hpp"

#include <sys/stat.h>
#include <sys/types.h>

#define UDS_FILE "/tmp/loggingServer/serverConnection.uds" // UDS = unix domain socket
#define UDS_PATH "/tmp/loggingServer/"                     // UDS = unix domain socket
#define DEFAULT_APP_NAME "LoggingServer"
#define DEFAULT_LOG_PATH "/var/log/LoggingServer/"
#define DEFUALT_CLIENT_LOG_FILE_NAME "Clients.log"

using namespace std;

string configLogging(const string applicatinName, ArgumentParser parser) {
    string logFilePath;
    if (parser.exitsCommandOption("--logFilePath")) {
        logFilePath = parser.getCommandOption("--logFilePath");
    } else {
        logFilePath = DEFAULT_LOG_PATH;
    }

    LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    loggingProcessor.setProperies(logFilePath, applicatinName);
    loggingProcessor.enableTermial();
    loggingProcessor.enableFilelog();
    loggingProcessor.enableSyslog();

    return logFilePath;
}

int main(const int argc, const char** argv) {
    string logtag = "main";
    string clientLogFileName = DEFUALT_CLIENT_LOG_FILE_NAME;
    string applicatinName = DEFAULT_APP_NAME;

    ArgumentParser parser(argc, argv);
    string logFilePath = configLogging(applicatinName, parser);

    struct stat st;
    if (stat(UDS_PATH, &st) != 0) {
        if (mkdir(UDS_PATH, 0777) == -1) {
            Log::e(logtag, "Error: The path could not be created. ");
        }
    } else {
        Log::i(logtag, "The path is pesent. ");
    }

    try {
        KillSignalHandler killSignalHandler;

        ServerConnectorThreadManager* serverConnectorThreadManager = new ServerConnectorThreadManager(UDS_FILE);
        ClientConnector* clientConnector = new ClientConnector();

        LogMessageCollector* logMessageCollector = new LogMessageCollector(clientConnector);
        LogMessageSorter* logMessageSorter = new LogMessageSorter();
        LogFileHandler* logFileHandler = new LogFileHandler(logFilePath, clientLogFileName);

        serverConnectorThreadManager->attachObserver(*clientConnector);

        logMessageCollector->attachObserver(*logMessageSorter);
        logMessageSorter->attachObserver(*logFileHandler);

        serverConnectorThreadManager->run();

        while (!killSignalHandler.isKillSignalReceived()) {
            std::this_thread::sleep_for(50ms);
        }

        delete logFileHandler;
        delete logMessageCollector;
        delete clientConnector;
        delete serverConnectorThreadManager;

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