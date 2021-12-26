#include "TritSet.h"
#include "Trit.h"
#include <cmath>

typedef unsigned int uint;

TritSet::TritSet(const std::size_t numOfTrits) {
    length = 0;
    arr = new uint[ceil(2 * numOfTrits / (8 * sizeof(uint)))];
}

TritSet::TritSet(const TritSet &ts) {
    length = ts.length;
    arr = new uint[ceil(2 * ts.length / (8 * sizeof(uint)))];
    for (int i = 0; i < length - 1; i++)
        arr[i] = ts.arr[i];
}

TritSet::~TritSet() {
    delete[] arr;
}

std::size_t TritSet::capacity() const {
    return length;
}

int bit_by_pos(uint bit, std::size_t bitNumber) {
    return (bit & (1 << bitNumber)) >> bitNumber;
}

std::size_t TritSet::len() const {
    int last = 0;
    for (int i = 0; i < capacity() * 2; i += 2) {
        uint byte_index = ((i) / (8 * sizeof(uint)));
        uint bit_index = ((i) % (8 * sizeof(uint)));
        if (bit_by_pos(arr[byte_index], bit_index) == 1 || bit_by_pos(arr[byte_index], bit_index + 1) == 1) {
            last = i / 2;
        }
    }
    return ++last;
}

void TritSet::shrink() {
    int last = 0, is_not_empty = 0;
    for (int i = 0; i < capacity() * 2; i += 2) {
        std::size_t byte_index = ((i) / (8 * sizeof(uint)));
        std::size_t bit_index = ((i) % (8 * sizeof(uint)));
        if (bit_by_pos(arr[byte_index], bit_index) == 1 ||
            bit_by_pos(arr[byte_index], bit_index + 1) == 1) {
            last = i / 2;
            is_not_empty = 1;
        }
    }
    if (is_not_empty == 1)
        trim(last + 1);
    else
        trim(0);

}

std::size_t TritSet::trim(const size_t lastIndex) {
    TritSet Tmp_ts(lastIndex);
    Tmp_ts.arr = new uint[lastIndex * 2 / (8 * sizeof(uint))];
    int tmp = length != 0 ? 1 : 0;
    int shift = lastIndex * 2 % (8 * sizeof(uint)) == 0 ? 0 : 1;
    tmp += length * 2 / (8 * sizeof(uint));
    if (tmp > lastIndex * 2 / (8 * sizeof(uint)) + shift)
        tmp = lastIndex * 2 / (8 * sizeof(uint)) + shift;
    for (uint i = 0; i < (tmp); i++)
        Tmp_ts.arr[i] = arr[i];
    for (uint i = length * 2; i < lastIndex * 2; i++)
        Tmp_ts.arr[i / (sizeof(uint) * 8)] &= ~(1 << i % (sizeof(uint) * 8));
    arr = Tmp_ts.arr;
    length = Tmp_ts.length;
    return length;
}

std::size_t TritSet::cardinality(const Trit value) const {
    std::size_t count = 0;
    for (int i = 0; i < length; i++) {
        if (get(i) == value)
            count++;
    }
    if (value == Trit::Unknown) count += capacity() - len();
    return count;
}

std::unordered_map<Trit, std::size_t, std::hash<std::size_t> > TritSet::cardinality() const {
    std::unordered_map<Trit, std::size_t, std::hash<std::size_t> > tritMap = {
            {Trit::True,    0},
            {Trit::False,   0},
            {Trit::Unknown, 0}
    };
    tritMap[Trit::True] = this->cardinality(Trit::True);
    tritMap[Trit::False] = this->cardinality(Trit::False);
    tritMap[Trit::Unknown] = this->cardinality(Trit::Unknown);
    return tritMap;
}
TritSet& TritSet::operator=(const TritSet& ts) {
    if (ts.length == 0){
        arr = new uint[1];
        arr[0] = 0;
        return *this;
    }
    uint* prev_arr = arr;
    arr = new uint[ts.length * 2 / (8 * sizeof(uint))];
    int tmp = ts.length * 2 % 8 * sizeof(uint) == 0 ? 0 : 1;
    for (uint i = 0; i < (ts.length * 2 / (8 * sizeof(uint)) + tmp); i++) {
        this->arr[i] = ts.arr[i];
    }
    this->length = ts.length;
    delete[] prev_arr;
    return *this;
}


void TritSet::set(const std::size_t index, const Trit value) {
    if (index >= len() && value == Trit::Unknown)
        return;

    std::size_t group_index = 2 * index / (8 * sizeof(uint));
    if (group_index >= len())
        return;

    if (index + 1 > length)
        length = index + 1;

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
    uint bit_value_of_group = 0b00000000;
    bit_value_of_group |= bit_value << pos_in_group / 2;
    arr[group_index] = bit_value_of_group;
}

static Trit TritSet::get(const std::size_t index) const {
    std::size_t byte_index = ((index) / (8 * sizeof(uint)));
    std::size_t bit_index = ((index) % (8 * sizeof(uint)));
    if (bit_by_pos(arr[byte_index], bit_index) == 1) {
        return Trit::True;
    } else if (bit_by_pos(arr[byte_index], bit_index + 1) == 1) {
        return Trit::False;
    } else {
        return Trit::Unknown;
    }
}

TritSet operator&(const TritSet &ts1, const TritSet &ts2) {
    TritSet tmp = ts1;
    tmp &= ts2;
    return tmp;
}

TritSet operator|(const TritSet &ts1, const TritSet &ts2) {
    TritSet tmp = ts1;
    tmp |= ts2;
    return tmp;
}

void TritSet::operator&=(const TritSet &ts2) {
    std::size_t max_len = (length > ts2.length) ? length : ts2.length;
    TritSet tmp(max_len);

    for (std::size_t i = 0; i < max_len; i++) {
        Trit t1, t2;
        if (len() <= i) t1 = Trit::Unknown;
        else t1 = ts2.get(i);
        if (ts2.len() <= i) t2 = Trit::Unknown;
        else t2 = ts2.get(i);

        if (t1 == Trit::False || t2 == Trit::False) {
            tmp[i] = Trit::False;
        } else if (t1 == Trit::Unknown || t2 == Trit::Unknown) {
            tmp[i] = Trit::Unknown;
        } else {
            tmp[i] = Trit::True;
        }
    }
    *this = tmp;
}
void TritSet::operator!=(const TritSet &ts2) {
    std::size_t max_len = (length > ts2.length) ? length : ts2.length;
    TritSet tmp(max_len);

    for (std::size_t i = 0; i < max_len; i++) {
        Trit t1, t2;
        if (len() <= i) t1 = Trit::Unknown;
        else t1 = ts2.get(i);
        if (ts2.len() <= i) t2 = Trit::Unknown;
        else t2 = ts2.get(i);

        if (t1 == Trit::True && t2 == Trit::True) {
            tmp[i] = Trit::False;
        } else if (t1 == Trit::False && t2 == Trit::False) {
            tmp[i] = Trit::False;
        } else if (t1 == Trit::Unknown || t2 == Trit::Unknown) {
            tmp[i] = Trit::Unknown;
        } else {
            tmp[i] = Trit::True;
        }
    }
    *this = tmp;
}
void TritSet::operator|=(const TritSet &ts2) {
    std::size_t max_len = (length > ts2.length) ? length : ts2.length;
    TritSet tmp(max_len);

    for (std::size_t i = 0; i < max_len; i++) {
        Trit t1, t2;
        if (len() <= i) t1 = Trit::Unknown;
        else t1 = ts2.get(i);
        if (ts2.len() <= i) t2 = Trit::Unknown;
        else t2 = ts2.get(i);

        if (t1 == Trit::True || t2 == Trit::True) {
            tmp[i] = Trit::True;
        } else if (t1 == Trit::Unknown || t2 == Trit::Unknown) {
            tmp[i] = Trit::Unknown;
        } else {
            tmp[i] = Trit::False;
        }
    }
    *this = tmp;
}

const Trit TritSet::operator[](std::size_t index) const {
    return get(index);
}

TritSet::TritProxy::TritProxy() {
    index = 0;
}
TritSet::TritProxy Proxy;
TritSet::TritProxy &TritSet::operator[](std::size_t index) {
    Proxy.index = index;
    Proxy.last = this;
    return Proxy;
}
TritSet::TritProxy& TritSet::TritProxy::operator=(Trit value) {
    std::size_t bit_index = index * 2 / (8 * sizeof(uint));
    if (index >= last->capacity()) {
        if (value == Trit::True || value == Trit::False) {
            last->trim(index + 1);
        } else
            return *this;
    }
    if (value == Trit::False) {
        last->arr[bit_index] |= 1 << (index % 16 * 2 + 1);
    } else {
        last->arr[bit_index] &= ~(1 << (index % 16 * 2 + 1));
    }
    if (value == Trit::True) {
        last->arr[bit_index] |= 1 << (index % 16 * 2);
    } else {
        last->arr[bit_index] &= ~(1 << (index % 16 * 2));
    }
    return *this;
}
