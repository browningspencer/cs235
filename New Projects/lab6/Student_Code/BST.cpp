#include "BST.h"

using namespace std;

BST::BST() : root(NULL) {
  //cout << "INIT" << endl;
  //root->info = 0;
  //root->left = NULL;
  //root->right = NULL;
}
BST::~BST() {
  //cout << "DECON" << endl;
  clear();
}

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * BST::getRootNode() {
  return root;
}



bool BST::finder(Node *&leaf, int& value, bool& found) {
  if (found == true) {
    return found = true;
  }
  else if (root == NULL) {
    return found = false;
  }
  else if (leaf == NULL) {
    return found = false;
  }
  else if (value == leaf->info) {
    return found = true;
  }
  else if (value < leaf->info) {
    finder(leaf->left, value, found);
  }
  else if (value >= leaf->info) {
    finder(leaf->right, value, found);
  }
  return found;
}

Node * BST::find (int& value, bool& found) {
  Node *leaf = root;

  finder(leaf, value, found);

  return leaf;
}
/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
Node * BST::insert(Node *&leaf, int& data) {
  if (root == NULL) {
    root = new(struct Node);
    root->info = data;
    root->left = NULL;
    root->right = NULL;
    leaf = root;
  }
  else if (leaf == NULL) {
    leaf = new (struct Node);
    leaf->info = data;
    leaf->left = NULL;
    leaf->right = NULL;
  }
  else if (data < leaf->info) {
    leaf->left = insert(leaf->left, data);
  }
  else if (data >= leaf->info) {
    leaf->right = insert(leaf->right, data);
  }
  return leaf;
}



bool BST::add(int data) {
  //cout << "ADD" << endl;
  Node *leaf = root;
  bool found = false;

  if (finder(leaf, data, found)) {
    //cout << "FALSE" << endl;
    return false;
  }
  else {
    insert(leaf, data);
    //cout << "TRUE" << endl;
    return true;
  }

}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
Node * BST::remover(Node *&leaf, int& data) {
  if (root == NULL) {
    return leaf;
  }
  else if (leaf == NULL) {
    return leaf;
  }
  else if (data < leaf->info) {
    //cout << "LEFT" << endl;
    leaf->left = remover(leaf->left, data);
  }
  else if (data > leaf->info) {
    //cout << "RIGHT" << endl;
    leaf->right = remover(leaf->right, data);
  }
  else {
    //cout << "EXACT\t" << leaf->info << endl;
    if (leaf->left == NULL && leaf->right == NULL) {
      //cout << "NULL CHILDREN" << endl;
      if (root == leaf) {
        root = NULL;
      }
      delete leaf;
      leaf = NULL;
    }
    else if (leaf->left == NULL) {
      //cout << "NULL LEFT" << endl;
      Node *temp = leaf->right;
      leaf->info = temp->info;
      leaf->left = temp->left;
      leaf->right = temp->right;
      delete temp;
    }
    else if (leaf->right == NULL) {
      //cout << "NULL RIGHT\t" << leaf->left->info << endl;
      Node *temp = leaf->left;
      leaf->info = temp->info;
      leaf->left = temp->left;
      leaf->right = temp->right;
      delete temp;
    }
    else {
      //cout << "LEFT & RIGHT CHILDREN" << endl;
      Node *x = leaf->left;
      while (x->right != NULL) {
        x = x->right;
      }
      leaf->info = x->info;
      remover(leaf->left, leaf->info);
    }
    return leaf;
  }
  return leaf;
}

bool BST::remove(int data) {
  //cout << "REMOVE" << endl;
  Node *leaf = root;
  bool found = false;

  if (finder(leaf, data, found)) {
    remover(leaf, data);
    return true;
  }
  else {
    return false;
  }
}



/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
Node * BST::clearer(Node *&leaf) {
  while (root != NULL) {
    if (leaf->left == NULL && leaf->right == NULL) {
      if (root == leaf) {
        root = NULL;
      }
      delete leaf;
      leaf = NULL;
      break;
    }
    else if (leaf->left != NULL) {
      leaf->left = clearer(leaf->left);
    }
    else if (leaf->right != NULL) {
      leaf->right = clearer(leaf->right);
    }
  }
  return leaf;
}

void BST::clear() {
  Node *leaf = root;

  clearer(leaf);
}
