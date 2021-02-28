// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// logger.h - Header file for Logger class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#pragma once
#include <fstream>
#include <string>

using namespace std;

namespace logger_std
{
    class Logger
    {
        private:
            ofstream log_file;
            string   log_file_path;

        public:
            Logger();
            void Log(string message);

    };
}