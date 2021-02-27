// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// databasemanager.cpp - DatabaseManager class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "databasemanager.h"
#include <iostream>
#include <string>
#include <unordered_map>

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
    cout << "DatabaseManager constructor..." << endl;

    // Unloading file with data to the datastructure
    this->rwdata.ReadInData(this->database);

    this->database.PrintDatabaseInOrder();

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


    // First we add the entry to the datastructure and then we append
    //      the entry to the data file
    // try
    // {
    //     this->database.AddEntry(socialSecurity, name, occupation);
    // }
    // catch(int e)
    // {
    //     switch (e)
    //     {
    //     case 101:  cout << "Entry with social security (" << socialSecurity << ") already exists. You can update the entry if youd like" << endl; 
    //         break;
        
    //     default:   cout << "Something went wrong in DatabaseManager::UpdateEntry" << endl; 
    //         break;
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
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
    

    // try
    // {
    //     this->database.UpdateEntry(socialSecurity, name, occupation);
    //     this->rwdata.WriteData    (socialSecurity, name, occupation, false);
        
    //     // Setting up removal of original entry from the file
    //     unordered_map<string, int>::const_iterator found = this->mapOfIgnoredEntires.find(socialSecurity);
    //     if (found == this->mapOfIgnoredEntires.end())   this->mapOfIgnoredEntires[socialSecurity] = 1;
    //     else                                            this->mapOfIgnoredEntires[socialSecurity]++;

    // }
    // catch(int e)
    // {
    //     switch (e)
    //     {
    //     case 102:  cout << "Entry with social security (" << socialSecurity << ") was not found" << endl; 
    //         break;
        
    //     default:   cout << "Something went wrong in DatabaseManager::UpdateEntry" << endl; 
    //         break;
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
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


    // try 
    // {
    //     // Removing desired entry from the datastructure
    //     this->database.RemoveEntry(socialSecurity);

    //     // Setting up removal from the file
    //     unordered_map<string, int>::const_iterator found = this->mapOfIgnoredEntires.find(socialSecurity);
    //     if (found == this->mapOfIgnoredEntires.end())   this->mapOfIgnoredEntires[socialSecurity] = 1;
    //     else                                            this->mapOfIgnoredEntires[socialSecurity]++;
    // }
    // catch (int e)
    // {
    //     switch (e)
    //     {
    //     case 102:  cout << "Entry with social security (" << socialSecurity << ") was not found" << endl; 
    //         break;
        
    //     default:   cout << "Something went wrong in DatabaseManager::RemoveEntry" << endl; 
    //         break;
    //     }
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << endl;
    // }


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
    // this->rwdata.WriteData("3", "3", "3", false);
    // for (int i = 0; i < 10; i++)
    // {
    //     mapOfIgnoredEntires[to_string(i)] = 1;
    // }

    this->rwdata.SaveData(mapOfIgnoredEntires);
    mapOfIgnoredEntires.clear();
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



