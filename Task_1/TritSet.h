#pragma once

typedef unsigned int uint;

class TritSet {
private:
    uint *arr;
    std::size_t length;
    std::size_t capacity;

public:
    TritSet(std::size_t capacity);
    TritSet(const TritSet&);
    ~TritSet();
    
    void shrink();
    std::size_t trim(size_t);
    std::size_t length() const;
    std::size_t capacity() const;
    std::size_t cardinality(Trit) const;
    std::unordered_map<Trit, uint, std::hash<uint>> cardinality();

    void operator=(const TritSet&);
    TritSet operator&(const TritSet& t) const;
    TritSet operator|(const TritSet& t) const;
    TritSet operator!(const TritSet& t) const;

    Trit operator[](std::size_t) const;
    TritProxy operator[](std::size_t);
};
