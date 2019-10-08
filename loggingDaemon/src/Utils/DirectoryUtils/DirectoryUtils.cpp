
#include "DirectoryUtils.hpp"

DirectoryUtils::DirectoryUtils() {
}

DirectoryUtils::~DirectoryUtils() {
}

bool DirectoryUtils::isExist(const string directory) {
    struct stat st;
    if (stat(directory.c_str(), &st) != 0) {
        return false;
    }
    return true;
}