#define CATCH_CONFIG_MAIN

#include "../src/datastructure/datastructure.h"
#include "../lib/catch2/catch_amalgamated.hpp"

TEST_CASE("Initializing tests...")
{
    int temp = 0;
    REQUIRE(temp == 0);
}

TEST_CASE("Testing the Datastructure class...")
{
    int sos = 120000;

	string nums[16] = { "1", "2", "3" , "4",
		"5", "6", "7", "8", "9", "10",
		"11", "12", "13", "14", "15",
		"16" };

    datastructure_std::Datastructure ds;
    
    // Adding the elements
	for (int i = 0; i < 16; i++)
	{
		ds.AddElem(sos+i, nums[i], nums[i]);
	}

    SECTION("Getting occupation of certain entries")
    {
        REQUIRE(ds.GetOccupation(120000) == "1");
        REQUIRE(ds.GetOccupation(120004) == "5");
        REQUIRE(ds.GetOccupation(120007) == "8");
        REQUIRE(ds.GetOccupation(120023) == "Empty");
    }

}






