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
        if (i == 1)		ds.AddElem(121000, nums[i], nums[i]);
        else            ds.AddElem(sos+i, nums[i], nums[i]);
	}

    // ds.PrintDatabaseInOrder();

    SECTION("Getting occupation of certain entries...")
    {
        REQUIRE(ds.GetOccupation(120000) == "1");
        REQUIRE(ds.GetOccupation(120004) == "5");
        REQUIRE(ds.GetOccupation(120007) == "8");
        REQUIRE(ds.GetOccupation(120023) == "Empty");
    }

    SECTION("TESTING RemoveNode methods...")
    {
        SECTION("Removing root node (but with only one child)...")
        {
            REQUIRE(ds.GetOccupation(120000) == "1");
            ds.RemoveNode(120000);
            REQUIRE(ds.GetOccupation(120000) == "Empty");
        }

        SECTION("Removing root node (but with two children)...")
        {
            ds.AddElem(119996, "-1", "-1");
            REQUIRE(ds.GetOccupation(119996) == "-1");
            ds.RemoveNode(120000);
            REQUIRE(ds.GetOccupation(120000) == "Empty");
        }
        
        SECTION("Removing leaf node...")
        {
            REQUIRE(ds.GetOccupation(120015) == "16");
            ds.RemoveNode(120015);
            REQUIRE(ds.GetOccupation(120015) == "Empty");
        }

        SECTION("Removing parent node (node with one left child)...")
        {
            REQUIRE(ds.GetOccupation(121000) == "2");
            ds.RemoveNode(121000);
            REQUIRE(ds.GetOccupation(121000) == "Empty");
        }

        SECTION("Removing parent node (node with one right child)...")
        {
            REQUIRE(ds.GetOccupation(120004) == "5");
            ds.RemoveNode(120004);
            REQUIRE(ds.GetOccupation(120004) == "Empty");
        }

        SECTION("Removing node that does not exist...")
        {
            REQUIRE(ds.GetOccupation(100000) == "Empty");
            ds.RemoveNode(100000);
            REQUIRE(ds.GetOccupation(100000) == "Empty");
        }
    }

    SECTION("Overwriting entries...")
    {
        REQUIRE(ds.GetOccupation(120000) == "1");
        ds.AddElem(120000, "Meldin", "Engineer");
        REQUIRE(ds.GetOccupation(120000) == "Engineer");
        ds.RemoveNode(120000);
        REQUIRE(ds.GetOccupation(120000) == "Empty");
    }

    SECTION("Overwriting entries...")
    {
        REQUIRE(ds.GetOccupation(120000) == "1");
        ds.AddElem(120000, "Meldin", "Engineer");
        REQUIRE(ds.GetOccupation(120000) == "Engineer");
        ds.RemoveNode(120000);
        REQUIRE(ds.GetOccupation(120000) == "Empty");
    }
}






