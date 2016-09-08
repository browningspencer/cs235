//
//  AVL.cpp
//  lab_6
//
//  Created by Spencer Browning on 8/1/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "AVL.h"

/*
using namespace std;

//Indices into a subtree array
enum dir_t { LEFT = 0, RIGHT = 1 };

//Reutnr the minumum of two numbers
inline int MIN(int a, int b) { return (a < b) ? a : b; }

//return the maximum of two numbers
inline int MAX (int a, int b ) { return ( a > b) ? a : b; }

//Note that RotateLeft and RotateRight are *static* member
//functions because otherwise they would have to re-assign
//to the "this" pointer.

template <class KeyType>
void
AVL<KeyType>::RotateLeft(AVL<KeyType> * & root) {
    AVL<KeyType> * oldRoot = root;
    
    //perform rotation
    root = root->mySubtree[RIGHT];
    oldRoot->mySubtree[RIGHT] = root->mySubtree[LEFT];
    root->mySubtree[LEFT] = oldRoot;
    
    //update balances
    oldRoot->myBal -= (1 + MAX(root->myBal, 0));
    root->myBal -= (1 - MIN(oldRoot->myBal, 0));
}

template <class KeyType>
void
AVL<KeyType>::RotateRight(AVL<KeyType> * & root) {
    AVL<KeyType> * oldRoot = root;
    
    //perform rotation
    root = root->mySubtree[LEFT];
    oldRoot->mySubtree[LEFT] = root->mySubtree[RIGHT];
    root->mySubtree[RIGHT] = oldRoot;
    
    //update balances
    oldRoot->myBal += (1 - MIN(root->myBal, 0));
    root->myBal += (1 + MAX(oldRoot->myBal, 0));
}

//RotateTwice -- static member function to rotate a given node
// for the given direction and then the opposite
//direction to restore the balance of an AVL tree
//Return 1 if the tree height changes due to rotation,
//otherwise return 0.

template <class KeyType>
void
AVL<KeyType>::RotateTwice(AVL<KeyType> * & root, dir_t dir) {
    dir_t otherDir = Opposite(dir);
    RotateOnce(root->mySubtree[otherDir], otherDir);
    RotateOnce(root, dir);
}
*/

/*
int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int avlTree::diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation(parent);
}

avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

avl_node *avlTree::insert(avl_node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

void avlTree::display(avl_node *ptr, int level)
{
    int i = 0;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "       ";
        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}

void avlTree::inorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout << tree->data << " ";
    inorder (tree->right);
}

void avlTree::preorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    cout << tree->data << " ";
    preorder (tree->left);
    preorder (tree->right);
}

void avlTree::postorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    postorder (tree->left);
    postorder(tree->right);
    cout << tree->data << " ";
}

 */

