#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "../Logging/Logger.hpp"
#include <string>

using namespace std;

template <class T> class Observer {

  public:
    Observer(){};
    virtual ~Observer(){};
    virtual void update(T value){};
};

#endif // OBSERVER_HPP