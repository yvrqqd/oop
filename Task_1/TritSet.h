#pragma once
#include "Trit.h"
typedef unsigned int uint;

class TritSet {
private:
    uint *arr;
    std::size_t length;
    std::size_t capacity;

    class TritProxy {
    private:
        TritSet& tritset;
        std::size_t pos;
    public:
        TritProxy(TritSet&, uint&, std::size_t)
        TritProxy& operator= (Trit);
        operator Trit();
    };

public:
    TritSet(std::size_t);
    TritSet(const TritSet&&);
    ~TritSet();

    void shrink();
    std::size_t trim(size_t);
    std::size_t length() const;
    std::size_t capacity() const;
    std::size_t cardinality(Trit) const;
    std::unordered_map<Trit, uint, std::hash<uint>> cardinality();

    void operator=(const TritSet&);
    TritSet operator&(const TritSet&) const;
    TritSet operator|(const TritSet&) const;
    TritSet operator!(const TritSet&) const;

    Trit operator[](std::size_t) const;
    TritProxy operator[](std::size_t);
};
