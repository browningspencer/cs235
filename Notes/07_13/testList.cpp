#include <iostream>
#include <string>

using namespace std;

#include "LinkedList.h"


int main() {
	List<string> list;

	cout << "size: " << list.size() << endl;

	cout << "append: hat" << endl;
	list.append("hat");
	cout << "size: " << list.size() << endl;

	cout << "remove: " << list.remove() << endl;
	cout << "size: " << list.size() << endl;

	cout << "append: apple" << endl;
	list.append("apple");
	cout << "size: " << list.size() << endl;

	cout << "append: book" << endl;
	cout << "append: book" << endl;

}