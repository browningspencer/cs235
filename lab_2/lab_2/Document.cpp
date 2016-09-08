//
//  Document.cpp
//  lab_2
//
//  Created by Spencer Browning on 7/9/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Document.h"
#include <sstream>

using namespace std;

Document::Document(string words, int lines)
{
    this->words = words;
    this->lines = lines;
}

Document::~Document()
{}

string Document::toString() const
{
    stringstream ss;
    
    ss << Document::toString();
    ss << words << endl;
    ss << lines << endl;
    
    return ss.str();
}



/*
string lower_case(string words)
{
    stringstream ss;
    char c;
    int counter = 0;
    
    while (ss << c)
    {
        counter ++;
        if (isalpha(c))
        {
            tolower(words[counter]);
        }
    }
    
    return words;
}
*/