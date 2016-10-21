#include "QS.h"
#include <iostream>
#include <string>


int* myArray;
int sizePointer = -1;
int formalSize = 0;

QS::QS() {
  myArray = NULL;
}

QS::~QS() {
  clear();
}

void swapVal(int first, int second) {
  int temp = myArray[first];
  myArray[first] = myArray[second];
  myArray[second] = temp;
}

void QS::sort(int left, int right) {
  if (right - left == 1) {
    if (myArray[right] > myArray[left]) {
      return;
    }
    else {
      swapVal(right, left);
      return;
    }
  }

  if (right == left) return;

  if (left < 0 || right > sizePointer - 1 || right < left || left > right) {
    return;
  }

  int pivotIndex = medianOfThree(left, right);
  int newIndex = partition(left, right, pivotIndex);

  sort(left, newIndex - 1);
  sort(newIndex + 1, right);
}
/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll() {
  if (sizePointer < 0) {
    return;
  }
  sort(0, sizePointer - 1);
}

/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right) {
  if (sizePointer < 0) {
    return -1;
  }
  if (left > right || left < 0 || right < left || right > sizePointer - 1 || left == right) {
    return -1;
  }

  int pIndex = (left + right) / 2;

  if (!(myArray[left] < myArray[pIndex])) swapVal(left, pIndex);
  if (!(myArray[pIndex] < myArray[right])) swapVal(right, pIndex);
  if (!(myArray[left] < myArray[pIndex])) swapVal(left, pIndex);

  getArray();
  return pIndex;
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not between the two boundaries.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int left, int right, int pivotIndex) {
  if (myArray == NULL) {
    return -1;
  }

  getArray();

  if ((sizePointer < 0) || (formalSize <= 0)) {
    return -1;
  }
  if ((left < 0) || (right < 0)) {
    return -1;
  }
  if (right > sizePointer - 1) {
    return -1;
  }
  if (!(left < right)) {
    return -1;
  }
  if ((!(pivotIndex <= right)) || (!(pivotIndex >= left))) {
    return -1;
  }

  swapVal(right, pivotIndex);
  int i = left;
  int j = right - 1;
  getArray();

  while (i < j) {
    while ((myArray[i] < myArray[right])) {
      i++;
    }
    while ((myArray[j] > myArray[right])) {
      j--;
    }
    if (i < j) {
      swapVal(i, j);
    }
  }

  if (i >= j) {
    swapVal(i, right);
    return i;
  }
  return i;
}

/*
* Produces a comma delimited string representation of the array.
* For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would
* look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals
* the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() {

  if (sizePointer < 0 || formalSize <= 0) {
    return "";
  }

  stringstream ss;
  for (int i = 0; i != sizePointer; i++) {
    ss << myArray[i] << ",";
  }
  string result = ss.str();
  string output = result.substr(0, result.size() - 1);

  return output;
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() {
  return formalSize;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
*/
void QS::addToArray(int value) {

  if (myArray == NULL) {
    return;
  }

  myArray[sizePointer] = value;
  sizePointer++;
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int size) {
  clear();

  if (size == 0) {
    return false;
  }
  else {
    myArray = new int[size];
    sizePointer = 0;
    formalSize = size;
    return true;
  }

}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear() {

  if (myArray == NULL) {
    return;
  }

  delete [] myArray;

  sizePointer = -1;
  formalSize = 0;
  myArray = NULL;
}
