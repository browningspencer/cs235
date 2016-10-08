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

const double A = 4.00;
const double Am = 3.70;
const double Bp = 3.40;
const double B = 3.00;
const double Bm = 2.70;
const double Cp = 2.40;
const double C = 2.00;
const double Cm = 1.70;
const double Dp = 1.40;
const double D = 1.00;
const double Dm = 0.70;
const double E = 0.00;

bool is_number(string s) {
    return (strspn(s.c_str(), "0123456789") == s.size());
}

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



bool validFile(string fileName) {
    ifstream in (fileName.c_str());

    if (in.fail()) {
        return false;
    }
    if (!in.good()) {
        return false;
    }

    string ID;
    string name;
    string address;
    string phone;

    if (in.is_open()) {
        while (in.good()) {
            getline(in, ID);
            if (!is_number(ID)) {
                return false;
            }
            if (ID == "") {
                break;
            }
            getline(in, name);
            getline(in, address);
            getline(in, phone);
        }
        return true;
    }
    else {
        return false;
    }
}

bool School::importMap(string fileName) {
    string ID;
    string name;
    string address;
    string phone;

    ifstream in(fileName.c_str());

    if (in.is_open()) {
        while (in.good()) {
            getline(in, ID);
            if (!is_number(ID)) {
                return false;
            }
            if (ID == "") {
                break;
            }

            getline(in, name);
            getline(in, address);
            getline(in, phone);

            unsigned long long int studentID = atoll(ID.c_str());

            StudentInterface* newStudent = new Student(studentID, name, address, phone);

            student_map.insert(student_map.end(), pair<unsigned long long int, StudentInterface*>(studentID, newStudent));
        }
        return true;
    }
    else {
        return false;
    }
}

bool School::importSet(string fileName) {
    string ID;
    string name;
    string address;
    string phone;

    ifstream in(fileName.c_str());

    if (in.is_open()) {
        while (in.good()) {
            getline(in, ID);
            if (!is_number(ID)) {
                return false;
            }
            if (ID == "") {
                break;
            }

            getline(in, name);
            getline(in, address);
            getline(in, phone);

            unsigned long long int studentID = atoll(ID.c_str());

            StudentInterface* newStudent = new Student(studentID, name, address, phone);

            student_set.insert(newStudent);
        }
        return true;
    }
    else {
        return false;
    }
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
    if (validFile(mapFileName) == false || validFile(setFileName) == false) {
        return false;
    }
    else {
        if (School::importMap(mapFileName) == false) {
            return false;
        }
        if (School::importSet(setFileName) == false) {
            return false;
        }
        return true;
    }
}




double calculateGPA(string letter_grade) {
    if (letter_grade == "A") { return A; }
    else if (letter_grade == "A-") { return Am; }
    else if (letter_grade == "B+") { return Bp; }
    else if (letter_grade == "B")  { return B; }
    else if (letter_grade == "B-") { return Bm; }
    else if (letter_grade == "C+") { return Cp; }
    else if (letter_grade == "C")  { return C; }
    else if (letter_grade == "C-") { return Cm; }
    else if (letter_grade == "D+") { return Dp; }
    else if (letter_grade == "D")  { return D; }
    else if (letter_grade == "D-") { return Dm; }
    else if (letter_grade == "E") { return E; }
    else { return E; }
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
bool School::importGrades( string fileName ) {
    ifstream in (fileName.c_str());
    //vector<School> grades;

    string ID;
    string course;
    string letter_grade;
    //int number_of_courses = 0;

    if (in.is_open()) {
        while (in.good()) {
            getline(in, ID);
            if (ID == "") {
                break;
            }
            getline(in, course);
            getline(in, letter_grade);

            unsigned long long int studentID = atoll(ID.c_str());
            for (set<StudentInterface*, Comparator>::iterator it = student_set.begin(); it != student_set.end(); it++) {
                StudentInterface* temp = *it;
                if (temp->getID() == studentID) {
                    temp->addGPA(calculateGPA(letter_grade));
                }
            }

            for (map<unsigned long long int, StudentInterface*>::iterator it = student_map.begin(); it != student_map.end(); it++) {
                if (it->first == studentID) {
                    it->second->addGPA(calculateGPA(letter_grade));
                }
            }
        }
        return true;
    }
    else {
        return false;
    }
}



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
    string ID;
    ifstream in (fileName.c_str());

    if(in.is_open()) {
        stringstream out;

        while (in.good()) {
            getline(in, ID);
            //if (ID.substr(0, 1) == "0") {
            //    cout << ID.substr(0, ID.length()) << endl;
            //}

            unsigned long long int studentID = atoll(ID.c_str());
            for (set<StudentInterface*, Comparator>::iterator it = student_set.begin(); it != student_set.end(); it++) {
                StudentInterface* temp = *it;
                if (temp->getID() == studentID) {
                    stringstream ss;
                    ss << temp->getID();

                    //cout << "Before:\t" << studentID << endl;
                    string studentID = ss.str();
                    //cout << "After:\t" << studentID << endl;

                    stringstream gss;
                    gss << setprecision(2) << fixed << temp->getGPA();
                    string precisionGPA = gss.str();
                    string output = studentID + " " + precisionGPA + " " + temp->getName() + "\n";

                    out << output;
                }
            }
        }
        return out.str();
    }
    else {
        return "";
    }
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
    string ID;
    ifstream in(fileName.c_str());

    if(in.is_open()) {
        stringstream out;
        while (in.good()) {
            getline(in, ID);

            unsigned long long int studentID = atoll(ID.c_str());
            for (map<unsigned long long int, StudentInterface*>::iterator it = student_map.begin(); it != student_map.end(); it++) {
                if (it->first == studentID) {
                    stringstream ss;
                    ss << it->first;
                    string IDstring = ss.str();

                    stringstream gss;
                    gss << setprecision(2) << fixed << it->second->getGPA();
                    string precisionGPA = gss.str();
                    string output = IDstring + " " + precisionGPA + " " + it->second->getName() + "\n";
                    out << output;
                }
            }
        }
        return out.str();
    }
    else {
        return "";
    }
}

/*
 * Clears the students from the map and set.
 */
void School::clear() {
    //Iterate over both map and set and call delete on all pointers in each
    //map.clear()
    //set.clear()
    for (map<unsigned long long int, StudentInterface*>::iterator it = student_map.begin(); it != student_map.end(); it++) {
        delete it->second;
    }
    student_map.clear();

    for (set<StudentInterface*, Comparator>::iterator it = student_set.begin(); it != student_set.end(); it++) {
        StudentInterface* temp = *it;
        delete temp;
    }
    student_set.clear();
}
