#include "datastructure.h"
#include <iostream>
#include <string>

using namespace datastructure_std;
using namespace std;

Datastructure::Datastructure()
{
    for (int i = 0; i < tableSize; i++) 
    {
        HashTable[i] = CreateLeaf(000000, "Empty", "Empty");
    }
}

Datastructure::~Datastructure()
{
    for (int i = 0; i < tableSize; i++)
    {
        DeleteSubTree(HashTable[i]);
    }
}

void Datastructure::DeleteSubTree(Datastructure::node* ptr)
{
    if (ptr != NULL)
    {
        if (ptr->left != NULL)   DeleteSubTree(ptr->left);
        if (ptr->right != NULL)  DeleteSubTree(ptr->right);
        cout << "From deconstructor helper function - Deleting node: " << ptr->name << endl;
        delete ptr;
    }
}

int Datastructure::Hash(int key)
{
    return (key * 13) % tableSize;
}

Datastructure::node* Datastructure::CreateLeaf(int socialSecurity, string name, string occupation)
{
    node* newLeaf = new node;
    newLeaf->socialSecurity = socialSecurity;
    newLeaf->name =           name;
    newLeaf->occupation =     occupation;
    newLeaf->left = NULL;
    newLeaf->right = NULL;

    return newLeaf;
}

void Datastructure::AddElemToTree(int socialSecurity, string name, string occupation, Datastructure::node* root)
{  
    if (socialSecurity < root->socialSecurity)       // Less than
    {
        if (root->left == NULL)  root->left = CreateLeaf(socialSecurity, name, occupation); 
        else                     AddElemToTree(socialSecurity, name, occupation, root->left);
    }
    else if (socialSecurity > root->socialSecurity)  // Greater than
    {
        if (root->right == NULL) root->right = CreateLeaf(socialSecurity, name, occupation); 
        else                     AddElemToTree(socialSecurity, name, occupation, root->right);
    }
    else                                             // Equal
    {
        root->socialSecurity = socialSecurity;
        root->name =           name;
        root->occupation =     occupation;
    }
}

void Datastructure::AddElem(int socialSecurity, string name, string occupation)
{
    int index = Hash(socialSecurity);

    // Index in hashtable is empty
    if (HashTable[index]->socialSecurity == 000000)
    {
        HashTable[index]->socialSecurity = socialSecurity;
        HashTable[index]->name = name;
        HashTable[index]->occupation = occupation;
    }
    // Index in hashtable is not empty
    else
    {
        cout << "Adding: " << socialSecurity << endl;
        AddElemToTree(socialSecurity, name, occupation, HashTable[index]);
    }
}

void Datastructure::PrintDatabaseInOrder()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "======================================================================" << endl;
        PrintDatabaseInOrder_P(HashTable[i]);
        cout << "======================================================================" << endl;
    }
}

void Datastructure::PrintDatabaseInOrder_P(Datastructure::node* ptr)
{
    if (ptr->left != NULL)  PrintDatabaseInOrder_P(ptr->left);
    cout << "\tName: " << ptr->name << endl;
    cout << "\tSS: " << ptr->socialSecurity << endl;
    cout << "\tOccupation: " << ptr->occupation << endl;
    cout << "\tleft: " << ptr->left;
    cout << "\tright: " << ptr->right << endl;
    if (ptr->right != NULL) PrintDatabaseInOrder_P(ptr->right);
}




// TODO: Work on removing and all other funtionality