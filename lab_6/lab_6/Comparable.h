//
//  Comparable.h
//  lab_6
//
//  Created by Spencer Browning on 8/1/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Comparable_h
#define Comparable_h

#pragma once
#include <iostream>

//Class "Comparable" corresponds to an arbitrary comparable element
//with a keyfield that has an ordering relation. The template parameter
//KeyType is the "type of the keyfield

/*
template <class KeyType>

class Comparable {
    
private:
    KeyType myKey;
    
    
public:
    Comparable(KeyType key) : myKey(key) {};
    
    // Use default copy-ctor, assignment, & destructor
    
    //Compare this item against the given key & return the result
    //cmp_t Compare(KeyType key) const;
    
    //Get the key-field of an item
    KeyType Key() const { return myKey; }
};


#endif /* Comparable_h */
