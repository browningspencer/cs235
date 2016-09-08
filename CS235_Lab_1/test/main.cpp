//
//  main.cpp
//  CS235_Lab_1
//
//  Created by Spencer Browning on 6/22/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//


#include "Grade.hpp"
#include "Student.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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



void gpa_counter (string id, string letter_grade, vector<Student> students)
{
    
    double total_gpa = 0;
    int total_courses = 0;
    
    
    for (unsigned int i = 0; i < students.size(); i++) {
        if (id == students[i].getId())
        {
            if (letter_grade == "A") { total_gpa += A; }
            else if (letter_grade == "A-") { total_gpa += Am; }
            else if (letter_grade == "B+") { total_gpa += Bp; }
            else if (letter_grade == "B")  { total_gpa += B; }
            else if (letter_grade == "B-") { total_gpa += Bm; }
            else if (letter_grade == "C+") { total_gpa += Cp; }
            else if (letter_grade == "C")  { total_gpa += C; }
            else if (letter_grade == "C-") { total_gpa += Cm; }
            else if (letter_grade == "D+") { total_gpa += Dp; }
            else if (letter_grade == "D")  { total_gpa += D; }
            else if (letter_grade == "D-") { total_gpa += Dm; }
            else if (letter_grade == "E")  { total_gpa += E; }
            else { total_gpa += 0; }
            
            total_courses += 1;
        }
    }

}




vector <Student> load_student (ifstream &in)
{
//    ifstream in;
    vector<Student> students;
    //string s;
    
    
    string id;
    string name;
    string address;
    string phone;
    double total_gpa = 0;
    int total_courses = 0;
    
//    in.open(student_file);
    
    cout << "Test" << endl;
    
    
    while (getline(in, id)) {
        getline(in, name);
        getline(in, address);
        getline(in, phone);
        total_gpa = 0;
        total_courses = 0;
        
        Student new_student = Student(id, name, address, phone, total_gpa, total_courses);
        
        students.push_back(new_student);
        //cout << s;

//        cout << name << endl;
    }
    
    cout << name << endl;
    
//    in.close();
    
    sort(students.begin(), students.end());
    
    return students;
}



vector<Grade> load_grade (string grade_file, vector<Student> students)
{
    
    
    ifstream in;
    vector<Grade> grades;
    
    string course;
    string id;
    string letter_grade;
    
    
    in.open(grade_file);
    
    while (getline(in, course)) {
        getline(in, id);
        getline(in, letter_grade);
        
        gpa_counter(id, letter_grade, students);
        
        Grade new_grade = Grade(course, id, letter_grade);
        
        grades.push_back(new_grade);
    }
    
    in.close();
    
    sort(grades.begin(), grades.end());
    
    return grades;
}





vector <string> load_query(string query_file)
{
    ifstream in;
    vector<string> queries;
    
    string id;
    
    in.open(query_file);
    
    while (in >> id) {
        
        string new_id = string(id);
        
        queries.push_back(new_id);
    }
    
    in.close();
    
    return queries;
}






void display_student(vector<Student> students)
{
    
    cout << "HERE!!!" << endl;
    /*
    for (unsigned int j = 0; j < students.size(); j++)
    {
        cout << students[j].getName() << endl;
    }
    */
    
    for (unsigned int i = 0; i < students.size(); i++)
    {
        cout << "HERE" << i << endl;

        cout << students[i].toString() << endl;
    }
}





void display_grade(vector<Grade> grades)
{
    for (unsigned int i = 0; i < grades.size(); i++)
    {
        cout << grades[i].toString() << endl;
    }
}






void display_query(vector<Student> students, vector<string> queries)
{
    double avg_gpa = 0;
    
    
    for (unsigned int i = 0; i < queries.size(); i++) {
        
        for (unsigned int j = 0; j < students.size(); i++) {
            if (queries[i] == students[j].getId())
            {
                avg_gpa = students[j].getTotal_gpa() / students[j].getTotal_courses();
                
                
                cout << queries[i] << "\t" << avg_gpa << "\t" << students[j].getName() << endl;
            }
        }
    }
}



int main(int argc, char* argv[])
{
    string student = argv[0];
    string grade = argv[1];
    string query = argv[2];

    /*
    string student = "in10a.txt";
    string grade = "in10b.txt";
    string query = "in10c.txt";
    */
     
     
    ifstream in;
    in.open(student);
    
    if (!in.is_open()) { cout << "I've failed!" << endl; }
    load_student(in);
    in.close();
     
    /*
    cout << "Hey" << endl;
    vector<Student> students = load_student(student);
    display_student(students);
    cout << "a" << endl;
    
    cout << "b" << endl;
    vector<Grade> grades = load_grade(grade, students);
    display_grade(grades);
    cout << "c" << endl;
    
    cout << "d" << endl;
    vector<string> queries = load_query(query);
    display_query(students, queries);
    cout << "e" << endl;
    */
    
    return 0;
}







