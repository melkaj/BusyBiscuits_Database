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
    int count = 0;
    for (int i = 0; i < tableSize; i++)
    {
        count += DeleteSubTree(HashTable[i]);
    }
    cout << "Deleted " << count << " node(s)..." << endl;
}

int Datastructure::DeleteSubTree(Datastructure::node* ptr)
{
    int count = 0;
    if (ptr != NULL)
    {
        if (ptr->left != NULL)   count += DeleteSubTree(ptr->left);
        if (ptr->right != NULL)  count += DeleteSubTree(ptr->right);
        cout << "From deconstructor helper function - Deleting node: " << ptr->name << endl;
        delete ptr;
        count += 1;
    }
    return count;
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
        if (root->left == NULL)   root->left = CreateLeaf(socialSecurity, name, occupation); 
        else                      AddElemToTree(socialSecurity, name, occupation, root->left);
    }
    else if (socialSecurity > root->socialSecurity)  // Greater than
    {
        if (root->right == NULL)  root->right = CreateLeaf(socialSecurity, name, occupation); 
        else                      AddElemToTree(socialSecurity, name, occupation, root->right);
    }
    else                                             // Equal so overwrite
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
        AddElemToTree(socialSecurity, name, occupation, HashTable[index]);
    }
}

void Datastructure::PrintDatabaseInOrder()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "======================================================================" << endl;
        PrintDatabaseInOrder_P(HashTable[i]);
    }
    cout << "======================================================================" << endl;
}

void Datastructure::PrintDatabaseInOrder_P(node* ptr)
{
    if (ptr->left != NULL)  PrintDatabaseInOrder_P(ptr->left);
    cout << "\tName: " << ptr->name << "(" << &ptr << ")" << endl;
    cout << "\tSS: " << ptr->socialSecurity << endl;
    cout << "\tOccupation: " << ptr->occupation << endl;
    cout << "\tleft: " << ptr->left;
    cout << "\tright: " << ptr->right << endl;
    cout << "\t______________________________________________________________" << endl;
    if (ptr->right != NULL) PrintDatabaseInOrder_P(ptr->right);
}

void Datastructure::RemoveNode(int socialSecurity)
{
    int index = Hash(socialSecurity);

    if (HashTable[index]->socialSecurity == socialSecurity)
    {
        RemoveRootMatch(HashTable[index]);
        cout << "Fourth pass\t" << HashTable[index]->name << "\t" << HashTable[index]->occupation << endl;
    }
    else   
    {
        RemoveNode_P(socialSecurity, HashTable[index]);
    }
    cout << "In RemoveNode: " << HashTable[index]->socialSecurity
        << HashTable[index]->name
        << HashTable[index]->occupation << endl;
}

void Datastructure::RemoveNode_P(int socialSecurity, node* parent)
{
    // socialSecurity is less than parent socialSecurity, 
    // and its looking at something to the left
    if (socialSecurity < parent->socialSecurity && parent->left != NULL)
    {
        parent->left->socialSecurity == socialSecurity ?
            RemoveMatch(parent, parent->left, true) :
            RemoveNode_P(socialSecurity, parent->left);
    }
    // socialSecurity is greater than parent socialSecurity, 
    // and its looking at something to the right
    else if (socialSecurity > parent->socialSecurity && parent->right != NULL)
    {
        parent->right->socialSecurity == socialSecurity ?
            RemoveMatch(parent, parent->right, false) :
            RemoveNode_P(socialSecurity, parent->right);
    }
    // No match in database
    else
    {
        cout << "socialSecurity was not found" << endl;
    }
}

void Datastructure::RemoveMatch(Datastructure::node* parent, Datastructure::node* match, bool left)
{
    node* delptr;
    int matchSocial = match->socialSecurity;
    //int smallestInRightSubtree;
    node* smallestNodeInRightSubtree;

    // ZERO children
    if (match->left == NULL && match->right == NULL)
    {
        delptr = match;
        left == true ? 
            parent->left = NULL : 
            parent->right = NULL;
        delete delptr;
        cout << " Node with Social Security " << matchSocial
            << " was removed\n";
    }
    // ONE child (has RIGHT child)
    else if (match->left == NULL && match->right != NULL)
    {
        // If the match node is a right node to the parent
        // or a left node to the parent
        left == true ?
            parent->left = match->right :
            parent->right = match->right;
        match->right = NULL;
        delptr = match;
        delete delptr;
        cout << " Node with Social Security " << matchSocial
            << " was removed\n";
    }
    // ONE child (has LEFT child)
    else if (match->left != NULL && match->right == NULL)
    {
        // If the match node is a right node to the parent
        // or a left node to the parent
        left == true ?
            parent->left = match->left :
            parent->right = match->left;
        match->left = NULL;
        delptr = match;
        delete delptr;
        cout << " Node with Social Security " << matchSocial
            << " was removed\n";
    }
    // 2 children
    else
    {
        smallestNodeInRightSubtree = FindSmallestNodePrivate(match->right);

        // temp strings to hold the data needed for the removal
        string temp1 = smallestNodeInRightSubtree->name;
        string temp2 = smallestNodeInRightSubtree->occupation;
        int temp3 = smallestNodeInRightSubtree->socialSecurity;

        // Removes smallest node in right subtree
        RemoveNode_P(smallestNodeInRightSubtree->socialSecurity, match);
        
        // Data moves to the root node
        match->name = temp1;
        match->occupation = temp2;
        match->socialSecurity = temp3;
    }
}

void Datastructure::RemoveRootMatch(Datastructure::node* &root)
{
    node* delptr = root;
    int rootSocial = root->socialSecurity;
    node* smallestNodeInRightSubtree;

    // ZERO children
    if (root->left == NULL && root->right == NULL)
    {
        cout << "Hello2" << endl;
        // root->socialSecurity = 000000;
        // root->name =           "Empty";
        // root->occupation =     "Empty";
        delete delptr;
        root = CreateLeaf(000000, "Empty", "Empty");
    }
    // One Child (only has RIGHT child)
    else if (root->left == NULL && root->right != NULL)
    {
        // root = root->right;
        // delete delptr;


        root = root->right;
        delptr->right = NULL;

        // cout << delptr->name << "\t" << delptr->occupation << endl;
        delete delptr;
        cout << "Root node with Social Security " << rootSocial
            << " has been deleted\n"
            << "New root node has Social Security " << root->socialSecurity << endl;
        cout << "Second pass\t" << root->name << "\t" << root->occupation << endl;
        cout << "Third pass\t" << delptr->name << "\t" << delptr->occupation << endl;
    }
    // One Child (only has LEFT child)
    else if (root->left != NULL && root->right == NULL)
    {
        root = root->left;
        delptr->left = NULL;
        delete delptr;
        cout << "Root node with Social Security " << rootSocial
            << " has been deleted\n"
            << "New root node has Social Security " << root->socialSecurity << endl;
    }
    // 2 Children
    else
    {
        // Finds smallest node in right subtree
        smallestNodeInRightSubtree = FindSmallestNodePrivate(root->right);

        // temp strings to hold the data needed for the removal
        string temp1 = smallestNodeInRightSubtree->name;
        string temp2 = smallestNodeInRightSubtree->occupation;
        int temp3 = smallestNodeInRightSubtree->socialSecurity;

        // Removes smallest node in right subtree
        RemoveNode_P(smallestNodeInRightSubtree->socialSecurity, root);

        // Data moves to the root node
        root->name = temp1;
        root->occupation = temp2;
        root->socialSecurity = temp3;
        cout << "The root node with Social Security " << rootSocial
            << " was overwritten with Social Security " << root->socialSecurity << endl;
    }
}

Datastructure::node* Datastructure::FindSmallestNodePrivate(Datastructure::node* ptr)
{
    if (ptr->left != NULL)
        return FindSmallestNodePrivate(ptr->left);
    else
        return ptr;
}

Datastructure::node* Datastructure::GetTargetNode(Datastructure::node* ptr, int socialSecurity)
{
    if (ptr->socialSecurity == socialSecurity)                            return ptr;
    else if (ptr->socialSecurity > socialSecurity && ptr->left != NULL)   return GetTargetNode(ptr->left, socialSecurity);
    else if (ptr->socialSecurity < socialSecurity && ptr->right != NULL)  return GetTargetNode(ptr->right, socialSecurity);
    return CreateLeaf(100000, "Empty", "Empty");
}

string Datastructure::GetOccupation(int socialSecurity)
{
    int index = Hash(socialSecurity);

    Datastructure::node* foundNode = GetTargetNode(HashTable[index], socialSecurity);

    return foundNode->occupation;
}
