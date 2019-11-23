#ifndef SERVER_EXCEPTION_H
#define SERVER_EXCEPTION_H

#include <string>

using namespace std;

class ServerException {
  private:
    string msg_;

  public:
    ServerException(const string& msg) : msg_(msg) {
    }

    ~ServerException() {
    }

    string getMessage() const {
        return (msg_);
    }
};

#endif // SERVER_EXCEPTION_H
