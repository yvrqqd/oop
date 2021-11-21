#pragma once

typedef unsigned int uint;

class TritSet {
private:
    uint *arr;
    std::size_t capacity;
    std::size_t length;

public:
    TritSet(std::size_t capacity);

    std::size_t trim(size_t lastIndex);

    std::size_t length();

    std::size_t capacity();

    std::size_t cardinality(Trit value);

    std::unordered_map<Trit, uint, std::hash<uint>> cardinality() const;

    void shrink();

    TritSet operator&(TritSet& t) const;
    TritSet operator|(TritSet& t) const;
    TritSet operator!(TritSet& t) const;

    Trit operator[](std::size_t idx) const;
    TritProxy operator[](std::size_t idx);

    ~TritSet();
};
