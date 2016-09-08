//
//  LinkedList.h
//  lab_5
//
//  Created by Spencer Browning on 7/18/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

/*
 
 
 private:
 struct Node
 {
 Node (ItemType, _data, Node*, _next = NULL, Node* prev = NULL) : data(_data), next(_next), prev(_prev)
    ItemType data;
    Node* next;
    Node* prev;
 }
 
 
 
 
 // this how you can call it??
 new Node(data)
    Node(data, next)
    Node(data, next, prev)
 
 */

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
#pragma once

using namespace std;

template <typename ItemType> //ItemType is not reserved (it can be anything you want as long as you are consistant)

class LinkedList {
    
private:
    struct Node {
        //Node (ItemType, ItemType data, Node*, next = NULL, Node* prev = NULL) : data(_data), next(_next), prev(_prev))
        ItemType info;
        //ItemType item;
        Node* next;
        Node* prev;
        
    }/**start*/;
    
    int count;
    Node* head;
    Node* tail;
    
    
public:
    LinkedList() :
        count (0),
        head(NULL),
        tail(NULL)
    { /*start = NULL;*/ }
    
    int size() const {

        return count;
    }
    
//********************************************************************************************
    void create_list(int item)
    {
        head->prev = NULL;
        tail->next = NULL;
        /*
        struct Node *s, *temp;
        temp = new(struct Node);
        temp->info = item;
        temp->next = tail;

        
        if (head == NULL)
        {
            temp->prev = head;
            head = temp;
        }
        else
        {
            s = head;
            while (s->next != NULL)
                s = s->next;
            s->next = temp;
            temp->prev = s;
        }
        */
    }
    
    
//********************************************************************************************
    void inserter(int& index, const ItemType& item)
    {
        /*
        if (head == NULL)
        {
            //std::cout << "list empty" << std::endl;
            return;
        }
         */
        
        
        struct Node *temp, *q;
        q = head;
        temp = new(struct Node);
        temp->info = item;
        
        if (count == 0)
        {
            temp->prev = NULL;
            temp->next = NULL;
            head = temp;
            tail = temp;
            
            count++;
            return;
        }
        else if (index == 0)
        {
            q->prev = temp;
            temp->next = q;
            temp->prev = NULL;
            head = temp;
            
            count++;
            return;
        }
        
        
        for (int i = 0; i < index; i++)
        {
            if (q->next != NULL)
                q = q->next;
            
        }
        
        
        if (q->next == NULL && index == count)
        {
            q->next = temp;
            temp->next = NULL;
            tail = temp;
            temp->prev = q;
            
        }
        
        else
        {
            Node *x = q;
            
            q = q->prev;
            
            q->next = temp;
            temp->prev = q;
            temp->next = x;
            x->prev = temp;
            
        }
        
        count++;
    }
    
    void insert(ItemType item)
    {
        int index = count;
        inserter(index, item);
    }

    
//********************************************************************************************
    LinkedList(const LinkedList& linkedlist) {
        
    }
    
    
//********************************************************************************************
    void clear()
    {
        Node *del = head;
        
        while (head != NULL) {
            
            del = head;
            head = head->next;
            delete del;
            
        }
        
        tail = NULL;
        head = NULL;
        
        count = 0;
        
    }

    
//********************************************************************************************

    ItemType remove(int index) {
        
        
        
        ItemType value;
        Node *q = head;
        
        if (count == 1)
        {
            ///std::cout << "Nothing to Remove" << std::endl;
            value = q->info;
            
            delete q;
            
            head = NULL;
            tail = NULL;
            
            count--;
            return value;
        }
        else if (index == 0)
        {
            Node *temp;
            temp = q;
            value = temp->info;
            
            q = q->next;
            q->prev = NULL;
            head = q;
            delete temp;
            
            count--;
            return value;
        }
        
        for (int i = 0; i < index; i++)
        {
            if (q->next != NULL)
                q = q->next;
        }
        
        if (q->next == NULL) {
            Node *temp = q;
            value = temp->info;
            
            q = q->prev;
            q->next = NULL;
            tail = q;
            delete temp;
            
        }
        else {
            Node *temp = q;
            Node *x = q;
            value = temp->info;
            
            q = q->prev;
            x = x->next;
            q->next = x;
            x->prev = q;
            delete temp;
            
        }
        count--;
        return value;
    }
    
//********************************************************************************************
    
    int find_index ( ItemType& item )
    {
        Node *temp = head;
        
        int iter = 0;
        while (temp != NULL) {
            if (temp->info == item) {
                return iter;
            }
        }
    }
    
    
//********************************************************************************************
    int find ( ItemType& item )
    {
        //head = start;
        Node *temp = head;
        
        int iter = 0;
        
        while (temp != NULL) {
            if (temp->info == item ) {
                //cout << "Find:head: " << head->info << endl;
                return iter;
            }
            iter++;
            temp = temp->next;
            
        }
        
        //std::cout << "Item: " << item << " not found" << std::endl;
        return -1;
    }
    
    
//********************************************************************************************
    void print(int& index, std::string& word, std::ofstream& output)
    {
        int pos = 0;
        Node *q;
        if (head == NULL)
        {
            //std::cout << "List empty, nothing to display" << std::endl;
            return;
        }
        q = head;
        //std::cout << "\nList: " << std::endl;
        
        
        for (pos = 0; pos < count; pos++)
        {
            if (pos % 8 == 0 && pos != 0) {
                //cout << endl;
                output << endl;
                //cout << "hash " << index << ":";
                output << "hash " << index << ":";
            }
            word = q->info;
            
            //std::cout << " " << word;
            output << " " << word;
            q = q->next;
            
            //pos++;
        }
        //std::cout << "NULL" << std::endl;
        return;
    }
    
    
    
    
    ~LinkedList() {
        clear();
        
        
    }
    
    
};


#endif /* LinkedList_h */
