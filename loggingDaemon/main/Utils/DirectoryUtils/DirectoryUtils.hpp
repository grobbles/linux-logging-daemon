#ifndef DIRECTORYUTILS_HPP
#define DIRECTORYUTILS_HPP

#include <set>
#include <string>

#include "../Logging/Logger.hpp"

using namespace std;

class DirectoryUtils {
  private:
    const string logtag = "DirectoryUtils";

  public:
    DirectoryUtils();
    ~DirectoryUtils();

    static bool remove(const string directoryPath);
    static bool create(const string directoryPath);
    static bool isExist(const string directoryPath);

};

#endif /* DIRECTORYUTILS.hpp */
