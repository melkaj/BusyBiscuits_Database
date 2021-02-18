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
        static const int tableSize = 10;

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
        void AddElemToTree(int socialSecurity, string name, string occupation, Datastructure::node* root);

        // Deletes a subtree recursively 
        void DeleteSubTree(Datastructure::node* ptr);

        void PrintDatabaseInOrder_P(Datastructure::node* ptr);

        void RemoveNode_P(int socialSecurity, Datastructure::node* parent);

        void RemoveMatch(Datastructure::node* parent, Datastructure::node* match, bool left);

        void RemoveRootMatch(Datastructure::node* &root);

        Datastructure::node* FindSmallestNodePrivate(Datastructure::node* ptr);

    public:  
        // Intializes hashtable with empty entries
        Datastructure();

        // TODO: ONCE DATASTRUCTURE IS FINISHED, CLEANUP PROPERLY    
        ~Datastructure();

        // Hash function
        int Hash(int key);

        // Creates new node 
        node* CreateLeaf(int socialSecurity, string name, string occupation);

        // Add item to the data structure
        void AddElem(int socialSecurity, string name, string occupation);

        //
        int NumberOfItemsInBucket(int index);

        //
        void PrintDatabaseInOrder();

        //
        void PrintItemsInBucket(int index);

        //
        void GetOccupation(int socialSecurity);

        //
        void RemoveNode(int socialSecurity);
    };
}

#endif  // DATASTRUCTURE_H