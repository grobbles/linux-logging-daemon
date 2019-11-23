
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>

#include "Logger.h"
#include "StringUtils/StringUtils.hpp"

using namespace std;

int main(int argc, char** argv) {
    string logtag = "ClientMain";

    Logger::i(logtag, "The socket is created.");
    for (int i = 0; i < 20000; i++) {
        Logger::i(logtag, "test message : " + std::to_string(i));
        std::this_thread::sleep_for(100us);
    }
}