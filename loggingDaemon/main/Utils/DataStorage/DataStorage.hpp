#ifndef DATA_STORAGE_HPP
#define DATA_STORAGE_HPP

#include <atomic>
#include <queue>
#include <string>

#include "../ObserverPattern/Observer.hpp"

using namespace std;

template <class T> class DataStorage : public Observer<T> {
  private:
    string logtag = "DataStorage";
    set<T> firstStorage;
    set<T> secondStorage;
    std::mutex storageMutex;
    atomic<bool> queueSelector;

  public:
    DataStorage() {
    }
    ~DataStorage() {
    }

    void update(T newValue) {
        this->storageMutex.lock();
        if (this->queueSelector) {
            this->firstStorage.insert(newValue);
        } else {
            this->secondStorage.insert(newValue);
        }

        this->storageMutex.unlock();
    }

    set<T> readMessages() {
        this->storageMutex.lock();

        set<T> results;
        if (this->isEmpty()) {
            results = set<T>();

        } else {
            this->queueSelector = !this->queueSelector;

            if (!this->queueSelector) {
                results = this->firstStorage;
                this->firstStorage = set<T>();
            } else {
                results = this->secondStorage;
                this->secondStorage = set<T>();
            }
        }
        this->storageMutex.unlock();
        return results;
    }

  private:
    bool isEmpty() {
        bool isEmpty;
        if (this->queueSelector) {
            isEmpty = firstStorage.empty();
        } else {
            isEmpty = secondStorage.empty();
        }
        return isEmpty;
    }
};

#endif // DATA_STORAGE_HPP