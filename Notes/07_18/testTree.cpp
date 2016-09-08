#include <iostream>
#include <string>

using namespace std;

#include "Tree.h"

int main() {

	Tree tree;
	
	cout << "preorder: " << tree.preorder() << endl;

	cout << "postorder: " << tree.postorder() << endl;

	cout << "inorder: " << tree.inorder() << endl;

	cout << "size: " << tree.size() << endl;

	cout << "height: " << tree.height() << endl;

	cout << "iterator: ";
	Tree::Iterator i = tree.begin();
	while (i !+ tree.end()) {
		cout << *i;
		++i;
	}
	cout << endl;
	
}