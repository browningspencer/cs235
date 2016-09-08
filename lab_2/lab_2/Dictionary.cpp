//
//  Dictionary.cpp
//  lab_2
//
//  Created by Spencer Browning on 7/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Dictionary.h"

#include <sstream>

using namespace std;


Dictionary::Dictionary(string word, list<int> line)
{
    this->word = word;
    this->line = line;
}

Dictionary::~Dictionary()
{
}


string Dictionary::toString() const
{
    stringstream ss;
    
    ss << Dictionary::toString();
    ss << word << endl;
    for (unsigned int i = 0; i < line.size(); i++)
    {
        ss << line.front() << endl;
    }
    
    return ss.str();
}

/*
bool Dictionary::operator<(const Dictionary& s) const {
    return  < s.id;
}
*/