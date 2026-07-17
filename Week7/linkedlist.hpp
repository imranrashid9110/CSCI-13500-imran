#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>
#include <stdexcept>

// section 3.1
struct Node {
  int value;
  Node* next;
  Node(int passed_value) : value(passed_value), next(nullptr) {}
};

// section 3.2
class LinkedList {
 public:
 LinkedList();

 private:
 int size_;     
  Node* head_;   

 public:

 // section 3.3
 void InsertNode(const int value);

 // section 3.4
 void InsertNodeFront(const int value);
 
 // section 3.5
 bool Contains(const int value) const;

 // section 3.6
 bool Remove(const int position);

 // section 3.7
 void PrintValues() const;
 void PrintAddresses() const;

// section 3.8
int GetValueAtPosition(const int position) const;

// section 3.9
LinkedList* ReverseList();

// section 3.10
void InsertNodeAt(const int value, const int position);

// section 3.11
int GetSize() const;

// section 3.12
LinkedList* MergeIntertwine(const LinkedList& second_list) const;

// section 3.13
~LinkedList();
};

#endif


