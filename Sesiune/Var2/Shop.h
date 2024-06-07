#pragma once
#include <vector>
#include "Article.h"

class Shop {
private:
  std::vector<Article*> items;
public:
  Shop& Add(Article *item);
  int GetTotalPrice(); 
  int GetQuantity(std::string name);
  void List();
};
