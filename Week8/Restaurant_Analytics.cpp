#include "Restaurant_Analytics.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 

namespace restaurant_util { // uses the namespace restaurant_util to avoid naming conflicts with other code
// function one
int StringToInt(const std::string& text) { // gets a string by const reference
  int number = 0; // sets the initial value of number to 0
  int sign = 1; // sets the initial value of sign to 1 
  int index = 0; // sets the initial value of index to 0

  while (index < static_cast<int>(text.size()) && text[index] == ' ') { // skips any leading whitespace characters and loops through the string until the end of the string is reached
    index++; // increments the index to move to the next character
  }

  if (index < static_cast<int>(text.size()) && text[index] == '-') { // uses if statements to check for a sign character at the start of the string and if the character is a negative sign, it sets the sign variable to -1
    sign = -1; // sets the sign variable to -1 
    index++; // index increases to move to the next character
  } else if (index < static_cast<int>(text.size()) && text[index] == '+') { // uses else if to check for a positive sign character at the start of the string // if the character is a positive sign, it does not change the sign variable
    index++;
  }

  if (index >= static_cast<int>(text.size())) { // if statement to check if the string is empty or only contains whitespace characters
    std::cerr << "Error: Invalid integer: " // it will print an error message to the console and return 0
              << text // prints the invalid integer 
              << std::endl; // prints a new line
    return 0; // returns 0 to indicate an error
  }

  while (index < static_cast<int>(text.size())) { // while loop to go through the string and convert each character to an integer
    char current_character = text[index]; // sets the current character to the character at the current index

    if (current_character == ' ') { // if statement to check for whitespace characters in the middle of the string
      while (index < static_cast<int>(text.size()) && text[index] == ' ') { // while loop to skip any whitespace characters
        index++; // index increases to move to the next character
      }

      if (index != static_cast<int>(text.size())) { // if statement to check if there are any non-whitespace characters after the whitespace characters
        std::cerr << "Error: Invalid integer: " // it will print an error message to the console and return 0
                  << text // prints the invalid integer
                  << std::endl; 
        return 0;
      }

      break; // breaks out of the while loop if there are no non-whitespace characters after the whitespace characters
    }

    if (current_character < '0' || current_character > '9') { // if the character is not a digit, it will print an error message,
      std::cerr << "Error: Invalid integer: " // prints error message
                << text // prints the invalid integer
                << std::endl;
      return 0;
    }

    number = number * 10 + ( current_character - '0'); // moves the previous digit by one to the left and adds a new digit
             
    index++; // increases by 1
  }

  return number * sign; // uses the sign and returns the integar
}
// function two
void LoadInventory(const std::string& filename, // gets the csv file name by using const
                   std::vector<MenuItem>& inventory) { // gets the inventory without being changed
  std::ifstream input_file(filename); // opens the file using ifstream

  if (!input_file.is_open()) { // if statement to check if the file opened
    std::cerr << "Error: Could not open " // prints error message
              << filename // prints the name of the file that couldnt open
              << std::endl;
    return; // stops th efunction 
  }

  inventory.clear(); // removes the existing material from the inventory vector

  std::string line; // stores a line from the csv file

  while (std::getline(input_file, line)) { // while loop to read each line of the whole file
    if (line.empty()) { // checks if the line is emtpy
      continue; // skips the emtpy line and moves onto the next
    }

    std::stringstream line_stream(line); // creates a stream for seperating the values from csv

    std::string name; // stores the menus name
    std::string category; // stores the menus category
    std::string price_text; // stores the menus price before it turns into double
    std::string stock_text; // stores stock before it gets turned into a integar

    std::getline(line_stream, name, ','); // reads the name up until the first comma
    std::getline(line_stream, category, ','); // reads the category up until the first comma
    std::getline(line_stream, price_text, ','); // reads the price up until the first comma
    std::getline(line_stream, stock_text); // reads the stock to the end of the line

    double price = 0.0; // a varaiable that stores the price
    std::stringstream price_stream(price_text); // creates a stream from the price string
    price_stream >> price; // changes the price string into a double

    int stock = StringToInt(stock_text); // changes the stock string to int

    MenuItem item(name, category, price, stock); // creates menuitem using csv values
    inventory.push_back(item); // adds it to the inventory vector
  }

  input_file.close(); // closes the file after all the lines were read
}
// function threee
void PrintInventory(
    const std::vector<MenuItem>& inventory) { // gets the inventory without being changed
  for (int i = 0; i < static_cast<int>(inventory.size()); i++) { // for loop starts from the beginning and going through everything in the inventory and moves to the next position
       inventory[i].PrintItem(); // prints the current menu item
  }
    }
// function four
void FilterByCategory(
    const std::vector<MenuItem>& inventory, // gets the inventory without being changed
    const std::string& category) { // gets the category
  for (int i = 0; i < static_cast<int>(inventory.size()); i++) { // for loop going through the inventory and postion moving up by 1
    if (inventory[i].GetCategory() == category) { // checks if the category matches
      inventory[i].PrintItem(); // prints the items if it matches
    }
  }
}
// function five
void FilterByPriceRange(
    const std::vector<MenuItem>& inventory, // gets the inventory without being changed
    double minimum_price, // varaible for the lowest price
    double maximum_price) { // variable for the highest price
  for (int i = 0; i < static_cast<int>(inventory.size()); i++) { // for loop going through the inventory and position moving up by 1
    double price = inventory[i].GetPrice(); // gets the price of the current one

    if (price >= minimum_price && price <= maximum_price) { // checks if the price is below the minimum and checks if the price is above the maximum
      inventory[i].PrintItem(); // prints the item if the price meets the conditions
    }
  }
}
// function six
MenuItem* FindItemByName(
    std::vector<MenuItem>& inventory, // gets the inventory without being changed
    const std::string& target_name) { // gets the name thats been searched for
  for (int i = 0; i < static_cast<int>(inventory.size()); i++) { // for loop to go through the inventory and position increases by 1
    if (inventory[i].GetName() == target_name) { // checks if the item name matches
      return &inventory[i]; // returns the memory address of that item
    }
  }

  return nullptr;
}
// function seven
void ApplyCategoryDiscount(
    std::vector<MenuItem>& inventory, // gets the inventory by reference
    const std::string& category, // gets the category thats discounted
    double discount_decimal) { // stores it
  if (discount_decimal < 0.0 || discount_decimal > 1.0) { // checks if its below 0% and above 100%
    std::cerr
        << "Error: Discount must be between 0 and 1." // prints error message
        << std::endl;
    return;
  }

  for (int i = 0;
       i < static_cast<int>(inventory.size()); i++) { // for loop to go through the inventory and moving the position up by 1
    if (inventory[i].GetCategory() == category) { // checks if the category matches
      double old_price = inventory[i].GetPrice(); // gets the current price of the item
      double new_price = old_price * (1.0 - discount_decimal); // calculates the price after discount

      inventory[i].SetPrice(new_price); // puts in the new discounted price
    }
  }
}
//function nine
std::vector<MenuItem> GetLowestStockItems(
    const std::vector<MenuItem>& inventory, int k) { // gets the orginal inventory
  if (k <= 0) { // checks if the number of items is invalid
    std::vector<MenuItem> empty_result; // creates a emtpy vector
    return empty_result; // returns the emtpy set if k is not a postive number
  }

  std::vector<MenuItem> sorted_inventory = inventory; // gets a copy of original inventory

  for (int i = 0; i < static_cast<int>(sorted_inventory.size()) - 1; i++) { // for loop to go through inventory and position increases by 1
    int lowest_index = i; // current item is the lowest stock

    for (int j = i + 1; j < static_cast<int>(sorted_inventory.size()); j++) { // for loop to go through inventory after the current
      if (sorted_inventory[j].GetStock() < sorted_inventory[lowest_index].GetStock()) { // gets the stock item being checked
        lowest_index = j; // saves it as the newest lowest stock item
      }
    }

    MenuItem temporary = sorted_inventory[i]; // temporarily saves the current item
    sorted_inventory[i] = sorted_inventory[lowest_index]; // moves the position of the lowest item
    sorted_inventory[lowest_index] = temporary; // moves the saved item to next position
  }

  if (k > static_cast<int>(sorted_inventory.size())) { // checks if k is too large
    k = static_cast<int>(sorted_inventory.size()); // puts k in a limit to the number of usable items
  }

  std::vector<MenuItem> result;

  for (int i = 0; i < k; i++) { // loops through 
    result.push_back(sorted_inventory[i]); // adds the current item into the result
  }

  return result;
}
// function ten
std::vector<MenuItem> GetHighestPriceItems(
    const std::vector<MenuItem>& inventory, int k) { // gets the original inventory
  if (k <= 0) { // checks the number is if its invalid
    std::vector<MenuItem> empty_result; // creates a emtpy menuitem vector
    return empty_result;
  }

  std::vector<MenuItem> sorted_inventory = inventory; // copies the orginal inventory

  for (int i = 0; i < static_cast<int>(sorted_inventory.size()) - 1; i++) { // uses a for loop to go through it and stops before the last item
    int highest_index = i; // 

    for (int j = i + 1; j < static_cast<int>(sorted_inventory.size()); j++) { // for loop to search for the current position and does this until the vector ends and moves up by 1
      if (sorted_inventory[j].GetPrice() > sorted_inventory[highest_index].GetPrice()) { // if statement to get the price checked
        highest_index = j; // saves the position of the highest price item
      }
    }

    MenuItem temporary = sorted_inventory[i]; // temporalily saves the current item
    sorted_inventory[i] = sorted_inventory[highest_index]; // moves the item forward
    sorted_inventory[highest_index] = temporary; // moves the saved item to the next position
  }

  if (k > static_cast<int>(sorted_inventory.size())) { // checks if k is too large
    k = static_cast<int>(sorted_inventory.size()); // limits k
  }

  std::vector<MenuItem> result; // creates a vector for the highest price

  for (int i = 0; i < k; i++) { // loops through the k sorted
    result.push_back(sorted_inventory[i]); // adds the current item to the list
  }

  return result;
}
// function eleven
void ExportLowStockCSV(
    const std::vector<MenuItem>& inventory, // gets the inventory without it being changed
    const std::string& filename, // gets the name of the output file
    int stock_threshold) { 
  std::ofstream output_file(filename); // opens the output csv file

  if (!output_file.is_open()) { // checks if the file is opened correctly
    std::cerr << "Error: Could not create " // prints error message
              << filename 
              << std::endl;
    return;
  }

  for (int i = 0; i < static_cast<int>(inventory.size()); i++) { 
    if (inventory[i].GetStock() < stock_threshold) { // checks if the stock is below the limit
      output_file // writes the information to the output file
          << inventory[i].GetName() << "," // writes the name after the comma
          << inventory[i].GetCategory() << "," // writes the catgegory after the comma
          << std::fixed // displays the price
          << std::setprecision(2) // displays 2 digits after the decimal
          << inventory[i].GetPrice() << "," // writes the price after the comma
          << inventory[i].GetStock() // writes the stock amount
          << std::endl; // finishes
    }
  }

  output_file.close(); // closes the file
}

}  