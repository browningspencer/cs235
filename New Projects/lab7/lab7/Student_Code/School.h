//
//  School.h
//  lab7
//
//  Created by Spencer Browning on 9/14/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef School_h
#define School_h

#include "GPAInterface.h"
#include "Student.h"
#include <iostream>
#pragma once
using namespace std;

class School : public GPAInterface {
protected:
    map<unsigned long long int,StudentInterface*> student_map;
    set<StudentInterface*,Comparator> student_set;

public:
    School(void) : GPAInterface(){}
    ~School(void) {clear();}


    virtual map<unsigned long long int,StudentInterface*> getMap();

    virtual set<StudentInterface*,Comparator> getSet();

    virtual bool importStudents(string mapFileName, string setFileName);

    virtual bool importGrades(string fileName);

    virtual string querySet(string fileName);

    virtual string queryMap(string fileName);

    virtual void clear();

};



#endif /* School_h */
