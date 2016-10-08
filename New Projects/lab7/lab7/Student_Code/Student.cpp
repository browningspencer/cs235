//
//  Student.cpp
//  lab7
//
//  Created by Spencer Browning on 9/14/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <string>
#include "Student.h"

/*
 * getID()
 *
 * Returns the ID of the Student.
 */
unsigned long long int Student::getID() {
    //cout << ID << endl;
    return ID;

}

/*
 * getName()
 *
 * Returns the name of the Student
 */

string Student::getName() {
    return this->name;
}

/*
 * getGPA()
 *
 * Returns the string representation of the Student's GPA.
 */

string Student::getGPA() {
    stringstream ss;
    double newGPA = GPA / number_of_courses;
    //cout << "GPA: \t" << setprecision(2) << fixed << newGPA << "# of courses:\t" << number_of_courses << endl;
    if (number_of_courses == 0) {
        ss << setprecision(2) << fixed << GPA;
        return ss.str();
    }
    else {
        //if (newGPA < 1.58 && newGPA > 1.56) {
        //    newGPA -= 0.01;
        //}
        ss << setprecision(2) << fixed << newGPA;
        return ss.str();
    }
}

/*
 * addGPA()
 *
 * Incorporates the given course grade into the Student's overall GPA.
 */

void Student::addGPA(double classGrade) {
    number_of_courses++;
    double newGPA = classGrade + GPA;
    GPA = newGPA;
}

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
string Student::toString() {
    //stringstream out;
    //out << fixed << setprecision(2) << calculated gpa;
    stringstream out;

    out << ID << endl;
    out << name << endl;
    out << address << endl;
    out << phone << endl;
    out << getGPA();

    return out.str();
}

/*
string Document::toString() const
{
    stringstream ss;

    ss << Document::toString();
    ss << words << endl;
    ss << lines << endl;

    return ss.str();
}
*/
