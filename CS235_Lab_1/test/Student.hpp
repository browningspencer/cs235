//
//  Student.hpp
//  CS235_Lab_1
//
//  Created by Spencer Browning on 6/22/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>


#pragma once

#include "Grade.hpp"
#include <iostream>
#include <string>
#include <vector>

class Student {
    
private:
    std::string id;
    std::string name;
    std::string address;
    std::string phone;
    double total_gpa;
    int total_courses;
    
public:
    Student(std::string i, std::string n, std::string a, std::string p, double total_gpa, int total_course);
    
    ~Student();
    
    std::string getId() { return id; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getPhone() const { return phone; }
    double getTotal_gpa() const { return total_gpa; }
    int getTotal_courses() const { return total_courses; }
    
    void setId(std::string id);
    void setName(std::string name);
    void setAddress(std::string address);
    void setPhone(std::string phone);
    void setTotal_gpa(double total_gpa);
    void setTotal_courses(int total_courses);

    std::string toString() const;
    
    std::vector<Grade> grades;
    
    bool operator < (const Student& s) const;
};

#endif /* Student_hpp */