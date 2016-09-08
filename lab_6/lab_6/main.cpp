//
//  main.cpp
//  lab_6
//
//  Created by Spencer Browning on 8/1/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "AVL.h"

using namespace std;


const string CLEAR = "clear";
const string ADD = "add";
const string REMOVE = "remove";
const string FIND = "find";
const string PRINT = "print";


void load_commands(string command_file, string result) //Read in commands one at a time based off of the first thing. You can also read in the file and output the file in the same function
{
    
    
    ifstream in;
    ofstream output;
    
    string command;
    string value;
    string temp;
    
    bool found = false;
    string x;
    
    AVL<string> tree;
    tree.clear();
    
    //int count = 0;
    
    in.open(command_file);
    output.open(result);
    
    while (in >> command) {
        //cout << count << endl;
        if (command == "clear") { // Don't need Command Class, just read in if needed
            tree.clear();
            output << "clear" << endl;
            //cout << "clear" << endl;
        }
        else if (command == "add") {
            in >> value;
            
            tree.add(value);
            output << "add " << value << endl;
            //cout << "add " << value << endl;
        }
        else if (command == "find") {
            in >> value;
            
            found = false;
            tree.find(value, found);
            if (found)
                x = "true";
            else
                x = "false";
            output << "find " << value << " " << x << endl;
            //cout << "find " << value << " " << x << endl;
        }
        else if (command == "remove") {
            in >> value;
            
            tree.remove(value);
            output << "remove " << value << endl;
            //cout << "remove " << value << endl;
        }
        else if (command == "print") {
            output << "print" << endl;
            //cout << "print" << endl;
            
            tree.print(output);
        }
        else {
            //cout << "bad input" << endl;
        }
    }
    output.close();
    in.close();
    
    tree.clear();
    
    return;
}


int main(int argc, const char * argv[]) {
    string command_file = argv[1];
    string result = argv[2];
    
    load_commands(command_file, result);
    
    
    return 0;
}


