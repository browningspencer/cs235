#include <iostream>
#include <vector>
#include <algorithm>

#include "Book.h"

using std::cout;
using std::endl;
using std::vector;
//The reason you use these ^ instead of "using namespace std;" so that in case
//you need to use mulitiple libraries, it won't break if there are overlaps


int main () {

	Book defoe ("Robinson Crusoe", "Defoe");
	Book swift ("Gulliver's Travels", "Swift");
	Book austen ("Pride and Prejudice", "Austen");
	Book twain ("The Adventures of Tom Sawyer", "Twain");

	cout << defoe.toString() << endl;
	cout << swift.toString() << endl;
	cout << austen.toString() << endl;
	cout << twain.toString() << endl;

	vector<Book> list;

	list.push_back(twain);
	list.push_back(defoe);
	list.push_back(swift);
	list.push_back(austen);

	print(list);

	sort(list.begin(), list.end());

	print(list);
}