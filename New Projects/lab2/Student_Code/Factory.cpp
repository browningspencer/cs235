#include "Factory.h"
#include "LinkedListInterface.h"
#include "LinkedList.h"

using namespace std;

/*
    You will MODIFY THIS DOCUMENT.
 */
//=======================================================================================
/*
	getLinkedListInt()

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<int>();".
*/
LinkedListInterface<int>* Factory::getLinkedListInt() {
    return new LinkedList<int>();
}

/*
	getLinkedListString()

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<string>();".
*/
LinkedListInterface<string>* Factory::getLinkedListString() {
    return new LinkedList<string>();
}
//=======================================================================================
