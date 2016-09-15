//
//  Student.cpp
//  lab7
//
//  Created by Spencer Browning on 9/14/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <stdio.h>
#include "Student.h"

/*
 * getID()
 *
 * Returns the ID of the Student.
 */
unsigned long long int getID() {
    return ID;
    
}

/*
 * getName()
 *
 * Returns the name of the Student
 */

string getName() {
    return name;
}

/*
 * getGPA()
 *
 * Returns the string representation of the Student's GPA.
 */

string getGPA() {
    return GPA;
}

/*
 * addGPA()
 *
 * Incorporates the given course grade into the Student's overall GPA.
 */

void addGPA(double classGrade);

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
string toString();