// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// databasemanager.cpp - DatabaseManager class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "databasemanager.h"
#include <iostream>
// #include <string>
// #include <unordered_map>

using namespace databasemanager_std;
using namespace std;



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Constructor
 * 
 */
DatabaseManager::DatabaseManager()
{
    // Unloading file with data to the datastructure
    this->rwdata.ReadInData(this->database);

    // this->database.PrintDatabaseInOrder();
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Destructor
 * 
 */
DatabaseManager::~DatabaseManager()
{
    cout << "DatabaseManager destructor...\n" << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String, String, String
 * RT: Integer
 * 
 * Performing all the necessaary additions to the database and the file
 * 
 */
int DatabaseManager::AddEntry(string socialSecurity, string name, string occupation)
{
    int response = this->database.AddEntry(socialSecurity, name, occupation);

    if (response == 100)  this->rwdata.WriteData(socialSecurity, name, occupation, false);

    return response;    
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String, String, String
 * RT: Integer
 * 
 * Performing all the necessaary additions to the database and the file
 * 
 */
int DatabaseManager::UpdateEntry(string socialSecurity, string name, string occupation)
{
    int response = this->database.UpdateEntry(socialSecurity, name, occupation);

    if (response == 100) 
    {
        this->rwdata.WriteData(socialSecurity, name, occupation, false);
        
        // Setting up removal of original entry from the file
        unordered_map<string, int>::const_iterator found = this->mapOfIgnoredEntires.find(socialSecurity);
        if (found == this->mapOfIgnoredEntires.end())      this->mapOfIgnoredEntires[socialSecurity] = 1;
        else                                               this->mapOfIgnoredEntires[socialSecurity]++;
    }
        
    return response;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String
 * RT: Integer
 * 
 * Removing the entry from the datastructure and the database. Remove from
 *      database is trivial as its just a function call. More on the use 
 *      of the unordered_map can be found in the SAVE function
 */
int DatabaseManager::RemoveEntry(string socialSecurity)
{
    int response = this->database.RemoveEntry(socialSecurity);

    if (response == 100)
    {
        this->database.RemoveEntry(socialSecurity);

        // Setting up removal from the file
        unordered_map<string, int>::const_iterator found = this->mapOfIgnoredEntires.find(socialSecurity);
        if (found == this->mapOfIgnoredEntires.end())      this->mapOfIgnoredEntires[socialSecurity] = 1;
        else                                               this->mapOfIgnoredEntires[socialSecurity]++;
    }

    return response;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String
 * RT: None
 * 
 * Restructuring the file so that the data in the file is most updated
 * 
 */
void DatabaseManager::SaveData()
{
    this->rwdata.SaveData(mapOfIgnoredEntires);
    mapOfIgnoredEntires.clear();

    string log = "\t| SAVEDATA |";
    this->database.Log(log);
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Calls the datastructure to print the current data
 * 
 */
void DatabaseManager::PrintDataInOrder()
{
    this->database.PrintDatabaseInOrder();
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String, String, String, String
 * RT: Void
 * 
 * Executes the right call based on the given command. Logs the responses
 *      (Used for ADD and UPDATE)
 * 
 */
void DatabaseManager::ExecuteCrudOper(string command, string socialSecurity, string name, string occupation)
{
    if (command == "add")
    {
        int response = AddEntry(socialSecurity, name, occupation);
        if      (response == 100)  cout << "Entry was entered in the database" << endl;
        else if (response == 101)  cout << "Database already has an entry with social security (" << socialSecurity << ")" << endl;
        else                       cout << "Something went wrong" << endl;

        string log = to_string(response) + "\tADD\t\t| " + socialSecurity + " |\t| " + name + " |\t| " + occupation + " |";
        this->database.Log(log);
    }
    else if (command == "update")
    {
        int response = UpdateEntry(socialSecurity, name, occupation);
        if      (response == 100)  cout << "Entry with social security (" << socialSecurity << ") was updated" << endl;
        else if (response == 102)  cout << "Entry with social security (" << socialSecurity << ") does not exist" << endl;
        else                       cout << "Something went wrong" << endl;

        string log = to_string(response) + "\tUPDATE\t\t| " + socialSecurity + " |\t| " + name + " |\t| " + occupation + " |";
        this->database.Log(log);
    }
    else                           cout << "Something went wrong" << endl; 
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String, String, String, String
 * RT: Void
 * 
 * Executes the right call based on the given command. Logs the responses
 *      (Used for REMOVE and FIND)
 * 
 */
void DatabaseManager::ExecuteCrudOper(string command, string socialSecurity)
{
    if (command == "remove")    
    {
        int response = RemoveEntry(socialSecurity);
        if      (response == 100)  cout << "Entry with social security (" << socialSecurity << ") was removed" << endl;
        else if (response == 102)  cout << "Entry with social security (" << socialSecurity << ") does not exist" << endl;
        else                       cout << "Something went wrong" << endl;

        string log = to_string(response) + "\tREMOVE\t\t| " + socialSecurity + " |";
        this->database.Log(log);
    }
    else if (command == "find") 
    {
        string* response = this->database.GetEntry(socialSecurity);

        if (*(response) == "000000")
        {
            cout << "Entry with social security (" << socialSecurity << ") does not exist" << endl;

            string log = "102\tFIND\t\t| " + socialSecurity + " |";
            this->database.Log(log);
        }
        else
        {
            cout << "\tName: " << *(response + 1) << endl;
            cout << "\tSS: " << *(response) << endl;
            cout << "\tOccupation: " << *(response + 2) << endl;
            cout << "\t______________________________________________________________\n" << endl;

            string log = "100\tUPDATE\t\t| " + *(response) + " |\t| " + *(response+1) + " |\t| " + *(response+2) + " |";
            this->database.Log(log);
        }
    }
    else  cout << "Something went wrong" << endl;
}
