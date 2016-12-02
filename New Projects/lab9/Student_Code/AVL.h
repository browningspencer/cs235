#pragma once

#include "AVLInterface.h"
#include "Node.h"
#include <iostream>

using namespace std;

class AVL : public AVLInterface {

private:
  Node* root;

public:
	AVL();
	virtual ~AVL();

  int height(Node *&temp);
  int diff(Node *&temp);
  Node *rr(Node *&leaf);
  Node *ll(Node *&leaf);
  Node *lr(Node *&leaf);
  Node *rl(Node *&leaf);
  Node *balance(Node *&leaf);

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	 * Returns the root node for this tree
	 *
	 * @return the root node for this tree.
	 */
	NodeInterface * getRootNode();

  bool finder(Node *&leaf, int& value, bool& found);

  Node * find(int& value, bool& found);

	/*
	 * Attempts to add the given int to the AVL tree
	 * Rebalances the tree if data is successfully added
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */
   Node * insert(Node *&leaf, int& data);

	bool add(int data);

	/*
	 * Attempts to remove the given int from the AVL tree
	 * Rebalances the tree if data is successfully removed
	 *
	 * @return true if successfully removed
	 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
	 */
   Node * remover(Node *&leaf, int& data);

	bool remove(int data);


  Node * clearer(Node *&leaf);

  void clear();
};
