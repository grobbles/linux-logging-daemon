
#include <DirectoryUtils.hpp>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(DirectoryUtilsTest, createDirectory) {
    string path = "./TestDirectory";
    DirectoryUtils::create(path);

    struct stat st;
    EXPECT_TRUE(stat(path.c_str(), &st) == 0);
}

TEST(DirectoryUtilsTest, isExist_positivTest) {
    string path = "./TestDirectory";
    mkdir(path.c_str(), 0777);

    EXPECT_TRUE(DirectoryUtils::isExist(path));
}

TEST(DirectoryUtilsTest, isExist_negativTest) {
    string path = "./Blubb";

    EXPECT_FALSE(DirectoryUtils::isExist(path));
}

TEST(DirectoryUtilsTest, remove_testFunctionality) {
    string path = "./TestDirectory0";
    mkdir(path.c_str(), 0777);

    DirectoryUtils::remove(path);

    struct stat st;
    EXPECT_TRUE(stat(path.c_str(), &st) != 0);
}

TEST(DirectoryUtilsTest, remove_testReturnValue_positivTest) {
    string path = "./TestDirectory1";
    mkdir(path.c_str(), 0777);

    EXPECT_TRUE(DirectoryUtils::remove(path));
}

TEST(DirectoryUtilsTest, remove_testReturnValue_negativTest) {
    string path = "./Blubb";

    EXPECT_FALSE(DirectoryUtils::remove(path));
}