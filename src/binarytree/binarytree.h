#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

namespace BT_std
{
	class BTree			// Binary Tree
	{
	private:
		struct node
		{
			int socialSecurity;
			string name;
			string occupation;
			node* left;
			node* right;
		};

		// Pointer to the root of the tree
		node* root;

		// Creates a new leaf and returns it
		node* CreateLeaf(int socialSecurity, string name, string occupation);

		// Adds leaf(created from CreateLeaf function)
		// to the binary tree.  
		void AddLeafPrivate(int socialSecurity, string name, string occupation, node* ptr);

		// Prints contents of tree IN-ORDER
		void PrintInOrderPrivate(node* ptr);

		// Calls 'ReturnNodePrivate'
		node* ReturnNode(int socialSecurity);

		// returns node with desired socialSecurity
		node* ReturnNodePrivate(int socialSecurity, node* ptr);

		// Finds smallest 'socialSecurity' in the tree
		int FindSmallestPrivate(node* ptr);

		// Finds the node with the smallest socialSecurity
		node* FindSmallestNodePrivate(node* ptr);

		//
		void RemoveNodePrivate(int socialSecurity, node* parent);

		//
		void RemoveRootMatch();

		//
		void RemoveMatch(node* parent, node* match, bool left);

		//
		void RemoveSubtree(node* ptr);

	public:
		// Contructor
		BTree();

		// Destructor
		~BTree();

		// Calls 'AddLeafPrivate'
		void AddLeaf(int socialSecurity, string name, string occupation);

		// Calls 'PrintInOrderPrivate'
		void PrintInOrder();

		// Returns name of the root of the tree
		string ReturnRootName();

		// Print children of node with desired socialSecurity
		void PrintChildren(int socialSecurity);

		// Calls private version
		int FindSmallest();

		//
		void RemoveNode(int socialSecurity);
	};
}

#endif //BINARYTREE_H
