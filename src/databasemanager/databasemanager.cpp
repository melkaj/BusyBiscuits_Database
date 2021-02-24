// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// databasemanager.cpp - DatabaseManager class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "databasemanager.h"
#include <string>
#include <iostream>

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
    cout << "DatabaseManager destructor..." << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Performing all the necessaary additions to the database and the file
 * 
 */
void DatabaseManager::AddEntry(int socialSecurity, string name, string occupation)
{
    this->database.AddEntry(socialSecurity, name, occupation);
    this->rwdata.AppendData(socialSecurity, name, occupation);
}