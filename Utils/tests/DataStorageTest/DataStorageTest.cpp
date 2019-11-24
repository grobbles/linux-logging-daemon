#include <DataStorage.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(DataStorageTest, getCommandOption_negative_test) {

    DataStorage<string> dataStorage;
    set<string> messages = dataStorage.readMessages();
}