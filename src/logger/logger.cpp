// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// logger.cpp - Logger class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "logger.h"

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
    this->log_file_path = "/home/mel/Desktop/BusyBiscuits_Database/logs/log.txt";
    log_file.open(log_file_path);
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Closing the file
 * 
 */
Logger::~Logger()
{
    log_file.close();
}