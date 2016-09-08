//
//  Grade.h
//  CS235_Lab_1
//
//  Created by Spencer Browning on 6/23/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Grade_hpp
#define Grade_hpp

#include <stdio.h>


#pragma once

#include <iostream>
#include <string>

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


#endif /* Grade_hpp */


