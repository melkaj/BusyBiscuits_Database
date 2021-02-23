// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// datastructure.h - Header file for Datastructure class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#pragma once
#include <string>

using namespace std;

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

namespace datastructure_std
{
    class Datastructure
    {
    private:
        static const int tableSize = 4;

        // Person structure
        struct node
        {
            int socialSecurity;
            string name;
            string occupation;
            node* left;
            node* right;
        };

        node*           HashTable[tableSize];

        int             DeleteSubTree           (node* ptr);

        void            PrintDatabaseInOrder_P  (node* ptr);
        void            AddEntryToTree          (int socialSecurity, string name, string occupation, node* root);
        void            RemoveEntry_P           (int socialSecurity, node* parent);
        void            RemoveMatch             (node* parent, node* match, bool left);
        void            RemoveRootMatch         (node* &root);

        node*           FindSmallestNodePrivate (node* ptr);
        node*           GetTargetNode           (node* ptr, int socialSecurity);


    public:  
        // Intializes hashtable with empty entries and deletes them all when program ends
        Datastructure();
        ~Datastructure();

        int             Hash                    (int key);
        node*           CreateLeaf              (int socialSecurity, string name, string occupation);

        void            AddEntry                (int socialSecurity, string name, string occupation);
        void            RemoveEntry             (int socialSecurity);
        void            PrintDatabaseInOrder    ();

        string          GetOccupation           (int socialSecurity);
    };
}

#endif  // DATASTRUCTURE_H