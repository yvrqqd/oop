#include "TritSet.h"
#include "Trit.h"

typedef unsigned int uint;

TritSet::TritSet(const std::size_t numOfTrits) {
    this->length = 0;
    this->capacity = numOfTrits;
    this->arr = new uint[ceil(2 * numOfTrits / (8 * sizeof(uint)))];
}

TritSet::TritSet(const TritSet &&ts) {
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

std::size_t TritSet::length() const {
    return this->length;
}

void TritSet::shrink() {
    if (this->length == 0)
        return;
    uint* newArr = new uint[ceil(2 * this->capacity / (8 * sizeof(uint)))];
    std::memcpy(newArr, this->arr, ceil(2 * this->capacity / (8 * sizeof(uint))));
    delete[] this->arr;
    this->capacity = this->length;
    this->arr=newArr;
}

std::size_t TritSet::trim(size_t lastIndex) {
    this->lastSetted = lastIndex;
    this->shrink();
}

std::size_t TritSet::cardinality(Trit value) const {
    std::size_t count;
    for (auto i: this->length-1)
        if (this->operator[](i) == value)
            count++;
    return count;
}

std::unordered_map<Trit::Trit, uint, std::hash<uint> > TritSet::cardinality() const {
    std::unordered_map<Trit::trit, int, std::hash<int> > tritMap = {
            {"True",    0},
            {"False",   0},
            {"Unknown", 0}
    };
    tritMap["True"] = this->cardinality(True);
    tritMap["False"] = this->cardinality(False);
    tritMap["Unknown"] = this->cardinality(Unknown);
    return tritMap;
}
