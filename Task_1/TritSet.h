#pragma once
#include <vector>

enum class Trit : unsigned int {
    False,
    Unknown,
    True
};

class TritSet{
private:
    vector<unsigned int> arr;
public:
    void capacity();
    void shrink();
    void cardinality(Trit value);
    size_t trim(size_t lastIndex);
    size_t length();
};
