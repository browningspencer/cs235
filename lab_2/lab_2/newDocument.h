//
//  newDocument.h
//  lab_2
//
//  Created by Spencer Browning on 7/13/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef newDocument_h
#define newDocument_h

#pragma once

#include "Document.h"

class newDocument {
private:
    std::string word;
    std::list<int> line;
    
public:
    newDocument(std::string w, std::list<int> l);
    ~newDocument();
    
    std::string getWord() { return word; }
    std::list<int> getLine() { return line; }
    
};

#endif /* newDocument_h */
