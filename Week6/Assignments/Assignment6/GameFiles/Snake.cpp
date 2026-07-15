#include "Snake.h"
#include <iostream>

// TODO: Constructor
// - Build a snake with STARTING_LENGTH segments using `new`.
// - head should point to segment id 0 (or 1, your choice - just be consistent),
//   tail should point to the last segment created.
// - Set length and nextId appropriately.
Snake::Snake() {
    head_ = nullptr;
    tail_ = nullptr;
    length_ = 0;
    id_ = 0;
    // TODO: allocate STARTING_LENGTH nodes and link them together
    for (int step = 0; step < STARTING_LENGTH; ++step) { // loops through the starting length and creates a new node
        Node* new_segment = new Node;  // creates a new node
        new_segment->body_part_ = id_; // assigns the id to the new node
        new_segment->next_ = nullptr; // sets the next pointer to nullptr 
        id_++; // increaes the id for the next node

        if (head_ == nullptr) { // if the head is nullptr, it means the snake is currently emtpy
            head_ = new_segment; // sets the head to the new node
            tail_ = new_segment; // sets the tail to the new node
        } else {
            tail_->next_ = new_segment; // connects the current tail to the new node
            tail_ = new_segment; // updates the tail to the new node
        }
        length_++; // increases the length of the snake by 1
    }
}

// TODO: Destructor
// - Walk the list and delete every remaining node.
// - If you don't do this, running under valgrind/ASan will report a leak.
Snake::~Snake() {
    // TODO
    Node* current_segment = head_; // starts from the head of the snake
    while (current_segment != nullptr) { // a while loop that goes on until it reaches nullptr
        Node* next_segment_to_delete = current_segment->next_; // saves the next segment to delete
        delete current_segment; // deletes to save memory
        current_segment = next_segment_to_delete; // moves to the next segment
    }   
    head_ = nullptr;
    tail_ = nullptr;
   length_ = 0;
}

// TODO: kill()
// - Remove up to `count` nodes from the FRONT of the list, deleting each one.
// - Handle the edge case where the snake has fewer than `count` nodes left:
//   kill all remaining nodes and stop. Do not crash.
// - Update `length` (and `tail`/`head` if the snake becomes empty!).
// - Return the number of segments ACTUALLY killed.
int Snake::Kill(int count) {
    // TODO
    if (count <= 0 || head_ == nullptr) { // uses a or condition, if the count is less than or equal to 0, or the head is nullptr, it will return 0
        return 0;
    }

    int actual_killed_count = 0;
    while (head_ != nullptr && actual_killed_count < count) { // uses a and condition, if the head is not nullptr and the actual killed count is less than the count, it will continue to kill segments
        Node* segment_to_kill = head_; // saves the current head to delete
        head_ = head_->next_; // moves the head to the next segment
        delete segment_to_kill; // deletes the current head to save memory   
        actual_killed_count++; // increases kill count by 1
        length_--; // length decreases by 1
    }
    if (head_ == nullptr) { // if the head is nullptr, it means the snake is empty
        tail_ = nullptr; // if its emtpy, the tail will also be nullptr
    }
    return actual_killed_count;
}

// TODO: regenerate()
// - Append `count` new nodes to the BACK of the list using `new`.
// - Use `nextId` to assign each new node a unique, increasing id, and
//   increment `nextId` each time.
// - Update `tail` (and `head` if the snake was empty!) and `length`.
void Snake::Regenerate(int count) {
    // TODO
    for (int step = 0; step < count; ++step) { // loops through the count and creates a new node
    Node* brand_new_segment = new Node; // creates a new node
    brand_new_segment->body_part_ = id_; // assigns the id to the new node
    brand_new_segment->next_ = nullptr; // sets the next pointer to nullptr

    id_++; // id_ increases by 1 for the next node

    if (head_ == nullptr) { // if the head is nullptr, it means the snake is currently empty
        head_ = brand_new_segment; // sets the head to the new node
        tail_ = brand_new_segment; // sets the tail to the new node
        } else {
            tail_->next_ = brand_new_segment; // connects the current tail to the new node
        }
      tail_ = brand_new_segment;

      length_++; // length increases by 1
    }
}

// TODO: print()
// - Walk the list from head to tail and print in the format:
//   Snake: [12] -> [13] -> [14] -> [15]
// - If the snake is empty, print something sensible like "Snake: (dead)".
// - This function must not modify the snake - use a `const Node*` to walk it.
void Snake::PrintSnake() const {    // TODO
    if (head_ == nullptr) { // if the head is nullptr, it means the snake is empty
    std::cout << "Snake: (dead)" << std::endl; // prints out a message that the snake is dead
    return;
  }
std::cout << "Snake: "; // prints out the snake
const Node* current_segment = head_; // starts from the head of the snake
  while (current_segment != nullptr) { // a while loop that goes on until it reaches nullptr
    std::cout << "[" << current_segment->body_part_ << "]"; 
    if (current_segment->next_ != nullptr) { // if the next pointer is not nullptr, it means there are more segments to print
      std::cout << " -> ";
    }
    current_segment = current_segment->next_; // moves to the next segment
  }
  std::cout << std::endl; 
}

int Snake::GetLength() const {
    // TODO
    return length_;
}
