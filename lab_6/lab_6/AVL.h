//
//  AVL.h
//  lab_6
//
//  Created by Spencer Browning on 8/1/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

/*
Build an AVL Tree Set

5 commands
    clear
    add
    print
    find
    remove

1. Use the command reader from project 5 and modify it
2. Get Print function working

EXAMPLE

    CLEAR
    add bob

        bob

    add joe

        bob
         \
         Joe

    add jim

        bob
         \
         Joe
         /
      Jim

    Now it needs to be rotated

        jim
        / \
    bob		joe

    print
        level 0: jim(2)

            Use a Linked List<Node*>
            Add Root to Q
            While Q not empty
                output level number
                size = Q.size
                loop size times
                Remove n from Q
                Output n.item
                add n's children to Q //Don't add if it's NULL
            end while

    Balance
        BAL (&n)
            if height(n.left)-hieght(n.right) > 1
                BALR (n) //balance right
            else if height(n.right) - height(n.left) > 1
                BALL(n)


        BALRight(n)
            if height(n.left.right) > height(n.left.left)
                RL(n.left)
            RR(n)
*/

#ifndef AVL_h
#define AVL_h

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "LinkedList.h"
#pragma once

using namespace std;

template <typename T>

class AVL {
    
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height = 0;
    };
    
    Node* root;

public:
    AVL() :
        root(NULL)
    {}
    
    Node *getRoot() { return root; }
    
//********************************************************************************************
//                                *** HEIGHT ***
//********************************************************************************************

    int height (Node *&temp)
    {
        //cout << "HEIGHT" << endl;
        int h = 0;
        if (temp != NULL)
        {
            //cout << "temp != NULL" << endl;
            int l_height = height (temp->left);
            int r_height = height (temp->right);
            int max_height = max (l_height, r_height);
            h = max_height + 1;
        }
        //cout << "H: " << h << endl;
        return h;
    }
    
//********************************************************************************************
//                          *** DIFFERENCE IN HEIGHT ***
//********************************************************************************************

    
    int diff(Node *&temp)
    {
        //cout << "DIFF" << endl;
        int l_height = height (temp->left);
        //cout << "l_height: " << l_height << endl;
        int r_height = height (temp->right);
        //cout << "r_height: " << r_height << endl;
        int b_factor = l_height - r_height;
        //int b_factor = r_height - l_height;
        return b_factor;
    }

    
//********************************************************************************************
//                            *** RIGHT ROTATION ***
//********************************************************************************************
    
    Node *rr (Node *&leaf)
    {
        //cout << "RR" << endl;
        Node *temp;
        temp = leaf->right;
        leaf->right = temp->left;
        temp->left = leaf;
        return temp;
    }
    
//********************************************************************************************
//                            *** LEFT ROTATION ***
//********************************************************************************************
    
    Node *ll (Node *&leaf)
    {
        //cout << "LL" << endl;
        Node *temp;
        temp = leaf->left;
        leaf->left = temp->right;
        temp->right = leaf;
        return temp;
    }

//********************************************************************************************
//                         *** LEFT-RIGHT ROTATION ***
//********************************************************************************************
    
    Node *lr (Node *&leaf)
    {
        //cout << "LR" << endl;
        Node *temp;
        temp = leaf->left;
        leaf->left = rr(temp);
        return ll(leaf);
    }
    
//********************************************************************************************
//                         *** RIGHT-LEFT ROTATION ***
//********************************************************************************************
    
    Node *rl (Node *&leaf)
    {
        //cout << "RL" << endl;
        Node *temp;
        temp = leaf->right;
        leaf->right = ll(temp);
        return rr(leaf);
    }
    
//********************************************************************************************
//                               *** BALANCE ***
//********************************************************************************************

    Node *balance (Node *&leaf)
    {
        //cout << "BALANCE" << endl;
        if (leaf == NULL)
            return leaf;
        int b_factor = diff(leaf);
        if (b_factor > 1)
        {
            //cout << "B > 1" << endl;
            if (diff(leaf->left) >= 0)
                leaf = ll(leaf);
            else
                leaf = lr(leaf);
        }
        else if (b_factor < -1)
        {
            //cout << "B < -1" << endl;
            if (diff(leaf->right) > 0)
                leaf = rl(leaf);
            else
                leaf = rr(leaf);
        }
        
        if (root != leaf)
            root = leaf;
        return leaf;
    }
    
//********************************************************************************************
//                               *** CLEAR ***
//********************************************************************************************

    Node *clearer(Node *&leaf)
    {
        while (root != NULL) {
            if (leaf->left == NULL && leaf->right == NULL)
            {
                if (root == leaf) {
                    root = NULL;
                }
                delete leaf;
                leaf = NULL;
                break;
            } else if (leaf->left != NULL) {
                leaf->left = clearer(leaf->left);
            } else if (leaf->right != NULL) {
                leaf->right = clearer(leaf->right);
            }
        }
        return leaf;
    }
    
    void clear()
    {
        Node *leaf = root;
        
        clearer(leaf);
        
    }
    
//********************************************************************************************
//                              *** FIND ***
//********************************************************************************************

    bool finder( Node *&leaf, T& value, bool& found )
    {
        if (found == true) {
            //cout << "U" << endl;
            return found = true;
        }
        else if (root == NULL) {
            //cout << "RETURNED FALSE" << endl;
            //cout << "V" << endl;
            return found = false;
        }
        else if (leaf == NULL) {
            //cout << "W" << endl;
            return found = false;
        }
        else if (value == leaf->data) {
            //cout << "X" << endl;
            return found = true;
        }
        else if (value < leaf->data) {
            //cout << "Y" << endl;
            //cout << "FIND LEFT" << endl;
            finder(leaf->left, value, found);
        }
        else if (value >= leaf->data) {
            //cout << "Z" << endl;
            //cout << "FIND RIGHT" << endl;
            finder(leaf->right, value, found);
        }
        
        return found;
    }
    
    Node *find( T& value, bool& found )
    {
        Node *leaf = root;
        
        finder(leaf, value, found);
        
        return leaf;
    }
    
//********************************************************************************************
//                          *** INSERT ***
//********************************************************************************************
    
    Node *insert( Node *&leaf, T& value )
    {
        bool found = false;
        if (finder(leaf, value, found))
            return leaf;
        if (root == NULL)
        {
            //cout << "ROOT" << endl;
            root = new(struct Node);
            root->data = value;
            root->height += 1;
            root->left = NULL;
            root->right = NULL;
            leaf = root;
            //cout << "data: " << leaf->data << "\theight: " << leaf->height << endl;
        }
        else if (leaf == NULL)
        {
            //cout << "LEAF" << endl;
            leaf = new (struct Node);
            leaf->data = value;
            leaf->height += 1;
            leaf->left = NULL;
            leaf->right = NULL;
            //cout << "data: " << leaf->data << "\theight: " << leaf->height << endl;
        }
        else if (value < leaf->data)
        {
            //cout << "LEFT" << endl;
            leaf->left = insert(leaf->left, value);
            leaf = balance(leaf);
        }
        else if (value >= leaf->data)
        {
            //cout << "RIGHT" << endl;
            leaf->right = insert(leaf->right, value);
            leaf = balance(leaf);
        }
        //cout << "END" << endl;
        return leaf;
    }
    
    Node *add( T& value )
    {
        Node *leaf = root;
        
        insert(leaf, value);
        
        return leaf;
    }
    
//********************************************************************************************
//                            *** FIND MINUMUM LEAF ***
//********************************************************************************************
    
    void findMin(Node *&leaf, Node *&n)
    {
        //Node *temp;
        if (n == NULL) {
            cout << "HERE" << endl;
            return;
        }
        if (n->left != NULL)
            findMin(leaf, n->left);
        else if (n == leaf->right) {
            //cout << "HERE " << leaf->data << endl;
            leaf->right = n->right;
            leaf->data = n->data;
            delete n;
        }
        else //(n->left == NULL)
        {
            //cout << "ABC" << endl;
            leaf->data = n->data;
            Node *temp = n;
            n = n->right;
            delete temp;
        }
        leaf = balance(leaf);
        /*
        //cout << "FINDMIN" << endl;
        //if (leaf == NULL)
            //cout << "NULL" << endl;
        Node *temp;
        while (leaf->left != NULL) {
            temp = leaf;
            leaf = leaf->left;
            //cout << "FINDMIN" << endl;
        }
        temp->left = leaf->right;
        */
        //delete temp;
        
        // CALL BALANCE AT THE END?? so either delete temp here or later
        //return temp;
    }
    

//********************************************************************************************
//                            *** REMOVE ***
//********************************************************************************************

    Node *removeCases( Node *&leaf, T& value )
    {
        //Node *temp = leaf;
        //cout << "HERE" << endl;
        if (leaf->left == NULL && leaf->right == NULL) {
            //cout << "W" << endl;
            if (root == leaf)
            {
                //cout << "ROOT" << endl;
                root = NULL;
            }
            //cout << "WW" << endl;
            delete leaf;
            leaf = NULL;
           
            //cout << root->data << endl;
        } else if (leaf->left == NULL) {
            //cout << "X" << endl;
            Node *temp = leaf->right;
            leaf->data = temp->data;
            delete temp;
            leaf->right = NULL;
        } else if (leaf->right == NULL) {
            //cout << "Y" << endl;
            Node *temp = leaf->left;
            leaf->data = temp->data;
            delete temp;
            leaf->left = NULL;
        } else {
            //cout << "Z" << endl;
            Node *x = leaf->right;
            
            //findMin(leaf, x);
            
            while (x->left != NULL) {
                //temp = x;
                x = x->left;
                //cout << "FINDMIN" << endl;
            }
            leaf->data = x->data;
            remover(leaf->right, leaf->data);
            
            //leaf->right = remover(leaf->right, temp->data);
        }
        //cout << "HERE" << endl;
        //if (leaf == NULL)
            //cout << "NULL" << endl;
        leaf = balance(leaf);
        //balance(leaf);
        return leaf;
    }
    
    Node *remover( Node *&leaf, T& value )
    {
        if (root == NULL) {
            //cout << "NULL ROOT" << endl;
            return leaf;
        }
        else if (leaf == NULL ) {
            //cout << "NULL LEAF" << endl;
            return leaf;
        }
        else if(value < leaf->data) {
            
            leaf->left = remover(leaf->left, value);
            //cout << "REMOVE LEFT" << endl;
            leaf = balance(leaf);
        }
        else if(value > leaf->data) {
            
            leaf->right = remover(leaf->right, value);
            //cout << "REMOVE RIGHT" << endl;
            leaf = balance(leaf);
        }
        else {
            removeCases(leaf, value);
            leaf = balance(leaf);
        }
        leaf = balance(leaf);
        return leaf;
    }
    
    Node *remove( T& value )
    {
        Node *leaf = root;
        remover(leaf, value);
        //balance(root);
        return leaf;
    }

//********************************************************************************************
//                            *** PRINT ***
//********************************************************************************************
/*
    void print( Node *leaf, int level, T& value, ofstream& output )
    {
        //cout << "HERE" << endl;
        if (root == NULL) {
            //cout << "NULL ROOT" << endl;
            return;
        }
        else if (leaf == NULL) {
            //cout << "NULL LEAF" << endl;
            return;
        }
        else
        {
            value = leaf->data;
            leaf->height = height(leaf);
            
            
            cout << "level " << level << ": " << value << "(" << leaf->height << ")" << endl;
            print(leaf->left, level + 1, value, output);
            print(leaf->right, level + 1, value, output);
        }
    }
   */
    void print2(ofstream& output, int& i, int& size, int& front, LinkedList<Node*>& Q, bool& x, int& level )
    {
        for ( i = 0; i < size; i++)
        {
            Node *leaf = Q.remove(front);
            leaf->height = height(leaf);
            if (i % 8 == 0 && i != 0) { //x == true
                x = false;
                output << endl;
                output << "level " << level << ":";
                //cout << endl;
                //cout << "level " << level << ":";
            }
            output << " " << leaf->data << "(" << leaf->height << ")";
            //cout << " " << leaf->data << "(" << leaf->height << ")";
            if (leaf->left != NULL)
                Q.insert(Q.size(), leaf->left);
            if (leaf->right != NULL)
                Q.insert(Q.size(), leaf->right);
        }

    }
    
    void print(ofstream& output )
    {
        if (root == NULL)
            return;
        //cout << "PRINT: " << root->data << endl;
        LinkedList<Node*> Q;
        int front = 0;
        int size = 0;
        int i = 0;
        int level = 0;
        if (root == NULL){
            return;
        }
        Q.insert(Q.size(), root);
        while (Q.size() != 0)
        {
            size = Q.size();
            output << "level " << level << ":";
            bool x = false;
            if (i > 7 || size > 8)
                x = true;
            
            print2(output, i, size, front, Q, x, level );
            
            output << endl;
            //cout << endl;
            level++;
        }
    }
    /*
    Using a Q or my LinkedList
     print () {
        Q.add root
        while(!Q.empty) {
            Q.top()
            Q.add (root->left)
            Q.add (root->right)
        }
     }
    */
/*
 if (root != NULL)
    while (!empty)
        size = queue.size()
        for (i < size)
            remove front
            cout info of front
            if (left child !=NULL)
                add left queue
            if (right child != NULL)
                add right queue
     
 
 Temp
    level 0: bob(3)
    level 1: joe(2)
    level 2: jim(1)
    
 Correct
    level 0: jim(2)
    level 1: bob(1) joe(1)
*/
//********************************************************************************************
    
    ~AVL() {
        clear();
    }
};




#endif /* AVL_h */

