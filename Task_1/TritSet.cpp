#include "TritSet.h"

TritSet::TritSet(size_t numOfTrits) {
    this->capacity = (numOfTrits / 4) / sizeof(size_t) + 1;
    this->data = <uint*>malloc(ceil( 2*this->length / (8*sizeof(uint))));
}

void TritSet::capacity() {
     return this->capacity;
}

void TritSet::shrink() {
}

void TritSet::cardinality(Trit value) {
}

std::size_t TritSet::trim(std::size_t lastIndex) {
}

std::size_t TrisSet::length();
}

TritSet::~TritSet() {
    free(this->data);
}
