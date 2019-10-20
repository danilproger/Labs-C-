/*
//
// Created by danil on 16.10.2019.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tritset.h"

TEST_CASE("Test_constructor") {
    tritset set1(64);
    tritset set2(67);
    REQUIRE(set1.getSize() == 64);
    REQUIRE(set1.getCapacity() == 4);
    for (int i = 0; i < set1.getCapacity(); i++) {
        REQUIRE(set1.getPTrits()[i] == 0);
    }
    REQUIRE(set2.getSize() == 67);
    REQUIRE(set2.getCapacity() == 5);
    for (int i = 0; i < set2.getCapacity(); i++) {
        REQUIRE(set2.getPTrits()[i] == 0);
    }
}

TEST_CASE("Test_destructor") {
    tritset set1(105);
    REQUIRE(set1.getSize() == 105);
    REQUIRE(set1.getCapacity() == 7);
    ~set1;
    REQUIRE(set1.getPTrits() == nullptr);
}

TEST_CASE("Test_constructor_copy") {
    tritset set1(67);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = True;
        else set1[i] = False;
    }
    tritset set2 = set1;
    REQUIRE(set1.getSize() == set2.getSize());
    REQUIRE(set1.getCapacity() == set2.getCapacity());
    REQUIRE(set1.getPTrits() != set2.getPTrits());
    for (int i = 0; i < set1.getSize(); i++) {
        REQUIRE(set1[i] == set2[i]);
    }
}

TEST_CASE ("Test_constructor_move") {
    tritset set1(130);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = True;
        else set1[i] = False;
    }
    uint *ptr = set1.getPTrits();
    tritset set2 = std::move(set1);
    REQUIRE(set1.getSize() == set2.getSize());
    REQUIRE(set1.getCapacity() == set2.getCapacity());
    REQUIRE(set1.getPTrits() == nullptr);
    REQUIRE(set2.getPTrits() == ptr);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) REQUIRE(set2[i] == True);
        else
            REQUIRE(set2[i] == False);
    }
}

TEST_CASE("Test_operator_=") {
    tritset set1(67);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = True;
        else set1[i] = False;
    }
    tritset set2(45);
    REQUIRE(set2.getSize() == 45);
    REQUIRE(set2.getCapacity() == 3);
    set2 = set1;
    REQUIRE(set1.getSize() == set2.getSize());
    REQUIRE(set1.getCapacity() == set2.getCapacity());
    REQUIRE(set1.getPTrits() != set2.getPTrits());
    for (int i = 0; i < set1.getSize(); i++) {
        REQUIRE(set1[i] == set2[i]);
    }
}

TEST_CASE("Test_operator_=&&") {
    tritset set1(130);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = True;
        else set1[i] = False;
    }
    uint *ptr = set1.getPTrits();
    tritset set2(1000);
    REQUIRE(set2.getSize() == 1000);
    REQUIRE(set2.getCapacity() == 63);
    set2 = std::move(set1);
    REQUIRE(set1.getSize() == set2.getSize());
    REQUIRE(set1.getCapacity() == set2.getCapacity());
    REQUIRE(set1.getPTrits() == nullptr);
    REQUIRE(set2.getPTrits() == ptr);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) REQUIRE(set2[i] == True);
        else
            REQUIRE(set2[i] == False);
    }
}

TEST_CASE("Test_operator_[ ]=") {
    tritset set1(85);
    set1[0] = True;
    REQUIRE(set1[0] == True);
    set1[10] = False;
    REQUIRE(set1[10] == False);
    set1[83] = set1[2000];
    REQUIRE(set1[83] == Unknown);
    set1[84] = set1[0];
    REQUIRE(set1[84] == True);
}

TEST_CASE("Test_operator [ ]") {
    tritset set1(2001);
    REQUIRE(set1.getSize() == 2001);
    REQUIRE(set1.getCapacity() == 126);
    set1[0] = True;
    REQUIRE(set1[0] == True);
    set1[100000000] = Unknown;
    REQUIRE(set1.getSize() == 2001);
    REQUIRE(set1.getCapacity() == 126);
    set1[3012] = True;
    REQUIRE(set1.getSize() == 3013);
    REQUIRE(set1.getCapacity() == 189);
    REQUIRE(set1[100000000] == Unknown);
    set1[1] = set1[0];
    REQUIRE(set1[0] == set1[1]);
}

TEST_CASE("Test_operator_&") {
    tritset set1(25);
    tritset set2(1000);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = False;
        else set1[i] = True;
    }

    for (int i = 0; i < set2.getSize(); i++) {
        if (i % 2 != 0) set2[i] = False;
        else set2[i] = True;
    }
    tritset set3 = set1 & set2;

    REQUIRE(set3.getSize() == set2.getSize());
    REQUIRE(set3.getCapacity() == set2.getCapacity());

    for (int i = 0; i < set3.getSize(); i++) {
        if (i < set1.getSize()) REQUIRE(set3[i] == False);
        else {
            if (i % 2 != 0) REQUIRE(set3[i] == False);
            else
                REQUIRE(set3[i] == Unknown);
        }
    }
}

TEST_CASE("Test_operator_|") {
    tritset set1(25);
    tritset set2(1000);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = False;
        else set1[i] = True;
    }

    for (int i = 0; i < set2.getSize(); i++) {
        if (i % 2 != 0) set2[i] = False;
        else set2[i] = True;
    }
    tritset set3 = set1 | set2;

    REQUIRE(set3.getSize() == set2.getSize());
    REQUIRE(set3.getCapacity() == set2.getCapacity());

    for (int i = 0; i < set3.getSize(); i++) {
        if (i < set1.getSize()) REQUIRE(set3[i] == True);
        else {
            if (i % 2 == 0) REQUIRE(set3[i] == True);
            else
                REQUIRE(set3[i] == Unknown);
        }
    }
}

TEST_CASE("Test_operator_~") {
    tritset set1(79);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = False;
        else set1[i] = True;
    }
    tritset set2 = ~set1;
    REQUIRE(set1.getSize() == set2.getSize());
    REQUIRE(set1.getCapacity() == set2.getCapacity());
    for (int i = 0; i < set2.getSize(); i++) {
        if (i % 2 == 0) REQUIRE(set2[i] == True);
        else
            REQUIRE((set2[i]) == False);
    }
}


TEST_CASE("Test_function_shrink") {
    tritset set1(25);
    set1[2000] = True;
    REQUIRE(set1[2000] == True);
    REQUIRE(set1.getSize() == 2001);
    REQUIRE(set1.getCapacity() == 126);
    set1[2000] = Unknown;
    REQUIRE(set1[2000] == Unknown);
    REQUIRE(set1[0] == True);
    REQUIRE(set1.getSize() == 2001);
    REQUIRE(set1.getCapacity() == 126);
    set1.shrink();
    REQUIRE(set1[0] == True);
    REQUIRE(set1.getSize() == 1);
    REQUIRE(set1.getCapacity() == 1);
}

TEST_CASE("Test_function_trim") {
    tritset set1(65);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = False;
        else set1[i] = True;
    }
    set1.trim(90);
    REQUIRE(set1.getSize() == 65);
    REQUIRE(set1.getCapacity() == 5);
    set1.trim(35);
    REQUIRE(set1.getSize() == 36);
    REQUIRE(set1.getCapacity() == 3);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) REQUIRE(set1[i] == False);
        else
            REQUIRE(set1[i] == True);
    }
}

TEST_CASE("Test_function_cardinality") {
    tritset set1(97);
    for (int i = 0; i < set1.getSize(); i++) {
        if (i % 2 == 0) set1[i] = False;
        else set1[i] = True;
    }
    set1[2] = Unknown;
    set1[9] = Unknown;
    set1[29] = Unknown;
    set1[36] = Unknown;
    set1[48] = Unknown;
    set1[96] = Unknown;
    REQUIRE(set1.cardinality(Unknown) == 6);
    REQUIRE(set1.cardinality(False) == set1.getSize() - 48 - 4);
    REQUIRE(set1.cardinality(True) == set1.getSize() - 49 - 2);
}*/
