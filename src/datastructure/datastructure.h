#pragma once
#include "../binarytree/binarytree.h"
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

        // Array of node pointers. Each node creates a binary tree
        node* HashTable[tableSize];

        // Used to traverse the tree if the main index is filled up
        void AddEntryToTree(int socialSecurity, string name, string occupation, Datastructure::node* root);

        // Deletes a subtree recursively 
        int DeleteSubTree(Datastructure::node* ptr);

        void PrintDatabaseInOrder_P(Datastructure::node* ptr);

        void RemoveEntry_P(int socialSecurity, Datastructure::node* parent);

        void RemoveMatch(Datastructure::node* parent, Datastructure::node* match, bool left);

        void RemoveRootMatch(Datastructure::node* &root);

        Datastructure::node* FindSmallestNodePrivate(Datastructure::node* ptr);

        // A:   pointer to a node, integer
        // RT:  pointer to a node
        // Returns the desired node based on social security. If no node is found, then a 
        //  generic one is returned (ie. ss=100000, "Empty", "Empty")
        Datastructure::node* GetTargetNode(Datastructure::node* ptr, int socialSecurity);

    public:  
        // Intializes hashtable with empty entries
        Datastructure();

        // TODO: ONCE DATASTRUCTURE IS FINISHED, CLEANUP PROPERLY    
        ~Datastructure();

        // Hash function
        int Hash(int key);

        // Creates new node 
        node* CreateLeaf(int socialSecurity, string name, string occupation);

        // A:   Integer, String, String
        // RT:  Void
        // Adds a new entry to the datastructure
        void AddEntry(int socialSecurity, string name, string occupation);

        //
        int NumberOfItemsInBucket(int index);

        // A:   None
        // RT:  None
        // Prints binary tree for each index in the hash table from (0->len(hashtable))
        void PrintDatabaseInOrder();

        // 
        void PrintItemsInBucket(int index);

        // A:   Integer
        // RT:  String
        // Returns the occupation of the data entry with the given social security
        //  If no entry is found, then "Empty is returned"
        string GetOccupation(int socialSecurity);

        //
        void RemoveEntry(int socialSecurity);
    };
}

#endif  // DATASTRUCTURE_H