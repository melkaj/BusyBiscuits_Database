#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

namespace HashT_std 
{
	class HashT		// Hash Table 
	{
	private:
		// Size of our hash table
		static const int tableSize = 4;

		// What each 'item' will hold;
		// A name, an occupation, social security 
		// and the address to the next 'item;
		struct item 
		{
			int socialSecurity;
			string name;
			string occupation;
			item* next;
		};

		// Array whose elements are pointers to an 'item'
		item* HashTable[tableSize];


	public:
		// Constructor
		HashT();

		// Destructor
		~HashT();

		// How we find what 'bucket' our item goes to
		int Hash(int key);

		// Add an item to our database
		void AddItem(int socialSecurity, string name, string occupation);

		// Finds number of items inside a 'bucket'
		int NumberOfItemsInBucket(int index);

		// Print out the items in the table (Not in the bucket yet)
		void PrintTable();

		// Prints items only in bucket
		void PrintItemsInBucket(int index);

		// Finds occupation of given person
		void FindOccupation(int socialSecurity);

		// Removes an item from the database
		void RemoveItem(int socialSecurity);
	};
}


#endif	//HASH_H
