
#include "./datastructure/datastructure.h"
#include "./databasemanager/databasemanager.h"
#include "./rwdata/rwdata.h"
#include <fstream>
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
	dbm.RemoveEntry("123120");
	dbm.SaveData();



	/**
	 * TESTING DOUBLE GETLINE
	 */

	// string line;
	// int count = 0;
	// ifstream tempfile("/home/mel/Desktop/BusyBiscuits_Database/src/open.txt");

	// if (tempfile.is_open())
	// {
	// 	cout << "opened..." << endl;
	// 	while(!tempfile.eof())
	// 	{
	// 		if (count<110)
	// 		{
	// 			getline(tempfile, line);
	// 			cout << "line: " << line << endl;
	// 			count++;
	// 			// while (getline(tempfile, line) and count<3)
	// 			// {
	// 			// 	cout << "line: " << line << endl;
	// 			// 	count++;
	// 			// }
	// 		}
	// 		else  break;
	// 	}
	// }


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