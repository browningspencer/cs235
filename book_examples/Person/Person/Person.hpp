//
//  Person.hpp
//  Person
//
//  Created by Spencer Browning on 6/22/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

#include <string>
#include <iostream>

class Person {

public:
    
    Person(std::string first, std::string family, std::string ID, int birth) : given_name(first), family_name(family), ID_number(ID), birth_year(birth) {}
    
    Person() : given_name(""), family_name(""), ID_number(""), birth_year(1900) {}
    
    
    
    void set_given_name(std::string given) {
        given_name = given;
    }
    void set_family_name(std::string family) {
        family_name = family;
    }
    void set_birth_year(int birth) {
        birth_year = birth;
    }
    
    std::string get_given_name() const { return given_name; }
    std::string get_family_name() const { return family_name; }
    std::string get_ID_number() const { return ID_number; }
    int get_birth_year() const { return birth_year; }
    
    int age(int year) const;
    bool can_vote(int year) const;
    bool is_senior(int year) const;
    
    bool operator==(const Person& per) const;
    bool operator!=(const Person& per) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Person& per);
    
private:
    std::string given_name;
    std::string family_name;
    std::string ID_number;
    int birth_year;
    
    static const int VOTE_AGE = 18;
    static const int SENIOR_AGE = 65;
};



#endif /* Person_hpp */
