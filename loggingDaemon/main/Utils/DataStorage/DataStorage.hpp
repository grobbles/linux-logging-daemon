#ifndef DATA_STORAGE_HPP
#define DATA_STORAGE_HPP

#include <atomic>
#include <queue>
#include <string>

#include "../ObserverPattern/Observer.hpp"

using namespace std;

class DataStorage : public Observer<string> {
  private:
    string logtag = "DataStorage";
    set<string> firstStorage;
    set<string> secondStorage;
    std::mutex storageMutex;
    atomic<bool> queueSelector;

  public:
    DataStorage();
    ~DataStorage();

    void update(string newValue);
    set<string> readMessages();

  private:
    bool isEmpty();
};

#endif // DATA_STORAGE_HPP