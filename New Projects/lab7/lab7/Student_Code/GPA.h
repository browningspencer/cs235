//
//  GPA.h
//  lab7
//
//  Created by Spencer Browning on 9/14/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef GPA_h
#define GPA_h

#include "GPAInterface.h"
#include <iostream>
#pragma once
using namespace std;

class GPA : public GPAInterface {
private:
    
public:
    GPA() {}
    ~GPA() {}
    

    virtual map<unsigned long long int,StudentInterface*> getMap();

    virtual set<StudentInterface*,Comparator> getSet();

    virtual bool importStudents(string mapFileName, string setFileName);

    virtual bool importGrades(string fileName);
    
    virtual string querySet(string fileName);

    virtual string queryMap(string fileName);

    virtual void clear();
    
};



#endif /* GPA_h */
