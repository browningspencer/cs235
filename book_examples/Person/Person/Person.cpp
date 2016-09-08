//
//  Person.cpp
//  Person
//
//  Created by Spencer Browning on 6/22/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//

#include "Person.hpp"

#include <ostream>
using std::ostream;



int Person::age(int year) const {
    return year - birth_year;
}

bool Person::can_vote(int year) const {
    int the_age = age(year);
    return the_age >= VOTE_AGE;
}

bool Person::is_senior(int year) const {
    return age(year) >= SENIOR_AGE;
}

bool Person::operator==(const Person& per) const {
    return ID_number == per.ID_number;
}

bool Person::operator!=(const Person& per) const {
    return !(*this == per);
}

ostream& operator<<(ostream& os, const Person& per) {
    os << "Given name: " << per.given_name << '\n' << "Family name: " << per.family_name << '\n' << "ID number: " << per.ID_number << '\n' << "Year of birth: " << per.birth_year << '\n';
    return os;
}
