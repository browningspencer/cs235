//
//  Dictionary.h
//  lab_2
//
//  Created by Spencer Browning on 7/8/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Dictionary_h
#define Dictionary_h


#pragma once

#include "Document.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>

class Dictionary {
private:
    std::string word;
    std::list<int> line;
    
    
public:
    Dictionary(std::string w, std::list<int> l);
    ~Dictionary();
    
    std::string getWord() { return word; }
    std::list<int> getLine() { return line; }
    
    void setWord() { std::string word; }
    void setLine() { std::list<int> list; }
    
    std::string toString() const;
    
    std::vector<Document> document;
    
    bool operator < (const Dictionary& s) const;
    
};

/*std::map<std::string, std::list<int>>*/


#endif /* Dictionary_h */

