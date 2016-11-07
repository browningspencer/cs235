#pragma once

#include <iostream>
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {

private:
  Node* root;

public:
	BST();
	~BST();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode();

  bool finder(Node *&leaf, int& value, bool& found);

  Node * find (int& value, bool& found);


	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
  Node * insert(Node *&leaf, int& data);

	bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
  Node * remover(Node *&leaf, int& data);

	bool remove(int data);



	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
  Node * clearer(Node *&leaf);

	void clear();
};
