//
//  HashSet.h
//  lab_7
//
//  Created by Spencer Browning on 7/28/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

/*
 You have to use an indexed Array for the hash table of buckets and each bucket is a LinkedList
 
 You don't really need to have a hash function for Student or could just do strings


bool Find (ItemType
    bool (is the value there or not)
    will be used in the insert and remove functions
    if (empty)
        return false
    unsigned int index = HashCode(value) //HashCode() returns the index of a value
    return table[index or hash(value)].find(value) != -1; //second find is the LinkedList Find
 
 
 
void Print
    For Each Bucket
        Print Hash
        for each item in the bucket
            output item
        ex
            for (unsigned int i = 0; i < capacity; i++)
                hash i : _  _  _
                    for (T items : table[i])

void add (ItemType item)
    if (find(item)) return;
    if (size == length) rehash (...);
        table[hash(item)].hash_insert(item);
    size++;
 
void hash_insert (ItemType item)
    insert(size, item); //LinkedList insert function
 
void add (T value)
    if (!find(value))
        num_items++;
        if (num_items == CAPACITY) grow(); //grow the table 
        unsigned int index = hash(code(value))
        table [index].insert(table[index].size(), value) //Will insert at the tail?
 
 
void hash_remove (ItemType item)
    remove(find(item));
 
void Remove (T value)   //Table size should always have a odd number
    if (find (value))
        index = hashcode(value)
        table[index].remove(value)
        --num_items;
        num_items = CAPACITY - ...?
 
void Clear()
    size = 0;
    length = 0;
    delete[ ] table //the [] is important because that will tell it to delete a table
 
int Hash(string item)
    unsigned int num = 0;
    for (auto i; item)
        num = num * 31 + i;
    return num % length
 
int Hash( string ?)
    strings need to be converted into a map? of char
    index = 0
        for every char
            index *= 31; //31 is important
            index += char
            ex
                bob
            ((((98 * 31) + 111) * 31) + 98) * 31
        return index % CAPACITY
 
 Grow()                         //Use when # of Items reaches CAPACTIY
    rehash ((CAPACITY * 2) +1)
 
 Shrink()                       //use when you remove and when the number of items is less than half CAPACITY
    rehash (CAPACITY / 2)
 
 void rehash (int new_size)
    LinkedList<ItemType>* temp = new LinkedList<ItemType>[new_size];
    int old_size = length;
    table+size = new_size;
        for (int i = 0; i < length; i++) {
            while (table[i].size() != 0) {
                ItemType item = table[i].remove(0);
                temp[hash(item)].hash_insert(item);
            }
        }
        delete[] table;
        table = temp;
 
 Rehash(unsigned int newCAP)
    LinkedList<T>* temp = new LinkedList<T>[newCAP]         //Make a table big enough
    unsigned int oldCAP = CAPACITY
            CAPACITY = newCAP
        for(i=0; i < oldCAP; i++)
            for(T item : table[i])
                index = hashCode[item]
                temp[index].insert at tail
        delete[] table
        table = temp
 
 Do Rehashing Last
    Don't actually compute the load factor instead just compare the size to find out if it has  a load factor of 1.0
 
    when making a new table, you can put the values from the old one into the new one by:
        a double for loop to grab each item in each bucket
 
    Make sure you also delete old arrays, and don't forget the []
 
    Rehash after I remove an item and before? I add an Item
 
 
class LinkedList
 
#include "LinkedList.h" ?? Or perhaps in the same file instead
class HashSet
    LinkedList<ItemType>* table
    int size;
    int length;
    hashSet() { 
        size = 0
        length = 0;
        table = new LinkedList<ItemType>[0]
    }
 
 Rehash and Print should be the only ones with a for() loop
 */

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"

#pragma once

using namespace std;


template <typename ItemType>

class HashTable {
    
private:
    LinkedList<ItemType>* table;
    int size;
    int length;
    unsigned int item_key;
    //int hash( string item_key );
    
public:
    
    HashTable() :
        table(new LinkedList<ItemType> [0]),
        size(0),
        length(0),
        item_key(0)
        //hash(0) //?????????
    {  }

    
//********************************************************************************************
//                                  *** HASH ***
//********************************************************************************************

    
    unsigned int hashCode( ItemType& item ) {
        
        unsigned int hashIndex = 0;
        for (int i = 0; i < item.size(); i++) {
            hashIndex *= 31;
            hashIndex += item.at(i);
        }
        return hashIndex % length;
    }
    

//********************************************************************************************
//                                  *** REHASH ***
//********************************************************************************************
    
    
    void rehash( int new_length )
    {
        
        LinkedList<ItemType>* temp = new LinkedList<ItemType>[new_length];
        int old_length = length;
        length = new_length;
        
        for (int i = 0; i < old_length; i++) {
            
            while (table[i].size() != 0) {
                ItemType item = table[i].remove(0);
                temp[hashCode(item)].insert(item);
            }
        }
        
        delete[] table;
        table = temp;
    }

    

    
//********************************************************************************************
//                                  *** CLEAR ***
//********************************************************************************************

    void clear()
    {
        if (size == 0 || length == 0)
            return;
        size = 0;
        length = 0;
        //call clear on all the buckets first??
        
        delete[] table;
        table = NULL;
    }
    

//********************************************************************************************
//                                  *** ADD ***
//********************************************************************************************

    void add( ItemType new_item ) //insertItem
    {
        if (find(new_item) == true) {
            //cout << "FIND TRUE" << endl;
            return;
        }
        if (size == length) {
            rehash(length * 2 + 1);
        }
        int index = hashCode( new_item ); //Use new_item->item_key ????
        table[index].insert(new_item);
        size++;
        
        

    }

//********************************************************************************************
//                                  *** REMOVE ***
//********************************************************************************************
    
    void remove( ItemType item ) //removeItem
    {
        if (find(item) == false) {
            //cout << "FIND FALSE" << endl;
            return;
        }
        int index = hashCode( item );
        table[index].remove(table[index].find(item));
        size--;
        if (length / 2 >= size )
            rehash(length / 2);
        

    }
    

//********************************************************************************************
//                                  *** FIND ***
//********************************************************************************************
    
    bool find( ItemType item ) //getItemByKey
    {
        if (length <= 0)
            return false;
        int index = hashCode( item );
        return table[index].find( item ) != -1;
    }
    
//********************************************************************************************
//                                  *** PRINT ***
//********************************************************************************************

    void print(ofstream& output) //printTable
    {
        if (size == 0)
            return;
        string word;
        for ( int i = 0; i < length; i++ )
        {
            //cout << endl;
            output << endl;
            //cout << "hash " << i << ":";
            output << "hash " << i << ":";
            table[i].print(i, word, output);
            
        }
    }
    

    
//********************************************************************************************
//                                 *** GET SIZE ***
//********************************************************************************************
    
    int getSize() //getLength()
    {
        return size;
    }
    

//********************************************************************************************
//                              *** DECONSTRUCTOR ***
//********************************************************************************************
    
    ~HashTable()
    {
        //clear();
        size = 0;
        length = 0;
        delete[] table;
        table = NULL;
    }
    
};


#endif /* HashTable_h */























