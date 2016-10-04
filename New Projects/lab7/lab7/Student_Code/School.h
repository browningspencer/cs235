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
private:
    map<unsigned long long int,StudentInterface*> student_map;
    set<StudentInterface*,Comparator> student_set;
    
    string ID;
    string course;
    string letter_grade;
    
public:
    School(string i, string c, string g) {
        this->ID = ID;
        this->course = course;
        this->letter_grade = letter_grade;
    }
    ~School() {}
    

    virtual map<unsigned long long int,StudentInterface*> getMap();

    virtual set<StudentInterface*,Comparator> getSet();

    virtual bool importStudents(string mapFileName, string setFileName);

    virtual bool importGrades(string fileName);
    
    virtual string querySet(string fileName);

    virtual string queryMap(string fileName);

    virtual void clear();
    
};



#endif /* School_h */

/* Grade.h
class Grade {
private:
    std::string course;
    std::string id;
    std::string letter_grade;
    
public:
    Grade(std::string c, std::string i, std::string g);
    ~Grade();
    
    
    std::string getCourse() const { return course; }
    std::string getId() const { return id; }
    std::string getGrade() const { return letter_grade; }
    
    void setCourse(std::string course);
    void setId(std::string id);
    void setGrade(std::string letter_grade);
    
    std::string toString() const;
    
    bool operator < (const Grade& g) const;
    
};
*/


