//Standard practice is to avoid using "using namespace std;", you have to call them
//everytime (ex. std::vector) (ex. std::cout)

#pragma once //allows any file that includes Book.h to share #includes

#include <iostream>
#include <string>


class Book {



private: //Only includes variables
	string title;
	string author;

public: // only includes functions

	bool operator < (Book b2) { //Defines the comparison called by sort()
		return this->title < b2.title; //that's called in Test.cpp.
	}// Pointers ^ use -> instead of . (ex "this->title", not "this.title")

	Book(string t, string a) : title(t), author(a) {}

	string getTitle() const { return title; }

	string getAuthor() const { return author; }

	void setTitle(string title);

	void setAuthor(string author);

	string toString() const; 

};