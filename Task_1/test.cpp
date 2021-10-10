#define CATCH_CONFIG_MAIN

#include "catch2.hpp"
#include "TritSet.h"

using namespace std;
using namespace tritset;

TEST_CASE("no allocation for unknown trits", "[capacity]") {
    TritSet set(1000);
    int allocLength = set.capacity();
    REQUIRE(allocLength >= (1000 * 2 / 8 / sizeof(uint)));
    // 1000*2 - min bits count
    // 1000*2 / 8 - min bytes count
    // 1000*2 / 8 / sizeof(uint) - min uint[] size

    set[1'000'000'000] = Unknown;
    REQUIRE(allocLength == set.capacity());

    // false, but no exception or memory allocation
    if (set[2'000'000'000] == True) {}
    REQUIRE(allocLength == set.capacity());

    //выделение памяти
    set[1'000'000'000] = True;
    REQUIRE(allocLength < set.capacity());

    //no memory operations
    allocLength = set.capacity();
    set[1'000'000'000] = Unknown;
    set[1'000'000] = False;
    REQUIRE(allocLength == set.capacity());

    set.shrink();
    REQUIRE(allocLength > set.capacity());

}
