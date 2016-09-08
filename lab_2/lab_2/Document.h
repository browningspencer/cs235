//
//  Document.h
//  lab_2
//
//  Created by Spencer Browning on 7/9/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Document_h
#define Document_h

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>

class Document {
private:
    std::string words;
    int lines;
    
public:
    Document(std::string w, int ln);
    ~Document();
    
    std::string getWords() { return words; }
    int getLines() { return lines; }
    
    void setWords() { std::string words; }
    //void setLines() { int lines; }
    
    std::string toString() const;
    
    std::string lower_case(std::string words);
};


#endif /* Document_h */

