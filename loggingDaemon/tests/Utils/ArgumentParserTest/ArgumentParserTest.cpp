
#include <ArgumentParser.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(ArgumentParserTest, exitsCommandOption_positive_test) {
    LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    loggingProcessor.enableTerminal();

    const char* argv[] = { "ArgumentParserTest", "--logfile", "/var/log/daemon", "param2" };
    const int argc = 3;
    ArgumentParser argumentParser(argc, argv);

    EXPECT_TRUE(argumentParser.exitsCommandOption("--logfile"));
}

TEST(ArgumentParserTest, exitsCommandOption_negative_test) {
    LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    loggingProcessor.enableTerminal();

    const char* argv[] = { "ArgumentParserTest", "--logfile", "/var/log/daemon", "param2" };
    const int argc = 3;
    ArgumentParser argumentParser(argc, argv);

    EXPECT_FALSE(argumentParser.exitsCommandOption("--blubb"));
}

TEST(ArgumentParserTest, getCommandOption_positive_test) {
    LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    loggingProcessor.enableTerminal();

    const char* argv[] = { "ArgumentParserTest", "--logfile", "/var/log/daemon", "param2" };
    const int argc = 3;
    ArgumentParser argumentParser(argc, argv);

    EXPECT_EQ("/var/log/daemon", argumentParser.getCommandOption("--logfile"));
}

TEST(ArgumentParserTest, getCommandOption_negative_test) {
    LoggingProcessor& loggingProcessor = LoggingProcessor::getInstance();
    loggingProcessor.enableTerminal();

    const char* argv[] = { "ArgumentParserTest", "--logfile", "/var/log/daemon", "param2" };
    const int argc = 3;
    ArgumentParser argumentParser(argc, argv);

    EXPECT_EQ("", argumentParser.getCommandOption("--blubb"));
}