#include "linkedlist.hpp"
#include <iostream>
#include <stdexcept>

// Section 3.2: constructor
LinkedList::LinkedList() { // makes a emtpy list with size 0 and head_ is nullptr
    size_ = 0;
    head_ = nullptr;
}

// Section 3.3: insert node at end
void LinkedList::InsertNode(const int value) {
    Node* new_node = new Node(value); // creates a new node with value
    
    if (head_ == nullptr) { // if the head is nullptr, it means the list is empty
        head_ = new_node; // it will set the head to the new node
    } else {
        Node* temp = head_; // it will create a temporary node 
        while (temp->next != nullptr) { // while loop will go through the list until it finds the last node
            temp = temp->next; 
        }
        temp->next = new_node; // it will set the next pointer of the last node to the new node
    }
    size_++; // size increases
}

// Section 3.4: insert node at the front
void LinkedList::InsertNodeFront(const int value) {
    Node* new_node = new Node(value); // creates a new node with value
    new_node->next = head_; // sets the next pointer of the new node to the current head
    head_ = new_node; // sets the head to the new node
    size_++; // size increases
}

// Section 3.5: contains
bool LinkedList::Contains(const int value) const {
    Node* temp = head_; // creates a temporary node 
    while (temp != nullptr) {
        if (temp->value == value) { // while loop to go through the list and if the value is found, it will return true
            return true;
        }
        temp = temp->next;
    }
    return false; // if the value is not found, it will return false
}

// Section 3.6: removes
bool LinkedList::Remove(const int position) {
    if (position < 1 || position > size_) { // uses a or condition, if the position is less than 1 or greater than the size, it will return false
        return false;
    }
    
    Node* to_delete = nullptr; // creates a temporary node to delete
  
    if (position == 1) { // if position is 1, it will delete the head
        to_delete = head_;
        head_ = head_->next; // sets the head to the next node
    } else {
        Node* temp = head_; // creates a temporary node to go through the list
        for (int i = 1; i < position - 1; ++i) { // loops through the list until it finds the node before the one to delete
            temp = temp->next; // moves to the next node
        }
        to_delete = temp->next; // sets the node to delete to the next node
        temp->next = to_delete->next; // unlink the node to delete from the list
    }

    delete to_delete; // deletes the node to save memory
    size_--; // size decreases
    return true;
}

// Section 3.7: print values
void LinkedList::PrintValues() const { // prints the values of the list
    Node* temp = head_; // creates a temporary node to go through the list
    while (temp != nullptr) { // while loop to go through the list and print the values
        std::cout << temp->value << " -> "; // prints the value of the node and an arrow
        temp = temp->next; // moves to the next node
    }
    std::cout << "nullptr" << std::endl;
}

// Section 3.7: print addresses
void LinkedList::PrintAddresses() const { // prints the addresses of the nodes in the list
    Node* temp = head_; // creates a temporary node to go through the list
    int pos = 1; // postion counter is 1
    while (temp != nullptr) { // while loop to go through the list and print the addresses
        std::cout << pos << " " << temp << std::endl; // prints the position and the address of the node
        temp = temp->next; // moves to the next node
        pos++; // increases by 1
    }
}

// Section 3.8: get value at position
int LinkedList::GetValueAtPosition(const int position) const {
    if (position < 1 || position > size_) { // or condition, if the position is less than 1 or greater than the size, it will throw an error
        throw std::out_of_range("Error: Position is out of bounds!");
    }
  
    Node* temp = head_; // creates a temporary node to go through the list
    for (int i = 1; i < position; ++i) { // for loop to go through the list until it finds the node at the position
        temp = temp->next; // moves to the next node
    }
    return temp->value;
}

// Section 3.9: reverse list
LinkedList* LinkedList::ReverseList() { // reverses the list and returns a new list
    Node* prev = nullptr; // creates a temporary node to go through the list
    Node* current = head_; // creates a temporary node to go through the list
    Node* next_node = nullptr; // creates a temporary node to go through the list
    
    while (current != nullptr) { // while loop to go through the list and reverse the pointers
        next_node = current->next; // saves the next node
        current->next = prev; // reverses the pointer of the current node
        prev = current; // moves the prev pointer to the current node
        current = next_node; // goes from the current node to the next node
    }
    
    LinkedList* reversed_list = new LinkedList(); // creates a new list to store the reversed list
    reversed_list->head_ = prev; // sets the head of the new list to the prev pointer
    reversed_list->size_ = size_; // sets the size of the new list to the size of the original list
    
    head_ = nullptr;  // sets the head of the original list to nullptr
    size_ = 0;

    return reversed_list;
}

// Section 3.10: insert node at
void LinkedList::InsertNodeAt(const int value, const int position) {
    if (position < 1 || position > size_ + 1) { // or condtion, if the position is less than 1 or greater than the size + 1, it will throw an error
        throw std::out_of_range("Error: Cannot insert out of list bounds!");
    }
    
    if (position == 1) { // if the position is 1, it will insert the node at the front
        InsertNodeFront(value);
    } else {
        Node* new_node = new Node(value); // temporary node to create a new node
        Node* temp = head_; // temporary node to go through the list
        for (int i = 1; i < position - 1; ++i) { // for loop to go through the list until it finds the node before the position
            temp = temp->next;
        }
        new_node->next = temp->next; // sets the next pointer of the new node to the next pointer of the temp node
        temp->next = new_node;
        size_++; // size increases 
    }
}

// Section 3.11: get size
int LinkedList::GetSize() const { // returns the size of the list
    return size_;
}

// Section 3.12: merge intertwine
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
    LinkedList* merged_list = new LinkedList(); // creates a new list to store the merged list
    Node* p1 = head_; // creates a temporary node to go through the first list
    Node* p2 = second_list.head_; // creates a temporary node to go through the second list
    
    while (p1 != nullptr || p2 != nullptr) { // while loop to go through both lists until both are nullptr
        if (p1 != nullptr) {
            merged_list->InsertNode(p1->value); // insertes the value if the first list is not nullptr
            p1 = p1->next;
        }
        if (p2 != nullptr) {
            merged_list->InsertNode(p2->value); // insertes the value if the second list is not nullptr
            p2 = p2->next;
        }
    }

    return merged_list;
}

// Section 3.13: destructor
LinkedList::~LinkedList() { // destructor to free the memory of the list
    Node* current = head_; // creates a temporary node to go through the list
    while (current != nullptr) {
        Node* next_node = current->next; // while loop and saves the next node
        delete current; // deletes the current node to free memory
        current = next_node;
    }
}
   


