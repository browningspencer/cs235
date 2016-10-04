//
//  Arena.cpp
//  lab1
//
//  Created by Spencer Browning on 9/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <stdio.h>
#include "Arena.h"
#include <sstream>

using namespace std;
/*
 *	addFighter(string)
 *
 *	Adds a new fighter to the collection of fighters in the arena. Do not allow
 *	duplicate names.  Reject any string that does not adhere to the format
 *	outlined in the lab specs.
 *
 *	Return true if a new fighter was added; false otherwise.
 */
bool Arena::addFighter(string info)
{
    //ss = "cow A 100 10 20 5"

    string name;
    string type;
    int max_hp = 0;
    int strength = 0;
    int speed = 0;
    int magic = 0;
    int temp = 0;

    stringstream ss(info);
    if (ss >> name) {
      //cout << "???" << endl;
      //cout << "Name: " << name << endl;
        //while (ss >> type) {
        ss >> type;
            //cout << "Type: " << type << endl;
            ss >> max_hp >> strength >> speed >> magic;
            //cout << "HP: " << max_hp << " ";
            //cout << "Strength: " << strength << " ";
            //cout << "Speed: " << speed << " ";
            //cout << "Magic: " << magic << endl;
            if (ss >> temp) {
              //cout << "false" << endl;
              return false;
            }
            Fighter* new_fighter; // = new Fighter(name, type, max_hp, current_hp, strength, speed, magic);
            if (type == "A") {
                new_fighter = new Archer(name, type, max_hp, strength, speed, magic);
            }
            else if (type == "C") {
                new_fighter = new Cleric(name, type, max_hp, strength, speed, magic);
            }
            else if (type == "R") {
                new_fighter = new Robot(name, type, max_hp, strength, speed, magic);
            }
            else {
              //cout << "false" << endl;
              return false;
            }

            for (int i = 0; i < fighters.size(); i++) {
              if (name == fighters[i]->getName()) {
                //cout << "false" << endl;
                return false;
              }
            }

            if (max_hp <= 0) {
              //cout << "false" << endl;
                return false;
              }
            if (strength <= 0) {
              //cout << "false" << endl;
                return false;
              }
            if (speed <= 0) {
              //cout << "false" << endl;
                return false;
              }
            if (magic <= 0) {
              //cout << "false" << endl;
                return false;
              }
              //cout << "Before Add Size: " << fighters.size() << endl;
            fighters.push_back(new_fighter);
            //cout << "After Add Size: " << fighters.size() << endl;
        //}
        //cout << "true" << endl;
        return true;
    }
    else {
        //cout << "false!" << endl;
        return false;
    }
    //cout << "ERROR" << endl;
}

/*
 *	removeFighter(string)
 *
 *	Removes the fighter whose name is equal to the given name.  Does nothing if
 *	no fighter is found with the given name.
 *
 *	Return true if a fighter is removed; false otherwise.
 */
bool Arena::removeFighter(string name)
{
    for (int i = 0; i < fighters.size(); i++) {
        if (name == fighters[i]->getName()) {
            fighters.erase(fighters.begin() + i);
            return true;
        }
    }
    return false;
}

/*
 *	getFighter(string)
 *
 *	Returns the memory address of a fighter whose name is equal to the given
 *	name.  Returns NULL if no fighter is found with the given name.
 *
 *	Return a memory address if a fighter is found; NULL otherwise.
 */
FighterInterface* Arena::getFighter(string name)
{
    for (int i = 0; i < fighters.size(); i++) {
        if (name == fighters[i]->getName()) {
            return fighters[i];
        }
    }
    return NULL;
}

/*
 *	getSize()
 *
 *	Returns the number of fighters in the arena.
 *
 *	Return a non-negative integer.
 */
int Arena::getSize()
{

    return fighters.size();
}
