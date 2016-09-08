/*
	Terminal codes for running test cases.


	DEBUGGING
	g++ -g -Wall -std=c++11 -o "file_name" "file_name.file_type" (ex. Notes Notes.cpp)

	RUN
	./"file_name" "test_name.test_type" (ex ./Notes items.txt)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

int main(int argc, char* argv[]) {

	ifstream in; //TA test files will have permissions, therefore always use ifsteam, not fstream
	string s;
	vector<string> items;

	in.open(argv[1]);

	while (in >> s) { //do this instead of eof, it will be more successful
		//cout << s << endl;
		items.push_back(s);
	}

	in.close();


	print(items); //print() would be a separete file that has the function to print out the vector

	sort(items.begin(), items.end());

	print(items);

	ofstream out;

	out.open(argv[2]);

	// easier than below
	/*
	for (auto item : items)
		out << item << endl
	*/

	for (unsigned int i = 0; i < items.size(); i++) 
	{
		out << items[i] << endl;
	}

	out.close();
}