//
//  main.cpp
//  lab_7
//
//  Created by Spencer Browning on 7/28/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "HashSet.h"

using namespace std;


void load_commands(string input_file, string result)
{
    ifstream in;
    ofstream output;
    
    string command;
    string value;
    //int num = 0;
    
    HashTable<string> table;
    
    
    
    in.open(input_file);
    output.open(result);
    
    while (in >> command)
    {
        if (command == "clear") {
            table.clear();
            output << "clear" << endl;
            //cout << "clear" << endl;
        } else if (command == "add") {
            in >> value;
            table.add(value);
            output << "add " << value << endl;
            //cout << "add " << value << endl;
        } else if (command == "remove") {
            in >> value;
            table.remove(value);
            output << "remove " << value << endl;
            //cout << "remove " << value << endl;
        } else if (command == "find") {
            in >> value;
            if (table.find(value)) {
                output << "find " << value << " true" << endl;
                //cout << "find " << value << " true" << endl;
            }
            else {
                output << "find " << value << " false" << endl;
                //cout << "find " << value << " false" << endl;
            }
        } else if (command == "print") {
            output << "print";
            //cout << "print";
            table.print(output);
            output << endl;
            //cout << endl;
        } else { }
    }
    output.close();
    in.close();
    
    return;
}

/*
 in >> value;
 
 found = false;
 tree.find(value, found);
 if (found)
 x = "true";
 else
 x = "false";
 output << "find " << value << " " << x << endl;
 //cout << "find " << value << " " << x << endl;

 */

int main(int argc, const char * argv[]) {
    string input_file = argv[1];
    string result = argv[2];
    
    load_commands(input_file, result);
    
    return 0;
}
