//
//  Robot.h
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Robot_h
#define Robot_h

#include <stdio.h>
#include "Fighter.h"
#pragma once

class Robot : public Fighter {
private:
    double energy;
    double max_energy;
    int bonus_damage;
    
public:
    Robot(string n, string t, int mh, int st, int sp, int m) : Fighter (n, t, mh, st, sp, m) {
        max_energy = magic * 2;
        energy = max_energy;
    }
    ~Robot() {}
    
    int getDamage();
    void reset();
    bool useAbility();
};


#endif /* Robot_h */
