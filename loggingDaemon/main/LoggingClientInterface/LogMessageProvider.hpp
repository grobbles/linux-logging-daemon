#ifndef LOG_MESSAGE_PROVIDER_HPP
#define LOG_MESSAGE_PROVIDER_HPP

#include <set>
#include <string>

using namespace std;

class LogMessageProvider {

  public:
    LogMessageProvider(){};
    virtual ~LogMessageProvider(){};

    virtual set<string> getMessages() {
        return set<string>();
    };
};

#endif // LOG_MESSAGE_PROVIDER_HPP