
#include "./database/database.h"
#include "./datastructure/datastructure.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace database_std;
using namespace datastructure_std;
using namespace std;

// Person structure
struct temp
{
	int num;
	temp* next;
}; 

int main(int argc, char** argv)
{
	// DATA TO BE USED IN TESTING
	// int ss[16] = { 100001, 100002, 100003, 100004,
	// 	100005, 100006, 100007 };

	// int temp = 100001;

	int sos = 120000;

	string names[16] = { "Meldin", "Adila", "Seio" , "Dad",
		"Mom", "Brother", "Sister", "Cousin", "Sam", "Mike",
		"Veronica", "Jon", "Jannise", "Liz", "Isabella",
		"Victor" };

	string jobs[16] = { "Engineer", "Marketing", "IT" , "Retired",
		"Cleaning", "Bank", "Consultant", "Waiter", "LS Sales", "TV Sales",
		"Paper Sales", "Fighter", "Secretary", "Driver", "Racer",
		"Intern" };





	// TESTING NEW DATASTRUCTURE ADDELEMENT
	Datastructure dt;
	// dt.PrintDatabaseInOrder();

	// Adding the elements
	for (int i = 0; i < 16; i++)
	{
		cout << i << endl;
		dt.AddEntry(sos+i, names[i], jobs[i]);
		dt.AddEntry(sos+i, names[i], jobs[i]);
	}

	// Printing the elements
	dt.PrintDatabaseInOrder();

	for (int i = 0; i < 5; i++)
	{
		cout << "Occupation of " << sos+i << ": " << dt.GetOccupation(sos+i) << endl;
	}
	cout << "Occupation of " << 130000 << ": " << dt.GetOccupation(130000) << endl;

	// dt.RemoveNode(120001);

	// Printing the elements
	// dt.PrintDatabaseInOrder();





	/**
	 * 	WRITING AND READING TO THE FILES
	 */	

	// Database open;
	// open.WriteData();
	// open.ReadInData();

	return 0;
}