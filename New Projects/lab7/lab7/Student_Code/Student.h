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
#pragma once
using namespace std;

class Student : public StudentInterface {
private:
    unsigned long long int ID;
    string name;
    string address;
    string phone;
    double GPA;
    
    /*
     * toString()
     *
     * The student object will be put into string representation. Student info will be
     * ordered ID, name, address, phone number, and GPA. Each piece of information will
     * be on its own line. GPA will not have a newline following it and the precision
     * of the GPA will be set to two decimal places. For example,
     *
     * 123456789
     * Ben Thompson
     * 17 Russell St, Provo, UT 84606
     * 555-555-5555
     * 3.12
     *
     * Returns a string representation of the student object There is no trailing new line.
     */

public:
    Student(unsigned long long int i, string n, string a, string p, double g) {
        ID = i;
        name = n;
        address = a;
        phone = p;
        GPA = g;
    }
    ~Student() {}

    virtual unsigned long long int getID();

    virtual string getName();

    virtual string getGPA();
    
    virtual void addGPA(double classGrade);

    virtual string toString();
};


#endif /* Student_h */
