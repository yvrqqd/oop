#include "TritSet.h"
#include "Trit.h"

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

std::size_t TritSet::trim(const size_t lastIndex) {
    this->lastSetted = lastIndex;
    this->shrink();
}

std::size_t TritSet::cardinality(const Trit value) const {
    std::size_t count;
    for (auto i: this->length-1)
        if (this->operator[](i) == value)
            count++;
    return count;
}

std::unordered_map<const Trit, const std::size_t, std::hash<std::size_t> > TritSet::cardinality() const {
    std::unordered_map<Trit, int, std::hash<int> > tritMap = {
            {"True",    0},
            {"False",   0},
            {"Unknown", 0}
    };
    tritMap["True"] = this->cardinality(True);
    tritMap["False"] = this->cardinality(False);
    tritMap["Unknown"] = this->cardinality(Unknown);
    return tritMap;
}


void TritSet::set(const std::size_t index, const Trit value);
Trit TritSet::get(const std::size_t index);
TritSet operator&=(const TritSet&) const;
TritSet operator|=(const TritSet&) const;
TritSet operator!=(const TritSet&) const;
TritSet operator&(const TritSet&, const TritSet&) const;
TritSet operator|(const TritSet&, const TritSet&) const;
TritSet operator!(const TritSet&, const TritSet&) const;
TritSet TritSet::operator!(const TritSet&) const;
const Trit TritSet::operator[](std::size_t) const;
const Trit TritSet::operator[](std::size_t idx) const;
TritSet::TritProxy TritSet::operator[](std::size_t pos);
TritSet::TritProxy& TritSet::TritProxy::operator=(Trit trit);
TritSet::TritProxy::TritProxy(TritSet& tritset, std::size_t index);

