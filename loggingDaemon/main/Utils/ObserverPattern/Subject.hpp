#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "../Logging/Logger.hpp"
#include <vector>

#include "Observer.hpp"

using namespace std;

template <class T> class Subject {
  private:
    std::vector<Observer<T>*> observers;
    string logtag = "Subject";

  public:
    Subject() {
    }

    virtual ~Subject() {
    }

    void attachObserver(Observer<T>& observer) {
        Log::d(logtag, "The subject attach a observer.");
        observers.push_back(&observer);
    }

    void detachObserver(Observer<T>& observer) {
        // ToDo: implement
    }

    void detachAllObserver() {
        // ToDo: implement
    }

    void notifyObserver(T info) {
        for (int index = 0; index < observers.size(); index++) {
            this->observers[index]->update(info);
        }
    }
};

#endif // ! SUBJECT_HPP