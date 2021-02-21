#define CATCH_CONFIG_MAIN

#include "../src/database/database.h"
#include "../lib/catch2/catch_amalgamated.hpp"

TEST_CASE("Testing the catch2 stuff...")
{
    int temp = 0;
    REQUIRE(temp == 0);
}