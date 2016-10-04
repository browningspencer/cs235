//
//  School.cpp
//  lab7
//
//  Created by Spencer Browning on 9/14/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

//change GPA.h and GPA.cpp to School or Class? That would be more descriptive...

/*
 my_map(id) will return a 1 if it is found, 0 if it is not
 
 

 
 for(set<"type">::iterator i = s.begin(); i != myset.end(); i++) {
    *i
    i->
 }
 OR
 for(Student * st : myset) {
 
 }
 OR
 for(auto st : myset) {
 
 }
 
 */

#include <stdio.h>
#include "School.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

const double A = 4.0;
const double Am = 3.7;
const double Bp = 3.4;
const double B = 3.0;
const double Bm = 2.7;
const double Cp = 2.4;
const double C = 2.0;
const double Cm = 1.7;
const double Dp = 1.4;
const double D = 1.0;
const double Dm = 0.7;
const double E = 0.0;


/*
 * getMap()
 *
 * Returns the map storing the student information.
 * The key of the map should be the student ID.
 */
map<unsigned long long int,StudentInterface*> School::getMap() {
    return student_map;
}

/*
 * getSet()
 *
 * Returns the set storing the student information.
 */
set<StudentInterface*,Comparator> School::getSet() {
    return student_set;
}


/*
 * importStudents()
 *
 * Read in and parse through the given files. Each part of an entry in a
 * file is given on a separate line in the file. Student ID is first, name is
 * second, address is third, and phone is last. There are no blank lines between
 * students. The following is an example file:
 *
 *	 5291738600
 * 	 Dick B. Smith
 * 	 879 Maple Road, Centralia, Colorado 24222
 * 	 312-000-1000
 * 	 9251738707
 *	 Harry C. Anderson
 *	 635 Main Drive, Midville, California 48444
 * 	 660-050-2200
 *
 * If a valid file is given, the new Students should be added to the existing
 * map and set.
 *
 * If an invalid file name is given or if there is a missing entry for a student,
 * return false. Duplicate student ID numbers and duplicate students will not be
 * tested for. There will never be a student that exists in the map and set. If
 * the function returns false, then no changes should have been made to the
 * existing map or set.
 *
 * The key of the map should be the student ID.
 *
 * Returns false if an invalid filename is given or if there is a missing entry for a
 * student, otherwise true.
 */
bool School::importStudents(string mapFileName, string setFileName) {
    ifstream in;
    
    unsigned long long int id;
    string name;
    string address;
    string phone;
    double gpa = 0;
    
    map<unsigned long long int,StudentInterface*> my_map;
    set<StudentInterface*,Comparator> my_set;
    
    if (in.open(mapFileName)) {
        if (in >> id) {
            while (in >> id && getline(in, name) && getline(in, address) && getline(in, phone)) {
                //map[id] = new Student( );
                //set.insert(new Student( ));
                my_map[id] = new Student(id, name, address, phone, gpa);
            }
            in.close();
            return true;
        }
        else {
            in.close();
            return false;
        }
    }
    
    if(in.open(setFileName)) {
        if (in >> id) {
            while(in >> id && getline(in, name) && getline(in, address) && getline(in, phone)) {
                my_set.insert(new Student(id, name, address, phone, gpa));
            }
            in.close();
            return true;
        }
        else {
            in.close();
            return false;
        }
    }
    
    return false;
}




/*
 * importGrades()
 *
 * Read in and parse through the given file. Each part of an entry in the file
 * is given on a separate line in the file. Student ID is first, course is
 * second, and grade is last. There are no blank lines between entries. The
 * following is an example file:
 *
 * 	5291738860
 * 	CHEM134
 * 	A
 * 	9251734870
 * 	BOT180
 * 	B
 * 	9251733870
 * 	PE273
 * 	D+
 * 	5291738760
 * 	HIS431
 *  	A-
 *
 * Compute the GPA by finding the average of all the grades with a matching student ID
 * in the Grade file. The GPA is calculated by taking a Student's total sum GPA and
 * dividing by the number of classes taken. If the given student ID has no matching
 * grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
 * names so long as the total number of courses taken is counted.
 *
 * You may assume that the given student ID exists in the map or set.
 *
 * Use the following point values for each grade.
 *
 *		  A = 4.0  A- = 3.7
 *	B+ = 3.4  B = 3.0  B- = 2.7
 *	C+ = 2.4  C = 2.0  C- = 1.7
 *	D+ = 1.4  D = 1.0  D- = 0.7
 *		  E = 0.0
 *
 * Returns false if an invalid filename is given, otherwise true.
 */
bool School::importGrades(string fileName) {
    ifstream in;
    vector<School> grades;
    
    string ID;
    string course;
    int number_of_courses = 0;
    string letter_grade;
    
    if (in.open(fileName)) {
    
        while (getline(in, ID)) {
            getline(in, course);
            getline(in, letter_grade);
            
            //calculate grades??
        }
        return true;
    }
    else {
        return false;
    }
}


/* Grade.cpp
 #include "Grade.h"
 #include <sstream>
 #include <vector>
 #include <fstream>
 using namespace std;
 
 Grade::Grade(string course, string id, string letter_grade)
 {
 this->course = course;
 this->id = id;
 this->letter_grade = letter_grade;
 }
 
 Grade::~Grade()
 {
 }
 
 string Grade::toString() const
 {
 stringstream ss;
 ss << Grade::toString();
 
 ss << id << "\t" << letter_grade << "\t" << course << endl;
 
 return ss.str();
 }
 
 
 
 
 bool Grade::operator < (const Grade& g) const {
 return id < g.id ||
 (id == g.id && course < g.course) ||
 (id == g.id && course == g.course && letter_grade < g.letter_grade);
 }
 */

/*
 * querySet()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your set to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. If an invalid file name is given,
 * then return an empty string. The precision of the GPA will be set to two decimal places.
 * There will be a trailing new line.
 */
string School::querySet(string fileName) {
    
}

/*
 * queryMap()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your map to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. if an ivalid file name is given,
 * then return an empty string. The precision of the GPA will be set to two decimal places.
 * There will be a trailing new line.
 */
string School::queryMap(string fileName) {
    
}

/*
 * Clears the students from the map and set.
 */
void School::clear() {
    //Iterate over both map and set and call delete on all pointers in each
    //map.clear()
    //set.clear()
}


