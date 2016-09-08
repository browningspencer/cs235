#include <iostream>
#include <sstream>

#pragma once

using namespace std;

class Tree {

private:
	struct Node {
		string item;
		Node* left;
		Node* right;

		Node (const string& item, Node* left, Node* right) : 

		item(item),
		left(left),
		right(right),

		{}
	};

	Node* root;

public:
	string preorder() const {
		

		return preorder(root);

	}

	string preorder(Node* n) const {

		stringstream out;

		if (n != NULL) {
			out << n->item;			//Parent

			out << preorder(n->left); //Left Child
			out << preorder(n->right); //Right Child
		}

		return out.str(); //outputs string that was built using stringstream
	}

	string postorder() const {

		return postorder(root);
	}

	string postorder(Node* n) const {

		stringstream out;

		if (n!= NULL) {
			out << postorder(n->left);	//Left Child
			out << postorder(n->right);	//Right Child

			out << n->item;				//Parent
		}

		return out.str();
	}

	string inorder() const {


		return inorder(root);

	}

	string inorder(Node* n) const {

		stringstream out;

		if (n != NULL) {
			out << inorder(n->left);	//Left Child
			out << n->item;				//Parent
			out << inorder(n->right);	//Right Child
		}

		return out.str();
	}


	int size() const {

		return size(root);
	}

	int size(Node* n) const {

		if ( n == NULL )
			return 0;
		else
			return size(n->left) + size(n->right) + 1;

	}


	int height () const {

		return height(root);
	}

	int height(Node* n) const {
		if (n == NULL)
			return -1; //More common definition of height
		else
			return max( height(n->left), height(n->right) ) + 1;

	}




	class Iterator {
	private:
		//std:: stack<Node*> items;
		std::queue<Node*> items; //Same as LEVEL ORDER
	
	public:
		Iterator(Node* root) {
			if (root != NULL)
				items.push(root);


		}

		string operator * () const {


			return items.front()->item;
		}

		void operator ++ () {

			Node* n = items.front();
			items.pop();

			if (n->left != NULL)
				items.push(n->left);
			if (n->right !=NULL)
				items.push(n->right);
			
			

		}

		bool operator ! = (const Iterator& i) const {

			return items != i.items;
		}

		

		Iterator begin() const {
			return Iterator(root);
		}

		Iterator end() const {
			return Iterator(NULL);
		}
		Node* makeTree() {


		}
	}
}

