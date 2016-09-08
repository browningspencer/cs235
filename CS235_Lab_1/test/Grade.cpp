//
//  Grade.cpp
//  CS235_Lab_1
//
//  Created by Spencer Browning on 6/23/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Grade.hpp"
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
