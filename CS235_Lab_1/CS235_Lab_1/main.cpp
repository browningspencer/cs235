//
//  main.cpp
//  CS235_Lab_1
//
//  Created by Spencer Browning on 6/22/16.
//  Copyright © 2016 Spencer Browning. All rights reserved.
//


#include "Grade.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
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
//const double E = 0.0;


/*
void display_student(vector<Student> students)
{
    
    
    for (unsigned int j = 0; j < students.size(); j++)
    {
        cout << students[j].getName() << endl;
        cout << students[j].getId() << endl;
        cout << students[j].getPhone() << endl;
        cout << students[j].getAddress() << endl;
    }
    
    cout << endl;
}
*/

/*
void gpa_counter (string id, string letter_grade, vector<Student>& students)
{
    string grades[] = { "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "E" };
    
    for (unsigned int i = 0; i < students.size(); i++)
    {
        if (id == students[i].getId()){
            if(letter_grade == grades[i]) {
                switch(i) {
                    case 0:
                        students[i].set_total_gpa(A);
                        break;
                    case 1:
                        students[i].set_total_gpa(Am);
                        break;
                    case 2:
                        students[i].set_total_gpa(Bp);
                        break;
                    case 3:
                        students[i].set_total_gpa(B);
                        break;
                    case 4:
                        students[i].set_total_gpa(Bm);
                        break;
                    case 5:
                        students[i].set_total_gpa(Cp);
                        break;
                    case 6:
                        students[i].set_total_gpa(C);
                        break;
                    case 7:
                        students[i].set_total_gpa(Cm);
                        break;
                    case 8:
                        students[i].set_total_gpa(Dp);
                        break;
                    case 9:
                        students[i].set_total_gpa(D);
                        break;
                    case 10:
                        students[i].set_total_gpa(Dm);
                        break;
                    case 11:
                        students[i].set_total_gpa(E);
                        break;
                }
            }
        }
        students[i].set_total_courses();
    }
}
*/

void cd (string id, string letter_grade, vector<Student>& students, int i)
{
    
    if (letter_grade == "C+") { students[i].set_total_gpa(Cp); }
    else if (letter_grade == "C")  { students[i].set_total_gpa(C); }
    else if (letter_grade == "C-") { students[i].set_total_gpa(Cm); }
    else if (letter_grade == "D+") { students[i].set_total_gpa(Dp); }
    else if (letter_grade == "D")  { students[i].set_total_gpa(D); }
    else if (letter_grade == "D-") { students[i].set_total_gpa(Dm); }

}

void ab (string id, string letter_grade, vector<Student>& students)
{
    for ( unsigned int i = 0; i < students.size(); i++) {
        if (id == students[i].getId())
        {
            if (letter_grade == "A") { students[i].set_total_gpa(A); }
            else if (letter_grade == "A-") { students[i].set_total_gpa(Am); }
            else if (letter_grade == "B+") { students[i].set_total_gpa(Bp); }
            else if (letter_grade == "B")  { students[i].set_total_gpa(B); }
            else if (letter_grade == "B-") { students[i].set_total_gpa(Bm); }
            else { cd(id, letter_grade, students, i); }
            
            students[i].set_total_courses();
        }
    }
}




/*
void gpa_counter (string id, string letter_grade, vector<Student>& students)
{
    
    
    for (unsigned int i = 0; i < students.size(); i++) {
        
        
        if (id == students[i].getId())
        {
            if (letter_grade == "A") { students[i].set_total_gpa(A); }
            else if (letter_grade == "A-") { students[i].set_total_gpa(Am); }
            else if (letter_grade == "B+") { students[i].set_total_gpa(Bp); }
            else if (letter_grade == "B")  { students[i].set_total_gpa(B); }
            else if (letter_grade == "B-") { students[i].set_total_gpa(Bm); }
            else if (letter_grade == "C+") { students[i].set_total_gpa(Cp); }
            else if (letter_grade == "C")  { students[i].set_total_gpa(C); }
            else if (letter_grade == "C-") { students[i].set_total_gpa(Cm); }
            else if (letter_grade == "D+") { students[i].set_total_gpa(Dp); }
            else if (letter_grade == "D")  { students[i].set_total_gpa(D); }
            else if (letter_grade == "D-") { students[i].set_total_gpa(Dm); }
            else if (letter_grade == "E")  { students[i].set_total_gpa(E); }
            else { students[i].set_total_gpa(E); }
            
            students[i].set_total_courses();
            
        }
    }
}
*/



vector <Student> load_student (string student_file)
{
    ifstream in;
    vector<Student> students;
    
    
    string id;
    string name;
    string address;
    string phone;
    double total_gpa = 0;
    int total_courses = 0;
    
    in.open(student_file);
    
    while (getline(in, id)) {
        getline(in, name);
        getline(in, address);
        getline(in, phone);
        
            total_gpa = 0;
            total_courses = 0;
            Student new_student = Student(id, name, address, phone, total_gpa, total_courses);
            
            students.push_back(new_student);
            
    }
    
    in.close();
    
    sort(students.begin(), students.end());
    
    return students;
}



vector<Grade> load_grade (string grade_file, vector<Student>& students)
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
        
        //gpa_counter(id, letter_grade, students);
        ab(id, letter_grade, students);
        
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



/*
void display_grade(vector<Grade> grades)
{
    for (unsigned int j = 0; j < grades.size(); j++)
    {
        cout << grades[j].getId() << "\t" << grades[j].getGrade() << "\t" << grades[j].getCourse() << endl;
    }
    cout << endl;
 
}
*/




/*
void display_query(vector<Student> students, vector<string> queries)
{
    double avg_gpa = 0;
    
    
    for (unsigned int i = 0; i < queries.size(); i++) {
        
//        cout << "queries: " << queries[i] << endl;
//        cout << "students: " << students[i].getId() << endl;
        
        for (unsigned int j = 0; j < students.size(); j++)
        {
            if (queries[i] == students[j].getId())
            {
                //match
                avg_gpa = students[j].getTotal_gpa() / students[j].getTotal_courses();
                cout << queries[i] << "\t" << avg_gpa << "\t" << students[j].getName() << endl;
            }
            else
            {
                //nomatch
                
            }
        }
    }
}
*/



void save_file(string result, vector<Student> students, vector<Grade> grades, vector<string> queries)
{
    
    ofstream output;
    output.open(result);
    

    for (unsigned int i = 0; i < students.size(); i++)
    {
        output << students[i].getName() << endl;
        output << students[i].getId() << endl;
        output << students[i].getPhone() << endl;
        output << students[i].getAddress() << endl;
    }
    output << endl;
    
    
    for (unsigned int j = 0; j < grades.size(); j++)
    {
        output << grades[j].getId() << "\t" << grades[j].getGrade() << "\t" << grades[j].getCourse() << endl;
    }
    output << endl;
    
    
    double avg_gpa = 0;
    string name;
    
    for (unsigned int k = 0; k < queries.size(); k++)
    {
        for (unsigned int l = 0; l < students.size(); l++)
        {
            if (queries[k] == students[l].getId())
            {
                //match
                if (name != students[l].getName())
                {
                    name = students[l].getName();
                    if (students[l].getTotal_courses() == 0)
                    {
                        output << queries[k] << "\t" << fixed << setprecision(2) << 0.00 << "\t" << name << endl;
                    }
                    else {
                        avg_gpa = students[l].getTotal_gpa() / students[l].getTotal_courses();
                        
                        output << queries[k] << "\t" << fixed << setprecision(2) << avg_gpa << "\t" << name << endl;
                    }
                }
            }
            
        }
        
        
        
    }
    
    output.close();
}


int main(int argc, char* argv[])
{
    string student = argv[1];
    string grade = argv[2];
    string query = argv[3];
    string result = argv[4];

    vector<Student> students = load_student(student);
    vector<Grade> grades = load_grade(grade, students);
    vector<string> queries = load_query(query);
    
    save_file(result, students, grades, queries);
    
    return 0;
    
    /*
     string student = "in10a.txt";
     string grade = "in10b.txt";
     string query = "in10c.txt";
     */
}







