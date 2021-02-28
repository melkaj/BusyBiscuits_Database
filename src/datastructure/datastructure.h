// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// datastructure.h - Header file for Datastructure class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#pragma once
#include "../logger/logger.h"
#include <string>

using namespace logger_std;
using namespace std;

// #ifndef DATASTRUCTURE_H
// #define DATASTRUCTURE_H

namespace datastructure_std
{
    class Datastructure: public Logger
    {
    private:
        static const int tableSize = 4;

        // Person structure
        struct node
        {
            string socialSecurity;
            string name;
            string occupation;
            node* left;
            node* right;
        };

        node*           HashTable[tableSize];

        int             DeleteSubTree           (node* ptr);

        void            PrintDatabaseInOrder_P  (node* ptr);
        int             AddEntryToTree          (string socialSecurity, string name, string occupation, node* root);
        int             RemoveEntry_P           (string socialSecurity, node* parent);
        int             RemoveMatch             (node* parent, node* match, bool left);
        int             RemoveRootMatch         (node* &root);

        node*           FindSmallestNodePrivate (node* ptr);
        node*           GetTargetNode           (node* ptr, string socialSecurity);


    public:  
        // Intializes hashtable with empty entries and deletes them all when program ends
        Datastructure();
        ~Datastructure();

        int             Hash                    (string key);
        
        node*           CreateLeaf              (string socialSecurity, string name, string occupation);
        
        int             AddEntry                (string socialSecurity, string name, string occupation);
        int             UpdateEntry             (string socialSecurity, string name, string occupation);
        int             RemoveEntry             (string socialSecurity);
        
        void            PrintDatabaseInOrder    ();

        string          GetOccupation           (string socialSecurity);
        string*         GetEntry                (string socialSecurity);
    };
}

// #endif  // DATASTRUCTURE_H