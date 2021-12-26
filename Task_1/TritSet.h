#pragma once

#include "Trit.h"

typedef unsigned int uint;

class TritSet {
private:
    uint *arr;
    std::size_t length;
    std::size_t capacity;
public:
    class TritProxy{
        friend class TritSet;
    private:
        uint index;
        TritSet *last;
    public:
        TritProxy();
        TritProxy& operator=(Trit value);
        bool operator==(Trit A);
    };
    
    TritSet(const std::size_t);
    TritSet(const TritSet&);
    ~TritSet();

    void shrink();
    std::size_t trim(const std::size_t);
    std::size_t length() const;
    std::size_t capacity() const;
    std::size_t cardinality(Trit) const;
    std::unordered_map<const Trit, const std::size_t, std::hash<std::size_t>> cardinality() const;

    void set(const std::size_t, Trit);
    Trit get(const std::size_t) const;
    
    const Trit operator[](const std::size_t) const;
    TritProxy &operator[](const std::size_t);
};
TritSet operator&=(const TritSet&);
TritSet operator|=(const TritSet&);
TritSet operator&(const TritSet&, const TritSet&);
TritSet operator|(const TritSet&, const TritSet&);
TritSet operator!();
