#pragma once
#include<iostream>
#include<unordered_map>
#include "Trit.h"

typedef unsigned int uint;

class TritSet {
private:
    uint *arr;
    std::size_t length;
public:
    class TritProxy{
        friend class TritSet;
    private:
        uint index;
        TritSet *last;
    public:
        TritProxy();
        TritProxy& operator=(Trit value);
    };

    TritSet(const std::size_t);
    TritSet(const TritSet&);
    ~TritSet();

    void shrink();
    std::size_t trim(const std::size_t);
    std::size_t len() const;
    std::size_t capacity() const;
    std::size_t cardinality(Trit) const;
    std::unordered_map<Trit, std::size_t, std::hash<std::size_t>> cardinality() const;

    void set(const std::size_t, const Trit);
    Trit get(const std::size_t) const;

    TritSet& operator=(const TritSet&);
    void operator&=(const TritSet&);
    void operator|=(const TritSet&);
    void operator!=(const TritSet&);
    const Trit operator[](const std::size_t) const;
    TritProxy &operator[](const std::size_t);
};
TritSet operator&(const TritSet&, const TritSet&);
TritSet operator|(const TritSet&, const TritSet&);
