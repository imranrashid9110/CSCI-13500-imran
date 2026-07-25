#ifndef MENUITEM_H_
#define MENUITEM_H_

#include <string>

class MenuItem {
 public:
  MenuItem();

  MenuItem(const std::string& name,
           const std::string& category,
           double price,
           int stock);

  std::string GetName() const;
  std::string GetCategory() const; 
  double GetPrice() const;
  int GetStock() const;

  void SetName(const std::string& name);
  void SetCategory(const std::string& category);
  void SetPrice(double price);
  void SetStock(int stock);

  void PrintItem() const;

 private:
  std::string name_;
  std::string category_;
  double price_;
  int stock_;
};

#endif  