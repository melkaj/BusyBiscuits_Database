// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// databasemanager.h - Header file for DatabaseManager class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#pragma once
#include "../datastructure/datastructure.h"
#include "../rwdata/rwdata.h"
#include <string>
#include <unordered_map>

using namespace std;

namespace databasemanager_std
{
    class DatabaseManager
    {
        private:
            datastructure_std::Datastructure    database;
            rwdata_std::RWData                  rwdata;

            unordered_map<string, int>             mapOfIgnoredEntires;


        public:
            DatabaseManager();
            ~DatabaseManager();
            void                                AddEntry        (string socialSecurity, string name, string occupation);
            void                                UpdateEntry     (string socialSecurity, string name, string occupation);
            void                                RemoveEntry     (string socialSecurity);
    };
}