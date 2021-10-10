#pragma once

typedef unsigned int uint;

namespace tritset {

    enum class Trit {
        False = -1, Unknown, True
    };
    class TritProxy {
    private:

    public:
        TritProxy(tritset tritSet);
        bool operator==(Trit trit) const;
    };

    class TritSet {
    private:
        std::size_t length;
        std::size_t* data;
    public:
        TritSet(std::size_t i);
        std::size_t capacity();
        const Trit operator[](std::size_t idx) const;
        const Trit operator&(std::size_t idx) const;
        const Trit operator|(std::size_t idx) const;
        const Trit operator!(std::size_t idx) const;
        void shrink();

        void cardinality(Trit value);

        std::size_t trim(size_t lastIndex);

        std::size_t length();
    };
}
