
#include <Logger.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string logtag = "ClientMain";

    Log::i(logtag, "The socket is created.");
    for (int i = 0; i < 20000; i++) {
        Log::i(logtag, "test message : " + std::to_string(i));
        std::this_thread::sleep_for(10us);
    }
}