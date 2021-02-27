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
    // SETUP
    string sos = "120000";

	string nums[16] = { "1", "2", "3" , "4",
		"5", "6", "7", "8", "9", "10",
		"11", "12", "13", "14", "15",
		"16" };
    string ss[16] = { "120000", "120001", "120002",
        "120003", "120004", "120005", "120006",
        "120007", "120008", "120009", "120010",
        "120011", "120012", "120013", "120014",
        "120015" };

    datastructure_std::Datastructure ds;
    
    // Adding the elements
	for (int i = 0; i < 16; i++)
	{
        if (i == 1)		ds.AddEntry("121000", nums[i], nums[i]);
        else            ds.AddEntry(ss[i], nums[i], nums[i]);
	}

    // ds.PrintDatabaseInOrder();

    SECTION("Getting occupation of certain entries...")
    {
        REQUIRE(ds.GetOccupation("120000") == "1");
        REQUIRE(ds.GetOccupation("120004") == "5");
        REQUIRE(ds.GetOccupation("120007") == "8");
        REQUIRE(ds.GetOccupation("120023") == "Empty");
    }

    SECTION("TESTING RemoveEntry methods...")
    {
        SECTION("Removing root node (but with only one child)...")
        {
            REQUIRE(ds.GetOccupation("120000") == "1");
            REQUIRE(ds.RemoveEntry("120000") == 100);
            REQUIRE(ds.GetOccupation("120000") == "Empty");
        }

        SECTION("Removing root node (but with two children)...")
        {
            // Adding a child to the left of the root
            ds.AddEntry("119996", "-1", "-1");
            REQUIRE(ds.GetOccupation("119996") == "-1");
            REQUIRE(ds.RemoveEntry("120000") == 100);
            REQUIRE(ds.GetOccupation("120000") == "Empty");
        }
        
        SECTION("Removing leaf node...")
        {
            REQUIRE(ds.GetOccupation("120015") == "16");
            REQUIRE(ds.RemoveEntry("120015") == 100);
            REQUIRE(ds.GetOccupation("120015") == "Empty");
        }

        SECTION("Removing parent node (node with one left child)...")
        {
            REQUIRE(ds.GetOccupation("121000") == "2");
            REQUIRE(ds.RemoveEntry("121000") == 100);
            REQUIRE(ds.GetOccupation("121000") == "Empty");
        }

        SECTION("Removing parent node (node with one right child)...")
        {
            REQUIRE(ds.GetOccupation("120004") == "5");
            REQUIRE(ds.RemoveEntry("120004") == 100);
            REQUIRE(ds.GetOccupation("120004") == "Empty");
        }

        SECTION("Removing node that does not exist...")
        {
            REQUIRE(ds.RemoveEntry("100000") == 102);
        }
    }


    SECTION("TESTING AddEntry method... ")
    {
        SECTION("Adding a new entry...")
        {
            REQUIRE(ds.AddEntry("100000", "New Entry", "New Entry"));
        }

        SECTION("Trying to add an existing entry...")
        {
            REQUIRE(ds.AddEntry("121000", "OVERWRITE", "OVERWRITE") == 101);
        }
    }

    SECTION("TESTING UpdateEntry method...")
    {
        SECTION("Updating exisiting entry...")
        {
            REQUIRE(ds.GetOccupation("120000") == "1");
            REQUIRE(ds.UpdateEntry("120000", "Meldin", "Engineer") == 100);
            REQUIRE(ds.GetOccupation("120000") == "Engineer");
        }

        SECTION("Updating entry that does not exist...")
        {
            ds.PrintDatabaseInOrder();
            REQUIRE(ds.GetOccupation("100000") == "Empty");
            REQUIRE(ds.UpdateEntry("100000", "UPDATED NAME", "UPDATED OCCU") == 102);
            REQUIRE(ds.GetOccupation("100000") == "Empty");
            ds.PrintDatabaseInOrder();
        }
    }

}
