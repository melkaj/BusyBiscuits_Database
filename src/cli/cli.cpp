// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// cli.cpp - CLI class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================


#include "cli.h"
#include <iostream>

using namespace cli_std;
using namespace std;



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 *
 * Greets the user
 * 
 */
CLI::CLI()
{
    cout << "Welcome to BusyBiscuits Database" << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 *
 * Says goodbye to the user
 * 
 */
CLI::~CLI()
{
    cout << "Goodbye..." << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 *
 * The user input will be taken here
 * 
 */
void CLI::MainLoop()
{
    string command;

    while (command != "quit")
    {
        cout << "Please enter what you would like to do: \n\t" << endl;
        getline(cin, command);

        if (command == "remove" || command == "find")
        {
            string socialSecurity;
            cout << "Enter social security: ";
            getline(cin, socialSecurity);

            this->databasemanager.ExecuteCrudOper(command, socialSecurity);
        }
        else if (command == "add" || command == "update")
        {
            string socialSecurity, name, occupation;
            cout << "Enter social security: ";
            getline(cin, socialSecurity);

            cout << "Enter name: ";
            getline(cin, name);

            cout << "Enter occupation: ";
            getline(cin, occupation);

            this->databasemanager.ExecuteCrudOper(command, socialSecurity, name, occupation);
        }
        else if (command == "print") 
        {
            this->databasemanager.PrintDataInOrder();
        }
        else if (command == "save")
        {
            this->databasemanager.SaveData();
        }
        else 
        {
            cout << "Command entered was invalid. Retry" << endl;
        }
    }
}
