#include <DataStorage.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(DataStorageTest, getCommandOption_negative_test) {

    DataStorage dataStorage;
    set<string> messages = dataStorage.readMessages();

    // LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    // loggingProcessor.enableTerminal();

    // const char* argv[] = { "ArgumentParserTest", "--logfile", "/var/log/daemon", "param2" };
    // const int argc = 3;
    // ArgumentParser argumentParser(argc, argv);

    // EXPECT_EQ("", argumentParser.getCommandOption("--blubb"));
}