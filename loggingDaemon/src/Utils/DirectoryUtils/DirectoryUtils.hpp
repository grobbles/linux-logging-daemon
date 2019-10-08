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

    static bool remove(const string directory);
    static bool create(const string directory);
    static bool isExist(const string directory);

};

#endif /* DIRECTORYUTILS.hpp */
