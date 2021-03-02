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
	// Initializing filenames
	this->db1FileName = "db1.txt";
	this->db2FileName = "db2.txt";

	string   line;
	ifstream datafile(this->db1FileName);

	// Checks if one of the files exists
	if (datafile.is_open())
	{
		getline(datafile, line);
		
		if (line == "/")	this->fileNumber = 1;
		else				this->fileNumber = 0;

		datafile.close();
	}
	else  
	{
		// Checks if the other file exists
		datafile.open(this->db2FileName);
		if (datafile.is_open())
		{
			getline(datafile, line);
			
			if (line == "/")	this->fileNumber = 1;
			else				this->fileNumber = 0;

			datafile.close();			
		}
		else
		{
			// Creates both files
			ofstream mainfile("db1.txt", ios::out);
			ofstream secondaryfile("db2.txt", ios::out);

			if (secondaryfile.is_open() && mainfile.is_open())  
			{  
				secondaryfile << "/" << endl;  
				datafile.close(); 

				this->fileNumber = 0;
			}
			else
			{
				string error = "\tUnable to open file in RWData::RWData";
				cout << error << endl;  Log(error);
			}
		}
	}
}



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
	this->fileNumber = (this->fileNumber + 1) % 2;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String, Bool
 * RT: Void
 * 
 * 
 * Writes given entries to the file. If bool is set to false, then the data
 * 		will be appended to the file. If its set to true, then the data will
 * 		overwrite the file
 * 
 */
void RWData::WriteData(string socialSecurity, string name, string occupation, bool isOverwrite)
{
	string   line;
	ofstream datafile;

	string   db1 = this->db1FileName;
	string   db2 = this->db2FileName;

	// Loding the main file that will be written to
	if 		(this->fileNumber == 0 && isOverwrite == false)	 datafile.open(db1, ios::app);
	else if (this->fileNumber == 1 && isOverwrite == false)	 datafile.open(db2, ios::app);
	else if (this->fileNumber == 0 && isOverwrite == true)	 datafile.open(db1, ios::out);
	else if (this->fileNumber == 1 && isOverwrite == true)	 datafile.open(db2, ios::out);
	else
	{
		string error = "Something went wrong in RWDAta::WriteData";
		cout << error << endl;  Log(error);
	}

	if (datafile.is_open())
	{
		datafile << socialSecurity << endl;
		datafile << name << endl;
		datafile << occupation << endl;
		datafile.close();
	} 
	else
	{
		string error = "Unable to open file in RWData::WriteData";
		cout << error << endl;  Log(error);
	}
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
	string   line;
	ifstream datafile;

	// Opening the 'main' storage file
	if      (this->fileNumber == 0)	 datafile.open(this->db1FileName);
	else if (this->fileNumber == 1)  datafile.open(this->db2FileName);
	else
	{
		string error = "Something went wrong in RWData::ReadInData(datastructure)";
		cout << error << endl;  Log(error);
	}

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
				if 	    (int(line[0]) > 47 && int(line[0]) < 59)  { ss = line;	isName = true; }
				else if (isName == true)  					 	  { nm = line;	isName = false; }
				else										      { occ = line; }
				count++;
			}
			if (count == 3)
			{
				datastructure.AddEntry(ss, nm, occ);
				count = 0;
			}
		}
		datafile.close();
	}
	else
	{
		string error = "Unable to open file in ReadInData(datastructure)";
		cout << error << endl;  Log(error); 
	}

	string log = "Data has been unloaded to the datastructure..."; 
	Log(log);
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void	
 * 
 * Applys the modifications on the current main data file and putting it
 * 		to the other file. Then toggling the main file 
 * 
 */
void RWData::SaveData(unordered_map<string, int> &ignoredEntry)
{
	string   line;
	ifstream dataFileMain;		// The file with all the data and user modifications
	ofstream dataFileNewMain;	// Where all the updated data will go
	int  	 count = 0;
	string   entry[3];

	// Opening the main file as a read and the other as a write
	if      (this->fileNumber == 0)	 { dataFileMain.open(this->db1FileName); dataFileNewMain.open(this->db2FileName); }
	else if (this->fileNumber == 1)  { dataFileMain.open(this->db2FileName); dataFileNewMain.open(this->db1FileName); }
	else
	{
		string error = "Something went wrong in RWData::SaveData()";
		cout << error << endl; Log(error);
	}

	if (dataFileMain.is_open() && dataFileNewMain.is_open())
	{
		while (!dataFileMain.eof())
		{
			if (count < 3)
			{
				getline(dataFileMain, line);
				entry[count] = line;
				count++;
			}
			else if (ignoredEntry.count(entry[0]) > 0)		// element is to be ignored
			{
				// Decrementing the hashvalue and erasing its hash if it equals to zero
				if (--ignoredEntry[entry[0]] == 0)  ignoredEntry.erase(entry[0]);
				count = 0;
			}
			else
			{
				dataFileNewMain << entry[0] << endl;
				dataFileNewMain << entry[1] << endl;
				dataFileNewMain << entry[2] << endl;
				count = 0;
			}
		}
		dataFileMain.close(); 
		dataFileNewMain.close();
	}
	else  
	{
		string error = "Unable to open file in RWData::SaveData()";
		cout << error << endl;  Log(error);
	}

	// Delete contents on original main file	(MAYBE PLACE IN A NEW FUNCTION)
	if      (this->fileNumber == 0)	 { dataFileNewMain.open(this->db1FileName); }
	else if (this->fileNumber == 1)  { dataFileNewMain.open(this->db2FileName); }
	else
	{
		string error = "Something went wrong in RWData::SaveData()";
		cout << error << endl;  Log(error);
	}

	if (dataFileNewMain.is_open())  { dataFileNewMain << "/" << endl;  dataFileNewMain.close(); }

	this->ToggleMainFile();
}