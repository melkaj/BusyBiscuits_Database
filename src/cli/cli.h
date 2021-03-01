// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// cli.h - Header file for CLI class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================


#pragma once
#include "../databasemanager/databasemanager.h"

namespace cli_std
{
    class CLI
    {
        private:
            databasemanager_std::DatabaseManager databasemanager;

        public:
            CLI();
            // ~CLI();

            void MainLoop();
    
    };
}

