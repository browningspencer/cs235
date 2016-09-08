//
//  Command.h
//  lab_5
//
//  Created by Spencer Browning on 7/23/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Command_h
#define Command_h


#include <iostream>
#include <string>

#pragma once

class Command {

private:
    std::string command;
    int index = 0;
    std::string word;
    
public:
    Command(std::string c, int i, std::string w) {};
    ~Command() {};
    
    std::string getCommand() { return command; }
    int getIndex() { return index; }
    std::string getWord() { return word; }
    
};


#endif /* Command_h */
