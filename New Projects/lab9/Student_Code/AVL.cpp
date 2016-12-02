#include "AVL.h"

using namespace std;


AVL::AVL() : root(NULL) {}
AVL::~AVL() {
  clear();
}


int AVL::height(Node *&temp) {
  int h = 0;
  if (temp != NULL) {
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int max_height = max(l_height, r_height);
    h = max_height + 1;
  }
  return h;
}

int AVL::diff(Node *&temp) {
  int l_height = height(temp->left);
  int r_height = height(temp->right);
  int b_factor = l_height - r_height;
  return b_factor;
}

Node *AVL::rr(Node *&leaf) {
  Node *temp;
  temp = leaf->right;
  leaf->right = temp->left;
  temp->left = leaf;
  return temp;
}

Node *AVL::ll(Node *&leaf) {
  Node *temp;
  temp = leaf->left;
  leaf->left = temp->right;
  temp->right = leaf;
  return temp;
}

Node *AVL::lr(Node *&leaf) {
  Node *temp;
  temp = leaf->left;
  leaf->left = rr(temp);
  return ll(leaf);
}

Node *AVL::rl(Node *&leaf) {
  Node *temp;
  temp = leaf->right;
  leaf->right = ll(temp);
  return rr(leaf);
}

Node *AVL::balance(Node *&leaf) {
  if (leaf == NULL)
    return leaf;
  int b_factor = diff(leaf);
  if (b_factor > 1) {
    if (diff(leaf->left) >= 0)
      leaf = ll(leaf);
    else
      leaf = lr(leaf);
  }
  else if (b_factor < -1) {
    if (diff(leaf->right) > 0)
      leaf = rl(leaf);
    else
      leaf = rr(leaf);
  }
  if (root != leaf)
    root = leaf;
  return leaf;
}


/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface * AVL::getRootNode() {
  return root;
}


bool AVL::finder(Node *&leaf, int& value, bool& found) {
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

Node * AVL::find(int& value, bool& found) {
  Node *leaf = root;

  finder(leaf, value, found);

  return leaf;
}


/*
 * Attempts to add the given int to the AVL tree
 * Rebalances the tree if data is successfully added
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
Node * AVL::insert(Node *&leaf, int& data) {
  if (root == NULL) {
    root = new(struct Node);
    root->info = data;
    root->left = NULL;
    root->right = NULL;
    leaf = root;
  }
  else if (leaf == NULL) {
    leaf = new(struct Node);
    leaf->info = data;
    leaf->left = NULL;
    leaf->right = NULL;
  }
  else if (data < leaf->info) {
    leaf->left = insert(leaf->left, data);
    leaf = balance(leaf);
  }
  else if (data >= leaf->info) {
    leaf->right = insert(leaf->right, data);
    leaf = balance(leaf);
  }
  return leaf;
}

bool AVL::add(int data) {
  Node *leaf = root;
  bool found = false;

  if (finder(leaf, data, found)) {
    return false;
  }
  else {
    insert(leaf, data);
    return true;
  }
}

/*
 * Attempts to remove the given int from the AVL tree
 * Rebalances the tree if data is successfully removed
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
Node * AVL::remover(Node *&leaf, int& data) {
  if (root == NULL) {
    return leaf;
  }
  else if (leaf == NULL) {
    return leaf;
  }
  else if (data < leaf->info) {
    leaf->left = remover(leaf->left, data);
  }
  else if (data > leaf->info) {
    leaf->right = remover(leaf->right, data);
  }
  else {
    if (leaf->left == NULL && leaf->right == NULL) {
      if (root == leaf) {
        root = NULL;
      }
      delete leaf;
      leaf = NULL;
    }
    else if (leaf->left == NULL) {
      Node *temp = leaf->right;
      leaf->info = temp->info;
      leaf->left = temp->left;
      leaf->right = temp->right;
      delete temp;
    }
    else if (leaf->right == NULL) {
      Node *temp = leaf->left;
      leaf->info = temp->info;
      leaf->left = temp->left;
      leaf->right = temp->right;
      delete temp;
    }
    else {
      Node *x = leaf->left;
      while (x->right != NULL) {
        x = x->right;
      }
      leaf->info = x->info;
      remover(leaf->left, leaf->info);
    }
    leaf = balance(leaf);
    return leaf;
  }
  leaf = balance(leaf);
  return leaf;
}

bool AVL::remove(int data) {
  Node *leaf = root;
  bool found = false;
  if (finder(leaf, data, found)) {
    remover(leaf, data);
    //rebalance the tree
    return true;
  }
  else {
    return false;
  }
}


Node * AVL::clearer(Node *&leaf) {
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


void AVL::clear() {
  Node *leaf = root;

  clearer(leaf);
}
