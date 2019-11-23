#include "StringUtils.hpp"

StringUtils::StringUtils() {
}

StringUtils::~StringUtils() {
}

const string WHITESPACE = " \n\r\t\f\v";

string StringUtils::trimFromLeft(const string s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
string StringUtils::trimFromRight(const string s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string StringUtils::trim(const string value) {
    return trimFromRight(trimFromLeft(value));
}

vector<string> StringUtils::split(string value, char splitCharactor) {
    stringstream valueStream(value);
    string segment;
    vector<string> resultList;

    while (std::getline(valueStream, segment, splitCharactor)) {
        segment = StringUtils::trim(segment);
        resultList.push_back(segment);
    }
    return resultList;
}

vector<string> StringUtils::split(string value, vector<char> splitCharactors) {
    stringstream valueStream(value);
    string segment;
    vector<string> resultList;

    for (auto splitCharactor : splitCharactors) {
        while (std::getline(valueStream, segment, splitCharactor)) {
            resultList.push_back(segment);
        }
    }
    return resultList;
}

string StringUtils::removeCharactor(string value, char charactorToRemve) {
    size_t position = value.find(charactorToRemve);
    if (position == std::string::npos) {
        return value;
    }
    return value.erase(position, 1);
}
