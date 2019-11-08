#pragma once

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