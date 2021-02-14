
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "../hashtable/hashtable.h"
#include "../binarytree/binarytree.h"
#include "database.h"

using namespace Database_std;
using namespace HashT_std;
using namespace BT_std;
using namespace std;

Database::Database()
{
	cout << "Hello from the database constructor" << endl;
}

Database::~Database()
{

}

void Database::ReadInData()
{
	string line;
	ifstream datafile("./open.txt");

	if (datafile.is_open())
	{
		while(getline(datafile, line))
		{
			cout << line << endl;
		}
		datafile.close();
	}
}

void Database::WriteData()
{
	string line;
	ofstream datafile("./open.txt", ios::app);
	if (datafile.is_open())
	{
		datafile << "123123" << endl;
		datafile << "Dwight Scrute" << endl;
		datafile << "Paper Salesman" << endl;
	} 
	datafile.close();
}
