//
//  Cleric.h
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Cleric_h
#define Cleric_h

#include <stdio.h>
#include "Fighter.h"
#pragma once

class Cleric : public Fighter {
private:
    int mana;
    int max_mana;
    
public:
    Cleric(string n, string t, int mh, int st, int sp, int m) : Fighter (n, t, mh, st, sp, m) {
        max_mana = magic * 5;
        mana = max_mana;
    }
    ~Cleric() {}
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();
    
};


#endif /* Cleric_h */
