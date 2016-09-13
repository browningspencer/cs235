//
//  Arena.h
//  lab1
//
//  Created by Spencer Browning on 8/31/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

/*
 Run Command:
     chmod 755 RunTestDriver.sh
 the first time you unzip the files to change the 
 permissions to allow you to use it
 
 Running the Program
    ./RunTestDriver.sh
 
 Start by building a skeleton of all the functions you need. 

 Write some code then test often
 
 
 */

#ifndef Arena_h
#define Arena_h

#include "ArenaInterface.h"
//#include "FighterInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;


class Arena : public ArenaInterface {
    
private:
    vector<Fighter*> fighters;
    
    
public:
    Arena() {}
    ~Arena(){}
    
    virtual bool addFighter(string info);
    
    virtual bool removeFighter(string name);
  
    virtual FighterInterface* getFighter(string name);
    
    virtual int getSize();

    
};



#endif /* Arena_h */
