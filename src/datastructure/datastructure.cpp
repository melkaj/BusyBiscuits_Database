// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// datastructure.cpp - Datastructure class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#include "datastructure.h"
#include <iostream>
#include <string>

using namespace datastructure_std;
using namespace std;



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Initializes the hashtable with default values
 * 
 */
Datastructure::Datastructure()
{
    for (int i = 0; i < tableSize; i++) 
    {
        HashTable[i] = CreateLeaf("000000", "Empty", "Empty");
    }
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: None
 * 
 * Deletes the datastructure that was added on the heap. Traverses through
 *      each bianry tree and deletes all the entrees
 * 
 */
Datastructure::~Datastructure()
{
    cout << "DataStructure deconstructor..." << endl;
    int count = 0;
    for (int i = 0; i < tableSize; i++)
    {
        count += DeleteSubTree(HashTable[i]);
    }
    cout << "Deleted " << count << " node(s)..." << endl;
    cout << "======================================================================\n" << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Datastructure::node*
 * RT: Integer
 * 
 * Returns the amount of nodes that were deleted in the given tree
 * Function used to recursively delete nodes from the heap 
 *      After a node is deleted, a counter is incremented and returned 
 *      to the calling function
 * 
 */
int Datastructure::DeleteSubTree(Datastructure::node* ptr)
{
    int count = 0;
    if (ptr != NULL)
    {
        if (ptr->left != NULL)   count += DeleteSubTree(ptr->left);
        if (ptr->right != NULL)  count += DeleteSubTree(ptr->right);
        cout << "From deconstructor helper function - Deleting node: " << 
            ptr->socialSecurity << '\t' << ptr->name << '\t' << ptr->occupation << endl;
        delete ptr;
        count += 1;
    }
    return count;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer
 * RT: Integer
 * 
 * Returns the index that a given 'key' should be placed in.
 *      Right now, the Hash function is EXTREMELY simple and needs to be 
 *      sreplaced with something a bit more robust
 * 
 */
int Datastructure::Hash(string key)
{
    int total = 0;
    for (long unsigned int i = 0; i < key.length(); i++)  total += int(key[i]);

    return total % tableSize;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String
 * RT: DataStructure::node*
 * 
 * Returns a new 'node' (data entry) that holds the arguments as its values
 * 
 */
Datastructure::node* Datastructure::CreateLeaf(string socialSecurity, string name, string occupation)
{
    node* newLeaf = new node;
    newLeaf->socialSecurity = socialSecurity;
    newLeaf->name =           name;
    newLeaf->occupation =     occupation;
    newLeaf->left = NULL;
    newLeaf->right = NULL;

    return newLeaf;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String, Datastructure::node*
 * RT: Integer
 * 
 * Adds a new entry to the binary tree that is attache to the index in the 
 *      table. This function is called when there was a collision in the 
 *      hashtable and the given key needs to be placed in the binary tree 
 *      instead of the table itself. 
 * 
 */
int Datastructure::AddEntryToTree(string socialSecurity, string name, string occupation, Datastructure::node* root)
{  
    if (socialSecurity < root->socialSecurity)       // Less than
    {
        if (root->left == NULL)   { root->left = CreateLeaf(socialSecurity, name, occupation); return 100; }
        else                      return AddEntryToTree(socialSecurity, name, occupation, root->left);
    }
    else if (socialSecurity > root->socialSecurity)  // Greater than
    {
        if (root->right == NULL)  { root->right = CreateLeaf(socialSecurity, name, occupation); return 100; }
        else                      return AddEntryToTree(socialSecurity, name, occupation, root->right);
    }
    else                                             // Equal
        return 101;

    return -100;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String
 * RT: Integer
 * 
 * Adds a new entry into the datastructure. If there is no collision in the
 *      hashtable, then the entry is placed on the table itself. If there 
 *      is a collision then it shall be placed in the binary tree that is
 *      attached to the index in the table.
 * 
 */
int Datastructure::AddEntry(string socialSecurity, string name, string occupation)
{
    int index = Hash(socialSecurity);

    // Index in hashtable is empty
    if (HashTable[index]->socialSecurity == "000000")
    {
        HashTable[index]->socialSecurity = socialSecurity;
        HashTable[index]->name = name;
        HashTable[index]->occupation = occupation;
        return 100;
    }
    // Index in hashtable is not empty
    else
    {
        return AddEntryToTree(socialSecurity, name, occupation, HashTable[index]);
    }
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, String, String
 * RT: Integer
 *
 * Looks for an existing entry and updates the entry 
 * 
 */

int Datastructure::UpdateEntry(string socialSecurity, string name, string occupation)
{
    int index = Hash(socialSecurity);

    Datastructure::node* foundNode = GetTargetNode(HashTable[index], socialSecurity);

    if (foundNode->socialSecurity == socialSecurity)
    {
        foundNode->name = name;  foundNode->occupation = occupation;
        return 100;
    }
    
    return 102;

}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  None
 * RT: Void
 * 
 * Prints the entire table. Traverses through the hashtable and calls the
 *      private function to print out the binary tree that is at that index
 * 
 */
void Datastructure::PrintDatabaseInOrder()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "======================================================================" << endl;
        PrintDatabaseInOrder_P(HashTable[i]);
    }
    cout << "======================================================================" << endl;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Datastructure::node*
 * RT: Void
 * 
 * Prints the inorder traversal of a given binary tree
 * 
 */
void Datastructure::PrintDatabaseInOrder_P(Datastructure::node* ptr)
{
    if (ptr->left != NULL)  PrintDatabaseInOrder_P(ptr->left);
    cout << "\tName: " << ptr->name << endl;
    cout << "\tSS: " << ptr->socialSecurity << endl;
    cout << "\tOccupation: " << ptr->occupation << endl;
    
    // Left node
    if (ptr->left != NULL)  cout << "\tleft: " << ptr->left->socialSecurity;
    else                    cout << "\tleft: " << ptr->left;

    // Right node
    if (ptr->right != NULL) cout << "\tright: " << ptr->right->socialSecurity << endl;
    else                    cout << "\tright: " << ptr->right << endl;

    cout << "\t______________________________________________________________" << endl;
    if (ptr->right != NULL) PrintDatabaseInOrder_P(ptr->right);
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer
 * RT: Integer
 * 
 * Checks if the given socialSecurity is in the hashtable. If so, then
 *      call the helper function to remove the root of the tree and 
 *      have it be replaced if necessary. If not, then call the other
 *      helper function to search through tree and remove it if possible
 * 
 */
int Datastructure::RemoveEntry(string socialSecurity)
{
    int index = Hash(socialSecurity);

    if (HashTable[index]->socialSecurity == socialSecurity)
    {
        return RemoveRootMatch(HashTable[index]);
    }
    else   
    {
        return RemoveEntry_P(socialSecurity, HashTable[index]);
    }
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer, Datastructure::node*
 * RT: Integer
 * 
 * Recursively traverses through the given binary tree to search for desired node.
 *      If found then call helper function to remove it and have it replaced
 *      if necessary. If not found, then console log that it was not found
 * 
 */
int Datastructure::RemoveEntry_P(string socialSecurity, Datastructure::node* parent)
{
    // socialSecurity is less than parent socialSecurity, 
    // and its looking at something to the left
    if (socialSecurity < parent->socialSecurity && parent->left != NULL)
    {
        if (parent->left->socialSecurity == socialSecurity) return RemoveMatch(parent, parent->left, true);
        else                                                return RemoveEntry_P(socialSecurity, parent->left);                 
    }
    // socialSecurity is greater than parent socialSecurity, 
    // and its looking at something to the right
    else if (socialSecurity > parent->socialSecurity && parent->right != NULL)
    {
        if (parent->right->socialSecurity == socialSecurity) return RemoveMatch(parent, parent->right, false);
        else                                                 return RemoveEntry_P(socialSecurity, parent->right); 
    }
    // No match in database
    else  
        return 102;

    return 100;

}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Datastrucure::node*, Datastrucure::node*, Bool
 * RT: Integer
 * 
 * Removes the node and reconnects the tree accordingly based on specific 
 *      orientations parent-match relationship
 * 
 */
int Datastructure::RemoveMatch(Datastructure::node* parent, Datastructure::node* match, bool left)
{
    node* delptr;
    string matchSocial = match->socialSecurity;
    node* smallestNodeInRightSubtree;

    // ZERO children
    if (match->left == NULL && match->right == NULL)
    {
        delptr = match;
        left == true ? 
            parent->left = NULL : 
            parent->right = NULL;
        delete delptr;
        cout << "Node with Social Security " << matchSocial
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
        cout << "Node with Social Security " << matchSocial
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
        cout << "Node with Social Security " << matchSocial
            << " was removed\n";
    }
    // 2 children
    else
    {
        smallestNodeInRightSubtree = FindSmallestNodePrivate(match->right);

        // temp strings to hold the data needed for the removal
        string temp1 = smallestNodeInRightSubtree->name;
        string temp2 = smallestNodeInRightSubtree->occupation;
        string temp3 = smallestNodeInRightSubtree->socialSecurity;

        // Removes smallest node in right subtree
        RemoveEntry_P(smallestNodeInRightSubtree->socialSecurity, match);
        
        // Data moves to the root node
        match->name = temp1;
        match->occupation = temp2;
        match->socialSecurity = temp3;
    }

    return 100;

}


 
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Datastructure::node*
 * RT: Integer
 * 
 * Removes root of the binary tree
 * 
 */
int Datastructure::RemoveRootMatch(Datastructure::node* &root)
{
    node* delptr = root;
    string rootSocial = root->socialSecurity;
    node* smallestNodeInRightSubtree;

    // ZERO children
    if (root->left == NULL && root->right == NULL)
    {
        delete delptr;
        root = CreateLeaf("000000", "Empty", "Empty");
    }
    // One Child (only has RIGHT child)
    else if (root->left == NULL && root->right != NULL)
    {
        root = root->right;
        delptr->right = NULL;

        delete delptr;
        cout << "Root node with Social Security " << rootSocial
            << " has been deleted\n"
            << "New root node has Social Security " << root->socialSecurity << endl;
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
        string temp3 = smallestNodeInRightSubtree->socialSecurity;

        // Removes smallest node in right subtree
        RemoveEntry_P(smallestNodeInRightSubtree->socialSecurity, root);

        // Data moves to the root node
        root->name = temp1;
        root->occupation = temp2;
        root->socialSecurity = temp3;
        cout << "The root node with Social Security " << rootSocial
            << " was overwritten with Social Security " << root->socialSecurity << endl;
    }

    return 100;

}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Datastructure::node*
 * RT: Datastrucutre::node*
 * 
 * Finds the smallest valued node in the right subtree of the given node
 * 
 */
Datastructure::node* Datastructure::FindSmallestNodePrivate(Datastructure::node* ptr)
{
    if (ptr->left != NULL)
        return FindSmallestNodePrivate(ptr->left);
    else
        return ptr;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Datastructure::node*
 * RT: Datastructure::node*
 * 
 * Recursively traverses through the binary tree to find and return node
 *      with desired social security. If not found, then a default node 
 *      is generated and returned. 
 * 
 */
Datastructure::node* Datastructure::GetTargetNode(Datastructure::node* ptr, string socialSecurity)
{
    if      (ptr->socialSecurity == socialSecurity)                       return ptr;
    else if (ptr->socialSecurity > socialSecurity && ptr->left != NULL)   return GetTargetNode(ptr->left, socialSecurity);
    else if (ptr->socialSecurity < socialSecurity && ptr->right != NULL)  return GetTargetNode(ptr->right, socialSecurity);
    return  CreateLeaf("-100000", "Empty", "Empty");
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  Integer
 * RT: String
 * 
 * Returns occupation of desired data entry
 * 
 */
string Datastructure::GetOccupation(string socialSecurity)
{
    int index = Hash(socialSecurity);

    Datastructure::node* foundNode = GetTargetNode(HashTable[index], socialSecurity);

    return foundNode->occupation;
}



/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * A:  String
 * RT: String Pointer
 * 
 * Returns a pointer to a string array that will hold the data of the array
 * 
 */
string* Datastructure::GetEntry(string socialSecurity)
{
    int index = Hash(socialSecurity);

    Datastructure::node* foundNode = GetTargetNode(HashTable[index], socialSecurity);

    string* entryData = new string[3] { foundNode->socialSecurity, foundNode->name, foundNode->occupation };

    // string entryData[3] = { foundNode->socialSecurity, foundNode->name, foundNode->occupation };

    return entryData;
}
