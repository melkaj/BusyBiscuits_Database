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
    cout << "Welcome to BusyBiscuits Database!\n" 
        << "You can store entries which contain a social security, a name, and an occupation\n"
        << "Enter 'help' for more details about the program" << endl;
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
        cout << "Please enter what you would like to do: ";
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
            cout << "\tSaving data...\n" << endl;
        }
        else if (command == "quit")
        {
            this->databasemanager.SaveData();
            cout << "\tSaving data..." << endl;
            cout << "\tGoodbye...\n" << endl;
        }
        else if (command == "help")
        {
            cout << "You can enter the following commands:\n"
                << "\tadd -    Add a new entry to the database. You will be promted to enter a social security, a name, and an occupation\n"
                << "\tupdate - Update an existing entry. You will be promted to enter a social security that is already in the database and then you will enter a new name and occupation that will overwrite the existing name and occupation\n"
                << "\tremove - Remove an existing entry. You will be promted to enter a social security. If it exists, it will be removed\n"
                << "\tsave -   The modifications that have been performed on the database will be applied to the actual system. Meaning when you exit and enter back in the program, the modifications will be shown."
                << "\tprint -  Prints out the current state of the database\n"
                << "\thelp -   This help summary will pop up again\n" << endl;
        }
        else 
        {
            cout << "\tCommand entered was invalid. Retry\n" << endl;
        }
    }
}
