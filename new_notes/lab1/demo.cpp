#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main (int argc, char* argv[]) {

	ifstream in;
	in.open(argv[1]);

	string item;
	vector<string> items;

	while (in >> item) {
		cout << item << endl;
		items.push_back(item);
	}

	in.close();
}