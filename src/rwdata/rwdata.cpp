
#include "rwdata.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace rwdata_std;
using namespace std;

RWData::RWData()
{
	cout << "Hello from the RWData constructor" << endl;
}

RWData::~RWData()
{
	cout << "Goodbye from RWData deconstructor, object is being destroyed..." << endl;
}

void RWData::ReadInData()
{
	string line;
	ifstream datafile("/home/mel/Desktop/BusyBiscuits_Database/src/open.txt");

	if (datafile.is_open())
	{
		int count = 0;
		while(getline(datafile, line))
		{
			// Checking if the first character of the input is a number
			// signifying that a new entry has started
			if (int(line[0]) > 47 && int(line[0]) < 59)	count++;
			// cout << line << endl;
		}
		cout << "count: " << count << endl;
		datafile.close();
	}
	else cout << "Unable to open file" << endl;
}

void RWData::WriteData()
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
