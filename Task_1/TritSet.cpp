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

void TritSet::set(const std::size_t index, const Trit value) {
    if (index >= this->length && value == Trit::Unknown)
        return;

    std::size_t group_index = 2 * index / (8 * sizeof(uint));
    if (group_index >= this->capacity)
        return;

    if (index + 1 > this->length)
        this->length = index + 1;

    uint bit_value;
    switch (value) {
        case Trit::True:
            bit_value = 0b01u;
            break;
        case Trit::False:
            bit_value = 0b10u;
            break;
        default:
            bit_value = 0b00u;
    }

    uint pos_in_group = (2 * index) % (8 * sizeof(uint));
    arr[group_index] = TritSet::set(this->arr[group_index], pos_in_group, bit_value & 0b1u);
    arr[group_index] = TritSet::set(this->arr[group_index], pos_in_group + 1, bit_value >> 1u);
}

Trit TritSet::get(const std::size_t index) {
    if (index >= this->length)
        return Trit::Unknown;
    
    size_t group_index = (2 * index) / (8 * sizeof(uint));
    uint pos_in_group = (2 * index) % (8 * sizeof(uint));
    uint bit_value = (this->arr[group_index] >> pos_in_group) & 0b11u;
    switch (bit_value) {
        case 0b01:
            return Trit::True;
        case 0b10:
            return Trit::False;
        default:
            return Trit::Unknown;
    }
}

TritSet operator&=(const TritSet& ts) const {
    *this = *this & ts;
}

TritSet operator|=(const TritSet& ts) const {
    *this = *this | ts;
}


TritSet operator&(const TritSet& ts) const {
    std::size_t length = td::max(this->length, ts.length);
    std::size_t capacity = std::max(this->capacity, ts.capacity);
    TritSet tmp(capacity);
    for (std::size_t i = 0; i < length; i++)
        tmp.set(i, this->get(i) | ts2.get(i));
    return tmp;
}

TritSet operator|(const TritSet& ts) const {
    std::size_t length = td::max(this->length, ts.length);
    std::size_t capacity = std::max(this->capacity, ts.capacity);
    TritSet tmp(capacity);
    for (std::size_t i = 0; i < length; i++)
        tmp.set(i, this->get(i) | ts.get(i));
    return tmp;
}

TritSet TritSet::operator!(const TritSet& ts) const {
    TritSet tmp = TritSet(ts.capacity);
    for (std::size_t i = 0; i < ts.length; i++)
        tmp.set(i, !ts.get(i));
    return tmp;
}

const Trit TritSet::operator[](std::size_t index) const {
    return this->get(index);
}


TritSet::TritProxy TritSet::operator[](std::size_t index) {
    return TritProxy{*this, index};
}

TritSet::TritProxy& TritSet::TritProxy::operator=(Trit trit) {
    ts.set(idx, trit);
    return *this;
}

TritSet::TritProxy::TritProxy(TritSet& tritset, std::size_t index){
    return;
}
