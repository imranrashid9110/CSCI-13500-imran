#ifndef RESTAURANT_ANALYTICS_H_
#define RESTAURANT_ANALYTICS_H_

#include <string>
#include <vector>

#include "MenuItem.h"

namespace restaurant_util {

// function one
int StringToInt(const std::string& text);

// function two
void LoadInventory(const std::string& filename,
                   std::vector<MenuItem>& inventory);

// function three
void PrintInventory(const std::vector<MenuItem>& inventory);

// function four
void FilterByCategory(const std::vector<MenuItem>& inventory,
                      const std::string& category);

// function five
void FilterByPriceRange(const std::vector<MenuItem>& inventory,
                        double minimum_price,
                        double maximum_price);

// function six
MenuItem* FindItemByName(std::vector<MenuItem>& inventory,
                         const std::string& target_name);

// function seven
void ApplyCategoryDiscount(std::vector<MenuItem>& inventory,
                           const std::string& category,
                           double discount_decimal);

// function nine
std::vector<MenuItem> GetLowestStockItems(
    const std::vector<MenuItem>& inventory,
    int k);

// function ten
std::vector<MenuItem> GetHighestPriceItems(
    const std::vector<MenuItem>& inventory,
    int k);

// function eleven
void ExportLowStockCSV(
    const std::vector<MenuItem>& inventory,
    const std::string& filename,
    int stock_threshold);

}  

#endif 