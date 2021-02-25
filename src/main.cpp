
#include "./datastructure/datastructure.h"
#include "./databasemanager/databasemanager.h"
#include "./rwdata/rwdata.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace databasemanager_std;
using namespace datastructure_std;
using namespace rwdata_std;
using namespace std;


int main(int argc, char** argv)
{
	// string names[16] = { "Meldin", "Adila", "Seio" , "Dad",
	// 	"Mom", "Brother", "Sister", "Cousin", "Sam", "Mike",
	// 	"Veronica", "Jon", "Jannise", "Liz", "Isabella",
	// 	"Victor" };

	// string jobs[16] = { "Engineer", "Marketing", "IT" , "Retired",
	// 	"Cleaning", "Bank", "Consultant", "Waiter", "LS Sales", "TV Sales",
	// 	"Paper Sales", "Fighter", "Secretary", "Driver", "Racer",
	// 	"Intern" };



	/**
	 * DATABASEMANAGER
	 * 
	 */
	DatabaseManager dbm;






	/**
	 * 	WRITING AND READING TO THE FILES
	 */	

	// RWData database;
	// database.WriteData();
	// database.ReadInData();





	/**
	 * EXPLORING UNORDERED MAPS
	 */
	// unordered_map<int, int> um = { {3,13}, {4,14} };
	// unordered_map<int, int>::const_iterator found = um.find(5);
	// if (found == um.end())	cout << "Didnt find anything" << endl;
	// else
	// {
	// 	cout << "first: " << found->first << endl;
	// 	cout << "second: " << found->second << endl;
	// }

	return 0;
}