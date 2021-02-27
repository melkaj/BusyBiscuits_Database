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
    char command;

    while (command != 'q')
    {
        cout << "Please enter what you would like to do: \n\t" << endl;
        cin >> command;

        switch (command)
        {
        case 'p':
            this->databasemanager.PrintDataInOrder();  break;
        
        default:
            cout << "Command (" << command << ") was not valid. Try again..." << endl;
            break;
        }
    }

}
