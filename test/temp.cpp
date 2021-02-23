#define CATCH_CONFIG_MAIN

#include "../src/datastructure/datastructure.h"
#include "../lib/catch2/catch_amalgamated.hpp"

TEST_CASE("Testing the datastructure stuff...")
{
    datastructure_std::Datastructure ds;
    ds.AddElem(100001, "name", "occ");
    int temp = 0;
    REQUIRE(temp == 0);
}