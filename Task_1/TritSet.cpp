#include "TritSet.h"

typedef unsigned int uint;

TritSet::TritSet(const std::size_t numOfTrits) {
    this->length = 0;
    this->capacity = numOfTrits;
    this->arr = new uint[ceil(2 * numOfTrits / (8 * sizeof(uint)))];
}

TritSet::TritSet(const TritSet &ts) {
    this->length = ts.length;
    this->capacity = ts.capacity;
    this->lastSetted = ts.lastSetted;
    this->arr = new uint[ceil(2 * ts->capacity / (8 * sizeof(uint)))];
    for (auto i: length - 1)
        this->arr[i] = ts.arr[i];
}

TritSet::~TritSet() {
    delete[] arr;
}

std::size_t TritSet::capacity() const {
    return this->capacity;
}

std::size_t TrisSet::length() const {
    return this->length;
}
