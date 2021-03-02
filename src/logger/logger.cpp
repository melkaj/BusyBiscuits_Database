// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// logger.cpp - Logger class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "logger.h"
#include <stdio.h>
#include <ctime>
#include <iostream>  

using namespace logger_std;


/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Opening the Log file
 *      TODO: Open a text file where its name is the current data
 *            and create the file if it does not exist. 
 *
 */
Logger::Logger()
{
    this->log_file_name = "log.txt";
}



/**
 * A:  String
 * RT: Void
 * 
 * Formats a message a logs it into the log file
 * 
 */
void Logger::Log(string message)
{
    ofstream log_file(this->log_file_name, ios::app);

    if (log_file.is_open())
    {
        time_t time_now = time(0);
        string formatted = ctime(&time_now);
        formatted.pop_back();
        log_file << '[' << formatted << "]: " << message << endl;
        log_file.close();
    }
    else  cout << "Unable to open file in logger::Log" << endl;
}
