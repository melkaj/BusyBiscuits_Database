
#include "rwdata.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace rwdata_std;
using namespace std;



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Finding out which file holds the data and which will be used as the
 * 		dummy file
 * 
 */
RWData::RWData()
{
	cout << "Hello from the RWData constructor" << endl;

	string line;
	ifstream datafile("/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt");

	if (datafile.is_open())
	{
		getline(datafile, line);
		
		cout << "line: " << line << endl;					// delete later

		if (line == "/")	this->fileNumber = 2;
		else				this->fileNumber = 1;
	}
	else  cout << "Unable to open file..." << endl;

	cout << "filenumber: " << this->fileNumber << endl;		// delete later
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Deconstructor
 * 
 */
RWData::~RWData()
{
	cout << "Goodbye from RWData deconstructor, object is being destroyed..." << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Reads in the file and prints the data
 * 
 */
void RWData::ReadInData()
{
	string line;
	ifstream datafile;
	if      (this->fileNumber == 1)	 datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt");
	else if (this->fileNumber == 2)  datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db2.txt");
	else							 cout << "Something went wrong in RWData::ReadInData..." << endl;

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



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Writes to the file specific entries. Was used for testing in early development
 * 		Use AppendData() to actually append user data to the files
 * 
 */
void RWData::WriteData()
{
	string line;
	ofstream datafile;
	if 		(this->fileNumber == 1)	 datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt", ios::app);
	else if (this->fileNumber == 2)	 datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db2.txt", ios::app);
	else						 	 cout << "Something went wrong in RWData::WriteData..." << endl;

	if (datafile.is_open())
	{
		datafile << "123123" << endl;
		datafile << "Dwight Schrute" << endl;
		datafile << "Paper Salesman" << endl;
		datafile.close();
	} 
	else cout << "Unable to open file" << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String
 * RT: Void
 * 
 * Writes to the file specific entries. Was used for testing in early development
 * 		Use AppendData() to actually append user data to the files
 * 
 */
void RWData::AppendData(int socialSecurity, string name, string occupation)
{
	ofstream datafile;
	if 		(this->fileNumber == 1)	 datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt", ios::app);
	else if (this->fileNumber == 2)	 datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db2.txt", ios::app);
	else						     cout << "Something went wrong in RWData::AppendData..." << endl;

	if (datafile.is_open())
	{
		datafile << socialSecurity << endl;
		datafile << name << endl;
		datafile << occupation << endl;
		datafile.close();
	}
	else  cout << "Something went wrong in RWData::AppendData..." << endl;

}
