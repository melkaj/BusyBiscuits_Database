
#include "./datastructure/datastructure.h"
#include "./rwdata/rwdata.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace datastructure_std;
using namespace rwdata_std;
using namespace std;


int main(int argc, char** argv)
{
	// DATA TO BE USED IN TESTING
	// int ss[16] = { 100001, 100002, 100003, 100004,
	// 	100005, 100006, 100007 };

	// int temp = 100001;

	// int sos = 120000;

	// string names[16] = { "Meldin", "Adila", "Seio" , "Dad",
	// 	"Mom", "Brother", "Sister", "Cousin", "Sam", "Mike",
	// 	"Veronica", "Jon", "Jannise", "Liz", "Isabella",
	// 	"Victor" };

	// string jobs[16] = { "Engineer", "Marketing", "IT" , "Retired",
	// 	"Cleaning", "Bank", "Consultant", "Waiter", "LS Sales", "TV Sales",
	// 	"Paper Sales", "Fighter", "Secretary", "Driver", "Racer",
	// 	"Intern" };





	// // TESTING NEW DATASTRUCTURE ADDELEMENT
	// Datastructure dt;
	// // dt.PrintDatabaseInOrder();

	// // Adding the elements
	// for (int i = 0; i < 16; i++)
	// {
	// 	cout << i << endl;
	// 	dt.AddEntry(sos+i, names[i], jobs[i]);
	// 	dt.AddEntry(sos+i, names[i], jobs[i]);
	// }

	// // Printing the elements
	// dt.PrintDatabaseInOrder();

	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "Occupation of " << sos+i << ": " << dt.GetOccupation(sos+i) << endl;
	// }
	// cout << "Occupation of " << 130000 << ": " << dt.GetOccupation(130000) << endl;

	// // dt.RemoveNode(120001);

	// // Printing the elements
	// // dt.PrintDatabaseInOrder();





	/**
	 * 	WRITING AND READING TO THE FILES
	 */	

	RWData database;
	database.WriteData();
	database.ReadInData();





	/**
	 * EXPLORING UNORDERED MAPS
	 */
	unordered_map<int, int> um = { {3,13}, {4,14} };
	unordered_map<int, int>::const_iterator found = um.find(5);
	if (found == um.end())	cout << "Didnt find anything" << endl;
	else
	{
		cout << "first: " << found->first << endl;
		cout << "second: " << found->second << endl;
	}

	return 0;
}