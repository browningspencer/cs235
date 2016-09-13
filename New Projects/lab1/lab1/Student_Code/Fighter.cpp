//
//  Fighter.cpp
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <stdio.h>
#include "Fighter.h"
#include "Arena.h"

using namespace std;

/*
 *	This class specifies the methods for a fighter.
 *
 *	All fighters have the following attributes:
 *		Name - The fighter's name
 *		Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing. A Fighter's
 *			starting Hit Points (which is a Fighter's maximum Hit Points) must be greater than 0. There is no upper bound to what
 *			a Fighter's starting/maximum Hit Points could be.
 *		Strength - Physical power, used to determine hit point regeneration. Must be greater than 0. No maximum value.
 *		Speed - Dexterity and physical movement, used to reduce damage when being attacked. Must be greater than 0. No maximum value.
 *		Magic - Magical prowess, used for some special abilities. Must be greater than 0. No maximum value.
 *
 *	The three fighter types have unique abilities:
 *		Robot - Relies on strength to deal damage.  Also can use stored energy to temporarily increase damage (max/starting energy equal to 2*magic).
 *			Only Robots have energy.
 *		Archer - Relies on speed to deal damage.  Also can increase its speed for the remainder of the battle (no max bonus speed).
 *		Cleric - Relies on magic to deal damage.  Also can heal itself using mana, restoring hit points (max/starting mana equal to 5*magic).
 *			Only Clerics have mana.
 *
 *	More details about how stats are used and how abilities work can be found in the comments below.
 */

/*
 *	ROBOT_ABILITY_COST
 *	The amount of energy a Robot needs to perform its special ability.
 */
//const int ROBOT_ABILITY_COST = 5;

/*
 *	CLERIC_ABILITY_COST
 *	The amount of mana a Cleric needs to perform its special ability.
 */
//const int CLERIC_ABILITY_COST = 25;

    
/*
 *	getName()
 *
 *	Returns the name of this fighter.
 */
string Fighter::getName()
{
    return name;
}

/*
 *	getMaximumHP()
 *
 *	Returns the maximum hit points of this fighter.
 */
int Fighter::getMaximumHP()
{
    return max_hp;
}

/*
 *	getCurrentHP()
 *
 *	Returns the current hit points of this fighter.
 */
int Fighter::getCurrentHP()
{
    return current_hp;
}

/*
 *	getStrength()
 *
 *	Returns the strength stat of this fighter.
 */
int Fighter::getStrength()
{
    return strength;
}

/*
 *	getSpeed()
 *
 *	Returns the speed stat of this fighter.
 */
int Fighter::getSpeed()
{
    return speed;
}

/*
 *	getMagic()
 *
 *	Returns the magic stat of this fighter.
 */
int Fighter::getMagic()
{
    return magic;
}



/*
 *	takeDamage(int)
 *
 *	Reduces the fighter's current hit points by an amount equal to the given
 *	damage minus one fourth of the fighter's speed.  This method must reduce
 *	the fighter's current hit points by at least one.  It is acceptable for
 *	this method to give the fighter negative current hit points.
 *
 *	Examples:
 *		damage=10, speed=7		=> damage_taken=9
 *		damage=10, speed=9		=> damage_taken=8
 *		damage=10, speed=50		=> damage_taken=1
 */

void Fighter::takeDamage(int damage)
{
    int speed_temp = Fighter::getSpeed() / 4;
    int damage_taken = 0;
    
    if (speed_temp >= damage) {
        damage_taken = 1;
    }
    else {
        damage_taken = damage - speed_temp;
    }
    
    current_hp -= damage_taken;
}

/*
 *	reset()
 *
 *	Restores a fighter's current hit points to its maximum hit points.
 *
 *	Robot:
 *	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
 *	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
 *
 *	Archer:
 *	Also resets an Archer's current speed to its original value.
 *
 *	Cleric:
 *	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
 */
void Fighter::reset()
{
    current_hp = max_hp;
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

void Fighter::regenerate()
{
    int regen = Fighter::getStrength() / 6;
    if (regen < 1) {
        regen = 1;
    }
    
    if (current_hp + regen > max_hp) {
        current_hp = max_hp;
    }
    else {
        current_hp += regen;
    }
}


