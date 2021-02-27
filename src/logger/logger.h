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

namespace logger_std
{
    class Logger
    {
        private:
            std::ofstream log_file;
            std::string   log_file_path;

        public:
            Logger();
            ~Logger();

    };
}