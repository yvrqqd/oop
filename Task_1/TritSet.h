#pragma once

typedef unsigned int uint;

namespace tritset {
    enum class Trit {
        False = -1, Unknown, True
    };

    class TritProxy {
    public:
        TritProxy(tritset tritSet);
        bool operator==(Trit trit) const;
    };

    class TritSet {
    private:
        std::size_t length;
        std::size_t *data;
    public:
        TritSet(std::size_t x);

        std::size_t trim(size_t lastIndex);

        std::size_t length();

        std::size_t capacity();

        srd::size_t cardinality(Trit value);

        std::unordered_map<Trit, int, std::hash<int>> cardinality();

        void shrink();

        const Trit operator[](std::size_t idx) const;

        const Trit operator&(Trit a, Trit b) const;

        const Trit operator|(Trit a, Trit b) const;

        const Trit operator!(Trit a) const;
    };
}
