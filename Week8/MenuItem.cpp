#include "MenuItem.h"

#include <iomanip>
#include <iostream>

// default constructor
MenuItem::MenuItem() {
  name_ = ""; //. makes the name a emtpy string
  category_ = ""; 
  price_ = 0.0; // sets price to 0
  stock_ = 0;
}

// parameter constructor
MenuItem::MenuItem(const std::string& name, // gets the name
                   const std::string& category, 
                   double price, // gets the price
                   int stock) {
  name_ = name; // stores the name
  category_ = category; // stores the category
  price_ = price;
  stock_ = stock;
}

// gets the items names
std::string MenuItem::GetName() const { 
  return name_;
}
// gets the items category
std::string MenuItem::GetCategory() const {
  return category_;
}
// gets the items price
double MenuItem::GetPrice() const {
  return price_;
}
// gets the items stock 
int MenuItem::GetStock() const {
  return stock_;
}

// sets the items name
void MenuItem::SetName(const std::string& name) {
  name_ = name;
}
// sets the items category
void MenuItem::SetCategory(const std::string& category) {
  category_ = category;
}
// sets the items price
void MenuItem::SetPrice(double price) {
  price_ = price;
}
// sets the items stock
void MenuItem::SetStock(int stock) {
  stock_ = stock;
}

// prints one menu item
void MenuItem::PrintItem() const {
  std::cout << std::left
            << std::setw(25) << name_ //. sets the width
            << std::setw(15) << category_ // sets the width
            << std::right // 
            << std::fixed // shows the decimal places
            << std::setprecision(2) // shows two digits after the decimal
            << std::setw(8) << price_ // sets width
            << std::setw(8) << stock_ // sets width
            << std::endl;
}