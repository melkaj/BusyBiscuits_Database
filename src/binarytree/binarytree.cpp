
#include <cstdlib>
#include <iostream>
#include <string>
#include "binarytree.h"

using namespace std;
using namespace BT_std;

BTree::BTree()
// Makes root point to nothing
{
	root = NULL;
}

BTree::~BTree()
{
	RemoveSubtree(root);
}

void BTree::RemoveSubtree(BTree::node* ptr)
{
	// points to something
	if (ptr != NULL)
	{
		if (ptr->left != NULL)
		{
			RemoveSubtree(ptr->left);
		}
		if (ptr->right != NULL)
		{
			RemoveSubtree(ptr->right);
		}
		cout << "Deleting Node with name: " << ptr->name << endl;
		delete ptr;
	}
}


BTree::node* BTree::CreateLeaf(int socialSecurity, string name, string occupation)
// Returns newly created node which is initialized with inputs
// name and occupation
{
	node* newLeaf = new node;
	newLeaf->socialSecurity = socialSecurity;
	newLeaf->name = name;
	newLeaf->occupation = occupation;
	newLeaf->right = NULL;
	newLeaf->left = NULL;

	return newLeaf;
}

void BTree::AddLeaf(int socialSecurity, string name, string occupation)
// Calls the private version of this function
{
	AddLeafPrivate(socialSecurity, name, occupation, root);
}

void BTree::AddLeafPrivate(int socialSecurity, string name, string occupation, BTree::node* ptr)
// Takes newly created leaf and adds it to the binary tree
{
	// Empty tree
	if (root == NULL)
	{
		root = CreateLeaf(socialSecurity, name, occupation);
		/*cout << "\n|\n\t\tThe name " << name
			<< " has been added to the database"
			<< "\n|\n";*/
	}
	
	// If name is LESS than the name in the node we are looking at
	else if (socialSecurity < ptr->socialSecurity)
	{
		// Move to the left of the tree recursively
		if (ptr->left != NULL)
		{
			AddLeafPrivate(socialSecurity, name, occupation, ptr->left);
		}
		else
		{
			ptr->left = CreateLeaf(socialSecurity, name, occupation);
			/*cout << "\n|\n\t\tThe name " << name
				<< " has been added to the database"
				<< "\n|\n";*/
		}
	}

	// If name is GREATER than or equal the name in the node
	// we are looking at
	else if (socialSecurity >= ptr->socialSecurity)
	{
		// Move to the right of the tree recursively
		if (ptr->right != NULL)
		{
			AddLeafPrivate(socialSecurity, name, occupation, ptr->right);
		}
		else
		{
			ptr->right = CreateLeaf(socialSecurity, name, occupation);
			/*cout << "\n|\n\t\tThe name " << name
				<< " has been added to the database"
				<< "\n|\n";*/
		}
	}
}

void BTree::RemoveNode(int socialSecurity)
{
	RemoveNodePrivate(socialSecurity, root);
}

void BTree::RemoveNodePrivate(int socialSecurity, BTree::node* parent)
{
	// Root is looking at something
	if (root != NULL)
	{
		// Root has name we want to remove
		if (root->socialSecurity == socialSecurity)
		{
			RemoveRootMatch();
		}
		else
		{
			// socialSecurity is less than parent socialSecurity, 
			// and its looking at something to the left
			if (socialSecurity < parent->socialSecurity && parent->left != NULL)
			{
				parent->left->socialSecurity == socialSecurity ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(socialSecurity, parent->left);
			}
			// socialSecurity is greater than parent socialSecurity, 
			// and its looking at something to the right
			else if (socialSecurity > parent->socialSecurity && parent->right != NULL)
			{
				parent->right->socialSecurity == socialSecurity ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(socialSecurity, parent->right);
			}
			// No match in database
			else
			{
				cout << "socialSecurity was not found" << endl;
			}
		}
	}
	// Empty Tree
	else
	{
		cout << "Empty Tree" << endl;
	}
}

void BTree::RemoveMatch(BTree::node* parent, BTree::node* match, bool left)
{
	if (root != NULL)
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
			RemoveNodePrivate(smallestNodeInRightSubtree->socialSecurity, match);
			
			// Data moves to the root node
			match->name = temp1;
			match->occupation = temp2;
			match->socialSecurity = temp3;
		}
	}
	else
	{
		cout << "Empty Tree" << endl;
	}
}

void BTree::RemoveRootMatch()
{
	// root is looking at something
	if (root != NULL)
	{
		node* delptr = root;
		int rootSocial = root->socialSecurity;
		node* smallestNodeInRightSubtree;

		// ZERO children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delptr;
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
			int temp3 = smallestNodeInRightSubtree->socialSecurity;

			// Removes smallest node in right subtree
			RemoveNodePrivate(smallestNodeInRightSubtree->socialSecurity, root);

			// Data moves to the root node
			root->name = temp1;
			root->occupation = temp2;
			root->socialSecurity = temp3;
			cout << "The root node with Social Security " << rootSocial
				<< " was overwritten with Social Security " << root->socialSecurity << endl;
		}
	}
	else
	{
		cout << "empty tree" << endl;
	}
}

BTree::node* BTree::FindSmallestNodePrivate(BTree::node* ptr)
{
	// pointer points to something
	if (ptr != NULL)
	{
		if (ptr->left != NULL)
			return FindSmallestNodePrivate(ptr->left);
		else
			return ptr;
	}
	// Empty Tree
	else
	{
		cout << "Empty Pointer" << endl;
		return NULL;
	}
}

int BTree::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BTree::FindSmallestPrivate(BTree::node* ptr)
{
	if (root == NULL)
	{
		cout << "Tree is empty\n";
		return -1000;
	}
	else
	{
		if (ptr->left != NULL)
			return FindSmallestPrivate(ptr->left);
		else
			return ptr->socialSecurity;
	}
}

void BTree::PrintInOrder()
// Calls private version of this fucntion
{
	PrintInOrderPrivate(root);
}

void BTree::PrintInOrderPrivate(BTree::node* ptr)
// Prints contents of tree IN-ORDER
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
		{
			PrintInOrderPrivate(ptr->left);
		}
		cout << "\t\tSocial Security: " << ptr->socialSecurity
			<< "\n\t\tName: " << ptr->name
			<< "\n\t\tOccupation: " << ptr->occupation
			<< "\n\n";
		if (ptr->right != NULL)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		cout << "\n|\n\t\tThe tree is empty"
			<< "\n|\n";
	}
}

void BTree::PrintChildren(int socialSecurity)
{
	node* ptr = ReturnNode(socialSecurity);

	// Node is pointing to something
	if (ptr != NULL)
	{
		cout << "#################################################\n";
		cout << "\tParent Node: \tSocial Security: " << ptr->socialSecurity
			<< "\n\t\t\tName: " << ptr->name
			<< "\n\t\t\tOccupation: " << ptr->occupation << endl;

		ptr->left == NULL ?
			cout << "\tLeft Child: \tNULL\n" :
			cout << "\tLeft Child: \tSocial Security: " << ptr->left->socialSecurity
			<< "\n\t\t\tName: " << ptr->left->name
			<< "\n\t\t\tOccupation: " << ptr->left->occupation
			<< endl;

		ptr->right == NULL ?
			cout << "\tRight Child: \tNULL\n" :
			cout << "\tRight Child: \tSocial Security: " << ptr->right->socialSecurity
			<< "\n\t\t\tName: " << ptr->right->name
			<< "\n\t\t\tOccupation: " << ptr->right->occupation
			<< endl;
		cout << "#################################################\n";
	}
	else
	{
		cout << "Social Security " << socialSecurity << " is not in the tree\n";
	}
}

BTree::node* BTree::ReturnNode(int socialSecurity)
{
	return ReturnNodePrivate(socialSecurity, root);
}

BTree::node* BTree::ReturnNodePrivate(int socialSecurity, BTree::node* ptr)
{
	if (ptr != NULL)
	{
		if (ptr->socialSecurity == socialSecurity)
			return ptr;
		else
		{
			if (socialSecurity < ptr->socialSecurity)
				return ReturnNodePrivate(socialSecurity, ptr->left);
			else
				return ReturnNodePrivate(socialSecurity, ptr->right);
		}
	}
	else
	{
		return NULL;
	}
}

string BTree::ReturnRootName()
{
	if (root != NULL)
		return root->name;
	else
	{
		return "ROOTEMPTY";
	}
}