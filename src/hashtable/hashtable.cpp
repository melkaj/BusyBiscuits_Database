
#include "hashtable.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace HashT_std;
using namespace std;

HashT::HashT()
// Makes each 'bucket' in our HashTable a new 'item'
// The item will be initialized to empty and it will point to NULL
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->socialSecurity = 000000;
		HashTable[i]->name = "Empty";
		HashTable[i]->occupation = "Empty";
		HashTable[i]->next = NULL;
	}
}

HashT::~HashT()
// Destroys the table
{
	item* delptr;
	for (int i = 0; i < tableSize; i++)
	{
		while (HashTable[i] != NULL)
		{
			delptr = HashTable[i];
			HashTable[i] = HashTable[i]->next;
			delete delptr;
		}
	}
}

int HashT::Hash(int key)
// Takes input and creates a hash value that will
// be used to store the element into the hashtable
{
	/*int hash = 0;

	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * 13;
	}
	return (hash % tableSize);*/

	return (key * 13) % tableSize;

}

void HashT::AddItem(int socialSecurity, string name, string occupation)
// Adds item into the database
// Inputs name and occupation
{
	int index = Hash(socialSecurity);

	// Checking if the first 'bucket' of the table is empty
	if (HashTable[index]->socialSecurity == 000000)
	{
		HashTable[index]->socialSecurity = socialSecurity;
		HashTable[index]->name = name;
		HashTable[index]->occupation = occupation;
		cout << "\n|\n\t\t" << name << " was added to the database" << "\n|\n\n";
	}
	else
	{
		// temperary pointer used to traverse through the
		// hash table
		item* ptr = HashTable[index];

		// Initializing new item before we add it to the HashTable
		item* newItem = new item;
		newItem->socialSecurity = socialSecurity;
		newItem->name = name;
		newItem->occupation = occupation;
		newItem->next = NULL;
		
		// Finding the last item in the hash table index
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		// Linking the last item to the new item
		ptr->next = newItem;
		cout << "\n|\n\t\t" << name << " was added to the database" << "\n|\n\n";
	}
}

void HashT::RemoveItem(int socialSecurity)
// Removes given name from the database
{
	// Finds bucket of name we want to remove
	int index = Hash(socialSecurity);

	// temporary pointers used to traverse bucket 
	// and delete item
	item* delptr;
	item* ptr1;
	item* ptr2;

	// case 0: Bucket is empty
	if (HashTable[index]->name == "Empty" && HashTable[index]->occupation == "Empty")
	{
		cout << "\n|\n\t\t" << socialSecurity << " is not in the database"
			<< "\n|\n\n";
	}

	// case 1: First item is a match and its the only item in the bucket
	else if ((HashTable[index]->socialSecurity == socialSecurity) && (HashTable[index]->next == NULL))
	{
		// Resets the first element to empty
		HashTable[index]->socialSecurity = socialSecurity;
		HashTable[index]->name = "Empty";
		HashTable[index]->occupation = "Empty";
		cout << "\n|\n\t\t" << socialSecurity << " was removed from the database" << "\n|\n\n";
	}
	
	// case 2: First item is a match and there are other items 
	//		   in the bucket
	// delptr points to first item, table element points to 
	// second item in the bucket then DELETES delptr
	else if (HashTable[index]->socialSecurity == socialSecurity)
	{
		delptr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delptr;
		cout << "\n|\n\t\t" << socialSecurity << " was removed from the database" << "\n|\n\n";
	}

	// case 3: Bucket has multiple items but first item is not match
	else
	{
		ptr1 = HashTable[index]->next;
		ptr2 = HashTable[index];

		// Traverses through bucket
		while (ptr1 != NULL && ptr1->socialSecurity != socialSecurity)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}

		// 3.1: No match is in the bucket
		if (ptr1 == NULL)
		{
			cout << "|\n\t\t" << socialSecurity << "'s information is not in the database"
				<< "\n|\n\n" << endl;
		}

		// 3.2: Match is within the bucket  
		else
		{
			delptr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;
			
			delete delptr;

			cout << "\n|\n\t\t" << socialSecurity << " was removed from the database" << "\n|\n\n";
		}

	}
}

int HashT::NumberOfItemsInBucket(int index)
// Finds the number of items in the bucket
// Takes in an index which will be the bucket we want to look into 
{
	int count = 0;

	if (HashTable[index]->name == "Empty")
	{
		return count;
	}
	else
	{
		count++;
		item* ptr = HashTable[index];
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			count++;
		}
	}
	return count;
}

void HashT::PrintTable()
// Prints out the entire table
{
	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInBucket(i);
		cout << "###############################\n";
		cout << "Bucket: " << i << endl;
		cout << HashTable[i]->socialSecurity << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->occupation << endl;
		cout << "Number of items in bucket: " << number << endl;
		PrintItemsInBucket(i);
		cout << "###############################\n";
	}
}

void HashT::PrintItemsInBucket(int index)
// Prints items only in a bucket
{
	item* ptr = HashTable[index];
	int counter = 1;

	if (ptr->name == "Empty")
	{
		cout << "----------------------------\n";
		cout << "Bucket " << index << " is empty." << endl;
		cout << "----------------------------\n";
	}
	else
	{
		cout << "Bucket " << index << " contains the following items:\n";
		while (ptr != NULL)
		{
			cout << "Item " << counter << " ---------------------\n";
			cout << "\t" << ptr->socialSecurity << endl;
			cout << "\t" << ptr->name << endl;
			cout << "\t" << ptr->occupation << endl;
			cout << "----------------------------\n";
			ptr = ptr->next;
			counter++;
		}
	}
}

void HashT::FindOccupation(int socialSecurity)
// Finds the occupation of the name given as the input
{
	// Gives us the bucket where the name would be placed
	int index = Hash(socialSecurity);
	bool foundName = false;
	string occ;

	item* ptr = HashTable[index];
	while (ptr != NULL)
	{
		if (ptr->socialSecurity == socialSecurity)
		{
			foundName = true;
			occ = ptr->occupation;
		}
		ptr = ptr->next;
	}

	if (foundName)
		cout << "\n|\n\t\t" << socialSecurity << "'s occupation: " << occ << "\n|\n\n";
	else
	{
		cout << "\n|\n\t\t" << socialSecurity << "'s information is not in the database"
			<< "\n|\n\n" << endl;
	}
}