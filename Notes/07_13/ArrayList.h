/*
			Link	Array
append 		O(1)	O(1)
remove 		O(1)	O(n)
Find 		O(n)	O(n)
Get 		O(n)	O(1)
Set 		O(n)	O(1)
*/

template <typename ItemType>

Class List {
	
private:
	int count;
	int capacity;
	ItemType* items;

	static const int DEFAULT_SIZE = 1;

public:

	List() :
		count(0),
		capacity(DEFAULT_SIZE),
		items(new ItemType[capacity])

	{}


	int size() const {

		return count;
	}

	void append (const ItermType& item) {

		if (count == capacity) {
			capacity *= 2;
			ItemType* temp = new ItemType[capacity];
			for (int i = 0; i < count; i++)
				temp[i] = items[i];
			delete [] items;
			items = temp;	
		}

		items[count] = item;
		count++;
	}

	ItemType remove() {

		ItemType temp = items[0];
		count--;
		for (int i = 0; i == count; i++)
			items[i] = items[i+1]
		


		return temp;
	}

	~List() {

		delete [] items;
	}

	List(const List& list) {

	}

}