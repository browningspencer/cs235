//
//  main.cpp
//  lab_5
//
//  Created by Spencer Browning on 7/18/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//
/*
            head        tail
           /             \
         __      __      __
        |  | -> |  | -> |  | -> NULL
 NULL<- |__| <- |__| <- |__|
 
 examples:
    head->prev = new Node(data, head, NULL)
 
 
 
 
 
 */




#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Command.h"
#include "LinkedList.h"

using namespace std;

const string CLEAR = "clear";
const string INSERT = "insert";
const string REMOVE = "remove";
const string FIND = "find";
const string PRINT = "print";


void load_commands(string command_file, string result) //Read in commands one at a time based off of the first thing. You can also read in the file and output the file in the same function
{
    
    
    ifstream in;
    ofstream output;
    
    string command;
    int index = 0;
    string word;
    string temp;
    
    //vector<Command> commands;
    LinkedList<string> list;
    list.clear();
    
    //int count = 0;
    
    in.open(command_file);
    output.open(result);
    
    while (in >> command) {
        //cout << count << endl;
        if (command == "clear") { // Don't need Command Class, just read in if needed
            list.clear();
            //list.create_list(0);
            output << "clear" << endl;
            //cout << "clear" << endl;
        }
        else if (command == "insert") {
            in >> index;
            in >> word;
            
            list.insert(index, word);
            output << "insert " << index << " " << word << endl;
            //cout << "insert " << index << " " << word << endl;
        }
        else if (command == "find") {
            in >> word;
            
            int index = list.find(word);
            output << "find " << word << " " << index << endl;
            //cout << "find " << word << " " << index << endl;
        }
        else if (command == "remove") {
            in >> index;
            
            word = list.remove(index);
            output << "remove " << index << " " << word << endl;
            //cout << "remove " << index << " " << word << endl;
        }
        else if (command == "print") {
            output << "print" << endl;
            //cout << "print" << endl;
            
            list.print(index, word, output);
        }
        else {
            //cout << "bad input" << endl;
        }
        
        //Command new_line = Command(command, index, word);
        
        //commands.push_back(new_line);
        //count++;
        
    }
    output.close();
    in.close();
    
    list.clear();
    
    return;
}






int main(int argc, const char * argv[]) {
    string command_file = argv[1];
    string result = argv[2];
    //string command_file = "in50.txt";
    //int ZERO = 0;
    //int ONE = 1;
    
    //vector<Command> commands;
    //load_commands(command_file, commands);
    
    load_commands(command_file, result);
    
    
    return 0;
}



