#define CATCH_CONFIG_MAIN

#include "catch2.hpp"
#include "TritSet.h" 
#include "Trit.h"

TEST_CASE("Default", "[TritSets]") {
    TritSet set(1000);
    int allocLength = set.capacity();
    REQUIRE(allocLength >= (1000 * 2 / 8 / sizeof(uint)));

    set[1000000000] = Unknown;
    REQUIRE(allocLength == set.capacity());

    if (set[2000000000] == True) {}
    REQUIRE(allocLength == set.capacity());

    set[1000000000] = True;
    REQUIRE(allocLength < set.capacity());

    allocLength = set.capacity();
    set[1000000000] = Unknown;
    set[1000000] = False;

    set.shrink();
    REQUIRE(allocLength > set.capacity());
}


TEST_CASE("test shrink"){
    TritSet A(10);
    A.shrink();
    REQUIRE(A.capacity() == 0);
    A[0] = True;
    REQUIRE(A.capacity() == 1);
    A[50] = True;
    A.resize(200);
    A.shrink();
    REQUIRE(A.capacity()==51);
    A.shrink();
    REQUIRE(A.capacity()==51);
}

TEST_CASE("test trim"){
    TritSet B(100);
    B[10] = True;
    B[5] = False;
    B[4] = True;
    B.trim(5);
    bool A = (B[4] == True);
    REQUIRE(A);
    A = B[10] == Unknown;
    REQUIRE(A);
    A = B[5] == Unknown;
    REQUIRE(A);
    A = B[4] == True;
    REQUIRE(A);
    REQUIRE(B.capacity() == 5);
}

TEST_CASE("test operators"){
    TritSet A(1000);
    TritSet B(2000);
    TritSet C = A & B;
    REQUIRE(C.capacity() == B.capacity());
    A[1] = True;
    B[1] = False;
    REQUIRE((A & B).show_data()[0] == B.show_data()[0]);
    REQUIRE((A | B).show_data()[0] == A.show_data()[0]);
    REQUIRE((!A).show_data()[0] == B.show_data()[0]);
    A[0] = True; A[2] = True; A[3] = False;A[4] = False; A[5] = False;
    B[0] = Unknown; B[2] = True; B[3] = Unknown; B[4] = False; B[5] = True; B[6] = Unknown; B[7] = False; B[8] = True;
    C = A|B;
    REQUIRE((C).show_data()[0] == 67093);
    C = A&B;
    REQUIRE((C).show_data()[0] == 35480);
    TritSet D;
    TritSet E(3);
    E[0] = True; E[2] = False;
    TritSet G = E|D;
    REQUIRE(G.show_data()[0] == 1);
    G = E&D;
    REQUIRE(G.show_data()[0] == 32);
}

TEST_CASE("test cardinality"){
    TritSet A;
    A[5] = True;
    A[7] = False;
    int C = A.cardinality(True);
    REQUIRE(C == 1);
    C = A.cardinality(False);
    REQUIRE(C == 1);
    C = A.cardinality(Unknown);
    REQUIRE(C == 6);
    A[5] = False;
    A[9] = False;
    C = A.cardinality(True);
    REQUIRE(C == 0);
    C = A.cardinality(False);
    REQUIRE(C == 3);
    C = A.cardinality(Unknown);
    REQUIRE(C == 7);
}
