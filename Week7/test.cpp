#include <iostream>
#include "linkedlist.hpp"

int main() {
    LinkedList list;
    list.InsertNode(10);
    list.InsertNode(20);
    list.InsertNodeFront(5);

    std::cout << "My list: ";
    list.PrintValues(); // Should print: 5 -> 10 -> 20 -> nullptr
    return 0;
}