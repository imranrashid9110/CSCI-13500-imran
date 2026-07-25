#include <iostream>
#include <string>
#include <vector>

#include "MenuItem.h"
#include "Restaurant_Analytics.h"

int main() {
  std::vector<MenuItem> inventory; // This will hold the menu items loaded from the CSV file.

  // function two
  restaurant_util::LoadInventory(
      "inventory.csv",
      inventory);

  if (inventory.empty()) {
    std::cerr << "Inventory could not be loaded."
              << std::endl;
    return 1;
  }

  // function three
  std::cout << "Full Inventory" << std::endl;
  restaurant_util::PrintInventory(inventory);

  // function four
  std::cout << std::endl;
  std::cout << "Dessert Items" << std::endl;
  restaurant_util::FilterByCategory(
      inventory,
      "Dessert");

  // function five
  std::cout << std::endl;
  std::cout << "Items from $5.00 to $10.00"
            << std::endl;
  restaurant_util::FilterByPriceRange(
      inventory,
      5.00,
      10.00);

  // function six
  std::cout << std::endl;
  std::cout << "Searching for French Fries"
            << std::endl;

  MenuItem* found_item =
      restaurant_util::FindItemByName(
          inventory,
          "French Fries");

  if (found_item != nullptr) {
    std::cout << "Item found:" << std::endl;
    found_item->PrintItem();

    // saves the orginal stock
    int original_stock = found_item->GetStock();

    // can modify the object with pointer
    found_item->SetStock(10);

    std::cout << "Updated item:" << std::endl;
    found_item->PrintItem();

    // brings back the original value
    found_item->SetStock(original_stock);
  } else {
    std::cout << "Item not found."
              << std::endl;
  }

  // function seven
  restaurant_util::ApplyCategoryDiscount(
      inventory,
      "Dessert",
      0.10);

  std::cout << std::endl;
  std::cout << "Dessert Items After 10% Discount"
            << std::endl;

  restaurant_util::FilterByCategory(
      inventory,
      "Dessert");

  // function nine
  std::vector<MenuItem> lowest_stock =
      restaurant_util::GetLowestStockItems(
          inventory,
          3);

  std::cout << std::endl;
  std::cout << "Three Lowest Stock Items"
            << std::endl;

  restaurant_util::PrintInventory(
      lowest_stock);

  // function ten
  std::vector<MenuItem> highest_price =
      restaurant_util::GetHighestPriceItems(
          inventory,
          3);

  std::cout << std::endl;
  std::cout << "Three Highest Price Items"
            << std::endl;

  restaurant_util::PrintInventory(
      highest_price);

  // function eleven
  restaurant_util::ExportLowStockCSV(
      inventory,
      "low_stock_report.csv",
      10);

  std::cout << std::endl;
  std::cout << "low_stock_report.csv created."
            << std::endl;

  // Function One
  std::cout << std::endl;
  std::cout << "StringToInt(\"123\") = "
            << restaurant_util::StringToInt("123")
            << std::endl;

  return 0;
}