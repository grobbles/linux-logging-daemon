#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StringUtils {
  public:
    static string trim(const string value);
    static string trimFromLeft(const string value);
    static string trimFromRight(const string value);

    static vector<string> split(string value, char splitCharactor);
    static vector<string> split(string value, vector<char> splitCharactor);

    static string removeCharactor(string value, char charactorToRemve);
    static string remove(string value, string stringToRemve);

  private:
    StringUtils();
    ~StringUtils();
};