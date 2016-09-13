//
//  Fighter.h
//  lab1
//
//  Created by Spencer Browning on 8/31/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Fighter_h
#define Fighter_h


#include "FighterInterface.h"
#include <iostream>
#pragma once
using namespace std;


class Fighter : public FighterInterface {
    
protected:
    string name;
    string type;
    int max_hp;
    int strength;
    int speed;
    int magic;
    
    int current_hp;
    
public:
    Fighter(string n, string t, int mh, int st, int sp, int m) {
        name = n;
        type = t;
        max_hp = mh;
        strength = st;
        speed = sp;
        magic = m;
        
        current_hp = max_hp;
    }
    ~Fighter() {}
    
    virtual string getName();
    
    virtual int getMaximumHP();

    virtual int getCurrentHP();

    virtual int getStrength();

    virtual int getSpeed();

    virtual int getMagic();

    virtual int getDamage() = 0;

    virtual void takeDamage(int damage);

    virtual void reset();

    virtual void regenerate();

    virtual bool useAbility() = 0;
    
};


#endif /* Fighter_h */
