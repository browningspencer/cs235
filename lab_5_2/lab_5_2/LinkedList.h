//
//  LinkedList.h
//  lab_5_2
//
//  Created by Spencer Browning on 7/29/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h


#include <iostream>
#include <string>
#pragma once

using namespace std;

template <typename T>
class LinkedList {
    
private:
    struct Node {
        T item;
        Node* next;
        Node* prev;
        
        Node(const T& item_data, Node* next_ptr = NULL) : item(item_data), next(next_ptr) {}
    };
    Node* head;
    Node* tail;
    Node* n;
    int size;
    
public:
    LinkedList() :
        head (NULL),
        tail (NULL),
        size (0)
    { head = NULL; }
    const int FOUND = 1;
    const int NOTFOUND = 0;
    int found_status = 0;
    

//************************************************************************************************************
    
    LinkedList( const LinkedList& linkedlist) { }
    
//************************************************************************************************************
    
    void create_list( )
    {
        n = new Node;
        n->item = 1;
        n->prev = NULL;
        head = n;
        tail = n;
        
        n = new Node;
        n->item = 2;
        n->prev = tail; //2 points to 1
        tail->next = n; //1 points to 2
        tail = n; //points tail to 2
        
        tail->next = NULL;
    }
    
//************************************************************************************************************
    
    void clear()
    {
        if (head == NULL)
            head = head->next;
        while (head != NULL) {
            cout << "W" << endl;
            Node* q = head->next;
            cout << "X" << endl;
            delete head;
            cout << "Y" << endl;
            head = q;
            cout << "Z" << endl;
            delete q;
        }
        cout << "1HERE" << endl;
    }
    
//************************************************************************************************************
    
    T AtIndex(int& index)
    {
        int count = 0;
        Node* q = head;
        while (count < index)
        {
            count++;
            q = q->next;
        }
        return q->item; //possibly just q?
    }
    
   
//************************************************************************************************************

    void insert(int& index, T value)
    {
        if (head == NULL)
            return;
        
        Node* q;
        Node* temp;
        q = head;
        
        for (unsigned int i = 0; i < index; i++) {
            q = q->next;
            if (q == NULL)
                return;
        }
        
        temp = new Node(value, NULL);
        
        if (q->next == NULL) {
            q->next = temp;
            temp->next = NULL;
            temp->prev = q;
        }
        else {
            temp->next = q->next;
            temp->next->prev = temp;
            q->next = temp;
            temp->prev = q;
        }
        
        size++;
    }

//************************************************************************************************************
    
    T remove(int& index)
    {
        Node* q = head;
        T value = AtIndex(index);
        
        if (q->item == value) {
            head = q->next;
            delete q;
            return value;
        }
        while (q != NULL && q->next != NULL)
        {
            if (q->next->item == value)
            {
                Node * del = q->next;
                q->next = q->next->next;
                delete del;
                return value;
            }
            q = q->next;
        }
        clear();
        return value;
    }
    
//************************************************************************************************************

    Node* finder(T value)
    {
        Node* q = head;
        while (q != NULL)
        {
            if (value == q->item)
            {
                return found_status = FOUND;
            }
            q = q->next;
        }
        return found_status = NOTFOUND;
    }
    
//************************************************************************************************************
    
    int find( T& value)
    {
        Node* q = head;
        Node* temp = head;
        
        int iter = 0;
        
        while (temp != NULL) {
            if (value == q->item) {
                delete q;
                delete temp;
                return iter - 1;
            }
            iter++;
            temp = temp->next;
        }
        delete q;
        delete temp;
        return -1;
    }
    
//************************************************************************************************************
    
    void print(int& index, string& value, ofstream& output)
    {
        int pos = 0;
        Node* q = head;
        if (head == NULL)
            return;
        
        while (pos <= size - 1) {
            q = q->next;
            value = q->item;
            index = pos;
            
            //output << "node " << index << ": " << value << endl;
            cout << "node " << index << ": " << value << endl;
            
            pos ++;
        }
        return;
    }
    
//************************************************************************************************************
    
    
    ~LinkedList() { clear(); }
};




#endif /* LinkedList_h */
