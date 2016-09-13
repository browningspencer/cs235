//
//  Archer.h
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Archer_h
#define Archer_h

#include <stdio.h>
#include "Fighter.h"
#pragma once

class Archer : public Fighter {
private:
    int original_speed;
    
public:
    Archer(string n, string t, int mh, int st, int sp, int m) : Fighter (n, t, mh, st, sp, m) {
        original_speed = speed;
    }
    ~Archer() {}
    
    int getDamage();
    void reset();
    bool useAbility();
};



#endif /* Archer_h */
