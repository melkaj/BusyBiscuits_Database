
#include "database.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace BT_std;
using namespace Database_std;
using namespace HashT_std;
using namespace std;

Database::Database()
{
	cout << "Hello from the database constructor" << endl;
}

Database::~Database()
{
	cout << "Goodbye from deconstructor, object is being destroyed..." << endl;
}

void Database::ReadInData()
{
	string line;
	ifstream datafile("/home/mel/Desktop/BusyBiscuits_Database/src/open.txt");

	if (datafile.is_open())
	{
		int count = 0;
		while(getline(datafile, line))
		{
			if (int(line[0]) > 47 && int(line[0]) < 59)	count++;
		}
		cout << "count: " << count << endl;
		datafile.close();
	}
	else cout << "Unable to open file" << endl;
}

void Database::WriteData()
{
	string line;
	ofstream datafile("/home/mel/Desktop/BusyBiscuits_Database/src/open.txt", ios::app);

	if (datafile.is_open())
	{
		datafile << "123123" << endl;
		datafile << "Dwight Scrute" << endl;
		datafile << "Paper Salesman" << endl;
	} 
	else cout << "Unable to open file" << endl;
	datafile.close();
}
