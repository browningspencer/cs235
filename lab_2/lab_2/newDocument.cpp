//
//  newDocument.cpp
//  lab_2
//
//  Created by Spencer Browning on 7/13/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <stdio.h>
#include "newDocument.h"

using namespace std;

newDocument::newDocument(string word, list<int> line)
{
    this->word = word;
    this->line = line;
}

newDocument::~newDocument()
{}
