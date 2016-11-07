#pragma once

#include <iostream>
#include "NodeInterface.h"

using namespace std;

class Node : public NodeInterface {
  friend class BST;

private:
    int info = 0;
    Node* left;
    Node* right;


public:
	Node();
	~Node();

  Node *getRoot();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData();

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild();

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild();

};
