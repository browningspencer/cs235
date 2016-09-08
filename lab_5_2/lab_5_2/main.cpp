//
//  main.cpp
//  lab_5_2
//
//  Created by Spencer Browning on 7/29/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

const string CLEAR = "clear";
const string INSERT = "insert";
const string REMOVE = "remove";
const string FIND = "find";
const string PRINT = "print";

void load_commands(string command_file, string result)
{
    string command;
    int index = 0;
    string value;
    string temp;
    
    LinkedList<string> list;
    
    list.clear();
    ifstream in;
    ofstream output;
    
    in.open(command_file);
    output.open(result);
    
    while (in >> command) {
        cout << "HERE" << endl;
        if (command == CLEAR) {
            list.clear();
            //output << CLEAR << endl;
            cout << CLEAR << endl;
        }
        else if (command == INSERT) {
            in >> index;
            in >> value;
            
            list.insert(index, value);
            //output << INSERT << index << " " << word << endl;
            cout << INSERT << index << " " << value << endl;
        }
        else if (command == FIND) {
            in >> value;
            
            index = list.find(value);
            //output << FIND << " " << word << " " << index << endl;
            cout << FIND << " " << value << " " << index << endl;
        }
        else if (command == REMOVE) {
            in >> index;
            
            value = list.remove(index);
            //output << REMOVE << " " << index << " " << value << endl;
            cout << REMOVE << " " << index << " " << value << endl;
        }
        else if (command == PRINT) {
            cout << PRINT << endl;
            
            list.print(index, value, output);
        }
        else {}
        
        output.close();
        in.close();
        
        list.clear();
        
        return;
    }
}


int main(int argc, const char * argv[]) {
    string command_file = argv[1];
    string result = argv[2];
    
    
    load_commands(command_file, result);
    
    
    return 0;
}
