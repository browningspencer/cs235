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
#pragma once
using namespace std;

class Student : public StudentInterface {
protected:
    unsigned long long int ID;
    string name;
    string address;
    string phone;
    double GPA;
    
    double GPAsum;
    int GPAcount;
    

public:
    Student(unsigned long long int i, string n, string a, string p, double g) {
        ID = i;
        name = n;
        address = a;
        phone = p;
        GPA = g;
        
        GPAsum += GPA;
        GPAcount += 1;
    }
    ~Student() {}

    virtual unsigned long long int getID();

    virtual string getName();

    virtual string getGPA();
    
    virtual void addGPA(double classGrade);

    virtual string toString();
};


#endif /* Student_h */
