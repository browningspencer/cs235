//
//  Student.h
//  lab7
//
//  Created by Spencer Browning on 9/14/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include "StudentInterface.h"
#include <iostream>
#include <map>
#include <set>
#include <fstream>
//#include <istream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iomanip>
#pragma once
using namespace std;

class Student : public StudentInterface {
protected:
    //unsigned long long int ID;
    int ID;
    string name;
    string address;
    string phone;
    double GPA;
    int number_of_courses;



public:
    Student(unsigned long long int i, string n, string a, string p) : StudentInterface() {
        ID = i;
        name = n;
        address = a;
        phone = p;
        GPA = 0.00;
        number_of_courses = 0.00;

    }
    ~Student(void) {}

    virtual unsigned long long int getID();

    virtual string getName();

    virtual string getGPA();

    virtual void addGPA(double classGrade);

    virtual string toString();
};


#endif /* Student_h */
