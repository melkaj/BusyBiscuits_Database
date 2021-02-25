// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// rwdata.cpp - RWData class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "../datastructure/datastructure.h"
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

	// Initializing filenames
	db1Filename = "/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt";
	db2Filename = "/home/mel/Desktop/BusyBiscuits_Database/src/db2.txt";

	string line;
	ifstream datafile(db1Filename);

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
 * RT: String
 * 
 * Getters for the filenames. The files are used for the handling of the data
 * 		One file is used for modifications. And then when its time to save the 
 *		data, the modifications are applied and all the data is stored on the
 * 		other file
 * 
 */

string RWData::Getdb1Filename()  { return db1Filename; } 
string RWData::Getdb2Filename()  { return db2Filename; } 



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Toggles to private variable 'fileNumber'. Meaning, the main file will be
 * 		switched to the other one 
 * 
 */
void RWData::ToggleMainFile()
{
	this->fileNumber += 1 % 2;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String, Bool
 * RT: Void
 * 
 * Writes given entries to the file. If bool is set to false, then the data
 * 		will be appended to the file. If its set to true, then the data will
 * 		overwrite the file
 * 
 */
void RWData::WriteData(string socialSecurity, string name, string occupation, bool isOverwrite)
{
	string line;
	ofstream datafile;

	string db1 = "/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt";
	string db2 = "/home/mel/Desktop/BusyBiscuits_Database/src/db2.txt";

	if 		(this->fileNumber == 1 && isOverwrite == false)	 datafile.open(db1, ios::app);
	else if (this->fileNumber == 2 && isOverwrite == false)	 datafile.open(db2, ios::app);
	else if (this->fileNumber == 1 && isOverwrite == true)	 datafile.open(db1, ios::out);
	else if (this->fileNumber == 2 && isOverwrite == true)	 datafile.open(db2, ios::out);
	else	cout << "Something went wrong in RWData::WriteData..." << endl;

	if (datafile.is_open())
	{
		datafile << socialSecurity << endl;
		datafile << name << endl;
		datafile << occupation << endl;
		datafile.close();
	} 
	else cout << "Unable to open file" << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Reads in the file and adds it to the datastructure
 * 
 */
void RWData::ReadInData(datastructure_std::Datastructure &datastructure)
{
	string line;
	ifstream datafile;

	// Opening the 'main' storage file
	if      (this->fileNumber == 1)	 datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db1.txt");
	else if (this->fileNumber == 2)  datafile.open("/home/mel/Desktop/BusyBiscuits_Database/src/db2.txt");
	else							 cout << "Something went wrong in RWData::ReadInData(datastructure)..." << endl;

	if (datafile.is_open())
	{
		int  count = 0;
		bool isName = false;
		string ss, nm, occ;

		while(getline(datafile, line))
		{
			/** 
			 * Stores the social security in the first IF stment and sets
			 * flag letting the loop know the next input will be the NAME.
			 * Name is recorded and flag is turned off. Then next input 
			 * will be the occupation. Once the loop has gone 3 times,
			 * the data is added to the datastructure 
			 */
			if (count < 3)
			{
				if (int(line[0]) > 47 && int(line[0]) < 59)  { ss = line;	isName = true; }
				else if (isName == true)  					 { nm = line;	isName = false; }
				else										 { occ = line; }
				count++;
			}
			if (count == 3)
			{
				cout << ss << '\t' << nm << '\t' << occ << endl;
				datastructure.AddEntry(ss, nm, occ);
				count = 0;
			}
		}
		datafile.close();
	}
	else cout << "Unable to open file (ReadInData(datastructure))" << endl;

	cout << "Data has been unloaded to the datastructure..." << endl;
}
