Restaurant 

Purpose: A program that manages and analyzes the restaurant's menu inventory. It goes through the information in the csv file, stores them in a vector, shows the inventory, gets filtered by price and category, searches for item names, able to apply discounts, and finds items that have the lowest stock and high prices, creating a lowstock csv file. 

Inputs:
-inventory.csv
-menu item name
-menu item price
-menu item stock amount
-category for filtering
-minimum price
-maximum price
-item name for searching
-discount
-number of requested using k
-amount of stock for the low stock report
-output csv filename
-string value turned into StringToInt()

Outputs:
-the full inventory
-items from chosen category
-items within chosen price range
-the result of item being searched by name
-updated menu using pointers
-items after discount
-3 items with lowest stock
-3 items with highest prices
-result of string converted into integer
-file report named low_stock_report.csv

Variables:
-Inventory, std::vector<MenuItem>, stores all the menu items
-name_, std::string, stores the menu item name
-category, std::string, stores the menu item category
-price_, double, stores the menu item price
-stock_, int, stores the menu item stock
-filename, std::string, stores the name of the input or output
-line, std::string, stores a line from the csv file
-name, std::string, stores the name read of the csv file
-category, std::string, stores the category of the csv file
-price_text, std::string, stores the price before it gets converted
-stock_text, std::string, stores the stock before it gets converted
-price, double, stores a converted menu price
-stock, int, stores a converted menu stock count
-number, int, makes the integer in StringToIt()
-sign, int, stores if the number is negative or positive
-index, int, looks for the current string position
-current_character, char, stores the current character
-minimum_price, double, stores the lowest limit price
-maximum_price, double, stores the highest limit price
-target_name, std::string, stores the item name thats searched for
-discount_decimal, double, stores the category discount
-old_price, double, stores the original price
-new_price, double, stores the discounted price
-k, int, stores the number of results requested
-sorted_inventory, std::vector<MenuItem>, stores a copy of the inventory
-lowest_index, int, stores the position of the lowest stock item
-highest_index, int, stores the position of the highest stock item
-temporary, MenuItem, temporarily stores an item
-result, std::vector<MenuItem>, stores the chosen sorted items
-stock_threshold, int, stores the low stock limit
-found_item, MenuItem*, stores a pointer to the found menu item
-orginal_stock, int, stores the original stock before changes

Key design choices:
-I used the menuitem class because each menu item has a name, category, price and stock count
-i made the class variable private so they can only be accessed by the setters and getters
-i used vector because it needed to store multiple menu items that could also change
-i used const reference so original inventory would not be changeable
-i used a pointer so the original item can be modified
-stringstream was used to take the values from the csv file and convert the price
-i used stringtoint function so it can be converted into integers
-i used a input and output file to create the low stock inventory report

Program steps:
-creating a empty vector of menu items
-open the csv file
-check if it opened correctly
-read the csv files line by line
-seperate the values by name, category, price and stock
-convert the price text to a number
-convert the stock text to a number
-create a menuitem object
-add the menuitem object into the inventory vector
-make it print the whole inventory 
-print all the items in dessert category
-print all items that's been filtered from 5 dollars to 10 dollars
-search for french fries by name
-return the pointer to the item if its found
-temporarily changing the items stock using the pointer
-bring back the original stock
-give a 10% discount to all the dessert items
-get a copy of the inventory and used the selection sort to find the 3 lowest stock
-get a copy of the inventory and used the selection sort to find the 3 highest stock
-wite the items stock threshold into the low stock report csv

Functions:
-StringToInt(), converts the string to a int
-LoadInventory(), goes into the csv file, reads each menu item line by line, converts these values and stores it into the inventory vector
-PrintInventory(), prints the menu items in the inventory
-FilterByCategory(), prints all the menu items thats been requested
-FilterByPriceRange(), prints all the menu items which prices are within range limit
-FindItemByName(), searches the menu item by name, it returns nullptr if its not found
-ApplyCategoryDiscount(), applies a discount to every menu item
-GetLowestStockItems(), used selection sort to return the number of items that has the lowest stock count
-GetHighestPriceItems(), used selection sort to return the number of items that has the highest prices
-ExportLowStockCSV(), creates a csv file that has the lowest stock amounts
-MenuItem Constructors, creates a menu item with provided values
-MenuItem Getters, returns the category, name, price and stock count 
-MenuItem Setters, updates the name, category, price and stock count

Sample input: values of csv file
-Plain Cheesecake,Dessert,8.50,12 
-Strawberry Cheesecake,Dessert,9.50,4 
-Black Coffee,Beverage,3.00,50 
-Pastrami Sandwich,Main,15.00,8
-French Fries,Side,5.00,0 
-Onion Rings,Side,6.00,2
-Steak Dinner,Main,25.00,5
-Iced Tea,Beverage,2.50,30
-Caesar Salad,Appetizer,7.00,15
-Garlic Bread,Side,4.50,20







Sample output::
-Plain Cheesecake		Dessert 		8.50 		12
-Strawberry Cheesecake	Dessert 		9.50 		4
-Black Coffee 			Beverage 		3.00 		50
-Pastrami Sandwich		Main			5.00		8
-French Fries 			Side 			5.00 		0
-Onion Rings			Side			6.00		2
-Steak Dinner 			Main 			25.00 		5
-Iced Tea			Beverage		2.50		30
-Caesar Salad			Appetizer		7.00		15
-Garlic Bread			Side			4.50		20


After, the program creates a low_stock_report.csv file.
