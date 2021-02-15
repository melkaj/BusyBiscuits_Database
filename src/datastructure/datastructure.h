#pragma once
#include <string>
// #include <cstdlib>
// #include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

namespace Datastructure_std
{
    class Datastructure
    {
    private:
        static const int tableSize = 10;

        struct elem
        {
            int socialSecurity;
            string name;
            string occupation;
            elem* next;
        };

        // Array that hold pointers to elems
        elem* HashTable[tableSize];

    public:  
        // Constructor
        Datastructure();

        // Deconstructor
        ~Datastructure();

        // Hash function
        int Hash(int key);

        // Add item to the data structure
        void AddItem(int socialSecurity, string name, string occupation);

        //
        int NumberOfItemsInBucket(int index);

        //
        void PrintTable();

        //
        void PrintItemsInBucket(int index);

        //
        void GetOccupation(int socialSecurity);

        //
        void RemoveItem(int socialSecurity);
    };
}

#endif  // DATASTRUCTURE_H