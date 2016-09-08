


class BST {


private:
	struct Node {

		ItemType item;
		Node* left;
		Node* right;

		Node(const ItemType( item))
	}
public:
	void insert(const ItemType& item) {

		insert(root, item);

	}

	void insert(Node*& n, const ItemType& item) {

		if(n == NULL)
			n = new Node(item)
		
		else if (item < n->item)
			insert(n->left, item);
		
		else if (item > n->item)
			insert(n->right, item);
		
		//else if (item == n->item)
			//; Do nothing
	}

	bool find (const ItemType& item) const {

		return find(root, item);
	}

	bool find(Node* n, const ItemType& item) const {

		if (n == NULL)
			return false;

		else if (item < n->item)
			return find(n->left, item);
		
		else if (item > n->item)
			return find(n->right, item);
		
		else
			return true;
	}

	void remove (const ItemType& item) {

		remove(root, item);
	}

	void remove(Node*& n, const ItemType& item) {

		if(n == NULL)
			return;

		else if (item < n->item)
			remove(n->left, item);
		
		else if (item < n->item)
			remove(n->right, item);
		
		else {		//1-child case
			//if (n->left == NULL && n->right == NULL) 
			//	n = NULL;
			if (n-> left == NULL)
				n = n->right;
			else if (n->right == NULL)
				n = n->left;
			else {	//2-child case
				n->item = findMin(n->right);
				remove(n->right, n->item);

			}
		}
	}

	ItemType findMin(Node* n) const {
		if (n->left == NULL)
			return n->item;
		else
			return findMin(n->left);

	}

	BST() :
		root(NULL)

}