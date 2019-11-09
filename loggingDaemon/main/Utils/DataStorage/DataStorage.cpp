#include "DataStorage.hpp"

DataStorage::DataStorage() {
}

DataStorage::~DataStorage() {
}

void DataStorage::update(string newValue) {
    this->storageMutex.lock();
    if (this->queueSelector) {
        this->firstStorage.insert(newValue);
    } else {
        this->secondStorage.insert(newValue);
    }

    this->storageMutex.unlock();
}

set<string> DataStorage::readMessages() {
    this->storageMutex.lock();

    set<string> results;
    if (this->isEmpty()) {
        results = set<string>();

    } else {
        this->queueSelector = !this->queueSelector;

        if (!this->queueSelector) {
            results = this->firstStorage;
            this->firstStorage = set<string>();
        } else {
            results = this->secondStorage;
            this->secondStorage = set<string>();
        }
    }
    this->storageMutex.unlock();
    return results;
}

bool DataStorage::isEmpty() {
    bool isEmpty;
    if (this->queueSelector) {
        isEmpty = firstStorage.empty();
    } else {
        isEmpty = secondStorage.empty();
    }
    return isEmpty;
}