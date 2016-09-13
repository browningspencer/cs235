//
//  Robot.cpp
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Robot.h"
#include <cmath>


/*
 *	getDamage()
 *
 *	Returns the amount of damage a fighter will deal.
 *
 *	Robot:
 *	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
 *
 */
int Robot::getDamage()
{
    int damage = Fighter::getStrength() + bonus_damage;
    return damage;
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
 */
void Robot::reset()
{
    Fighter::reset();
    energy = max_energy;
    bonus_damage = 0;
}

/*
 *	useAbility()
 *
 *	Attempts to perform a special ability based on the type of fighter.  The
 *	fighter will attempt to use this special ability just prior to attacking
 *	every turn.
 *
 *	Robot: Shockwave Punch
 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
 *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
 *		Examples:
 *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
 *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
 *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
 *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
 *	Robot Note:
 *	The bonus damage formula should be computed using double arithmetic, and only
 *	the final result should be cast into an integer.
 *
 *	Return true if the ability was used; false otherwise.
 */
bool Robot::useAbility()
{
    double shockwave_punch = strength * pow((energy / max_energy), 4);
    
    if (energy >= ROBOT_ABILITY_COST) {
        bonus_damage = shockwave_punch;
        energy -= ROBOT_ABILITY_COST;
        return true;
    }
    else {
        return false;
    }
}

