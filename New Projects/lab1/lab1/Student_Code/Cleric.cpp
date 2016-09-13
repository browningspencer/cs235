//
//  Cleric.cpp
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Cleric.h"


/*
 *	getDamage()
 *
 *	Returns the amount of damage a fighter will deal.
 *
 *	Cleric:
 *	This value is equal to the Cleric's magic.
 */
int Cleric::getDamage()
{
    int damage = Fighter::getMagic();
    return damage;
}

/*
 *	reset()
 *
 *	Restores a fighter's current hit points to its maximum hit points.
 *
 *	Cleric:
 *	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
 */
void Cleric::reset()
{
    Fighter::reset();
    mana = max_mana;
}

/*
 *	regenerate()
 *
 *	Increases the fighter's current hit points by an amount equal to one sixth of
 *	the fighter's strength.  This method must increase the fighter's current hit
 *	points by at least one.  Do not allow the current hit points to exceed the
 *	maximum hit points.
 *
 *	Cleric:
 *	Also increases a Cleric's current mana by an amount equal to one fifth of the
 *	Cleric's magic.  This method must increase the Cleric's current mana by at
 *	least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
 */

void Cleric::regenerate()
{
    Fighter::regenerate();
    
    int mana_regen = magic / 5;
    if (mana_regen < 1)
        mana_regen = 1;
    
    if (mana + mana_regen > max_mana) {
        mana = max_mana;
    }
    else {
        mana += mana_regen;
    }
    
}

/*
 *	useAbility()
 *
 *	Attempts to perform a special ability based on the type of fighter.  The
 *	fighter will attempt to use this special ability just prior to attacking
 *	every turn.
 *
 *	Cleric: Healing Light
 *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
 *	Will be used even if the Cleric's current HP is equal to their maximum HP.
 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
 *	Cleric Note:
 *	This ability, when successful, must increase the Cleric's current hit points
 *	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
 *	Do not allow the current hit points to exceed the maximum hit points.
 *
 *	Return true if the ability was used; false otherwise.
 */

bool Cleric::useAbility()
{
    int heal_light = magic / 3;
    if (heal_light < 1)
        heal_light = 1;
    
    if (mana >= CLERIC_ABILITY_COST) {
        if (current_hp + heal_light > max_hp) {
            current_hp = max_hp;
        }
        else {
            current_hp += heal_light;
        }
        mana -= CLERIC_ABILITY_COST;
        return true;
    }
    return false;
}



