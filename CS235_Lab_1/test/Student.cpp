//
//  Student.cpp
//  CS235_Lab_1
//
//  Created by Spencer Browning on 6/22/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Student.hpp"

#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

Student::Student(string id, string name, string address, string phone, double total_gpa, int total_courses)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->total_gpa = total_gpa;
    this->total_courses = total_courses;
}

Student::~Student()
{
}

string Student::toString() const
{
    stringstream ss;
    
    ss << Student::toString();
    ss << name << endl;
    ss << id << endl;
    ss << phone << endl;
    ss << address << endl;
    
    ss << total_gpa << endl;
    ss << total_courses << endl;
    
    cout << "HERE" << endl;
    
    cout << ss.str();
    return ss.str();
}



bool Student::operator<(const Student& s) const {
    return id < s.id;
}


