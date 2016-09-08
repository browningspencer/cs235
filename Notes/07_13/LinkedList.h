// implement a List using linked nodes

templates<typename ItemType> //Best practice is to put templates in .h files. Only one per .h file

class List {
private:
	struct Node {
		ItemType item;
		Node* next;
		Node* prev;
	};

	int count;
	Node* head;
	Node* tail;

public:
	List() : 
		count (0),
		head(NULL),
		tail(NULL)

	{}

	int size() const {

		return count;
	}

	void append(const ItemType& item) {

		//this was a stub or an empty function. So you can run your 
		//project sooner and catch errors. Code a little bit, test a little bit.
		Node* node = new Node();
		node->item = item;
		//this ^ the same as (*node).item = item;
		//node is a pointer, so dereferrencing it will allow me to 
		//grab the itme it's pointing at
		if (tail == NULL)
			head = node;
		else
			tail->next = node;


		node->prev = tail;
		node->next = NULL;
		tail = node;

		count++;
	}

	ItemType remove() {
		
		Node* temp = head->next;
		ItemType stuff = head->item;
		delete head;

		count--;

		if (count == 0)
			tail = NULL;
		else
			temp->prev = NULL;

		head = temp;

		

		return stuff;
	}

	~List() {
		while (size() > 0)
			remove();
	}

	List(const List& list) {
		
	}
}
