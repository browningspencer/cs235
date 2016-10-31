#pragma once
#include "LinkedListInterface.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T> {
private:
  struct Node {
    T info;
    Node* next;
  };

  int count;
  Node* head;
  Node* tail;

public:
  LinkedList() :
    count (0),
    head(NULL),
    tail(NULL)
  {}
  ~LinkedList() {
    clear();
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  bool checkIfInList(T value) {
    struct Node *q;
    q = head;
    for (int i = 0; i < count; i++) {
      if (value == q->info) {
        return true;
      }
      q = q->next;
    }
    return false;
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void insertHead(T value) {
    //cout << "\tINSERTHEAD" << endl;
    if (checkIfInList(value)) {
      return;
    }

    struct Node *temp, *q;
    q = head;
    temp = new(struct Node);
    temp->info = value;

    if (count == 0) {
      temp->next = NULL;
      head = temp;
      tail = temp;

      count++;
      return;
    }
    else {
      temp->next = q;
      head = temp;

      count++;
      return;
    }
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void insertTail(T value) {
    //cout << "\tINSERTTAIL" << endl;
    if (checkIfInList(value)) {
      return;
    }

    struct Node *temp, *q;
    q = head;
    temp = new(struct Node);
    temp->info = value;

    if (count == 0) {
      temp->next = NULL;
      head = temp;
      tail = temp;

      count++;
      return;
    }
    else {
      for (int i = 0; i < count; i++) {
        if (q->next != NULL) {
          q = q->next;
        }
      }

      q->next = temp;
      temp->next = NULL;
      tail = temp;
      count++;
    }
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Issue might be here. Somehow, when the program inserts a node in, I don't think
  //it is properly connecting the nodes, and so nodes are getting lost
  void insertAfter(T value, T insertionNode) {
    //cout << "\tINSERTAFTER" << endl;
    if (checkIfInList(value)) {
      return;
    }

    struct Node *temp, *q;
    q = head;
    temp = new(struct Node);
    temp->info = value;

    if (count == 0) {
      temp->next = NULL;
      head = temp;
      tail = temp;

      count++;
      return;
    }
    else {
      while (insertionNode != q->info) {
        q = q->next;
      }

      Node *x = q;
      q->next = temp;
      temp->next = x;
    }
    count ++;
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void remove(T value) {
    //cout << "\tREMOVE" << endl;
    Node *q = head;
    Node *x = q;

    if (count == 1) {
      if (value == q->info) {
        delete q;
        head = NULL;
        tail = NULL;

        count--;
        return;
      }
      return;
    }
    else if (value == q->info) {
      Node *temp;
      temp = q;
      q = q->next;
      head = q;
      delete temp;

      count--;
      return;
    }
    else {
      while (value != q->info) {
        x = q;
        q = q->next;
      }

      if (q->next == NULL) {
        Node *temp = q;
        q = x;
        q->next = NULL;
        tail = q;
        delete temp;
      }
      else {
        Node *temp = q;
        Node *y = q;

        q = x;
        y = y->next;
        q->next = y;
        delete temp;
      }
      count--;
      return;
    }
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void clear() {
    Node *del = head;

    while (head != NULL) {
      del = head;
      head = head->next;
      delete del;
    }

    tail = NULL;
    head = NULL;

    count = 0;
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  T at(int index) {
    //cout << "\tAT" << endl;
    Node *temp = head;

    if (index < 0) {
      throw out_of_range("");
    }

    if (index >= count) {
      throw out_of_range("");
    }
    else {
      for (int i = 0; i < index; i++) {
        temp = temp->next;
      }

      return temp->info;
    }
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int size() {
    return count;
  }

};
