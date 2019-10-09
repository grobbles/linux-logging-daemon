
#include "DirectoryUtils.hpp"

DirectoryUtils::DirectoryUtils() {
}

DirectoryUtils::~DirectoryUtils() {
}

bool DirectoryUtils::isExist(const string directoryPath) {
    struct stat st;
    if (stat(directoryPath.c_str(), &st) != 0) {
        return false;
    }
    return true;
}

bool DirectoryUtils::create(const string directoryPath) {
    struct stat st;
    if (stat(directoryPath.c_str(), &st) == 0) {
        return true;
    }

    if (mkdir(directoryPath.c_str(), 0777) == -1) {
        return true;
    }
    return false;
}

bool DirectoryUtils::remove(const string directoryPath) {
    if (rmdir(directoryPath.c_str()) >= 0) {
        return true;
    }
    return false;
}