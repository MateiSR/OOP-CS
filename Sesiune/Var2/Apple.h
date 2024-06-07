#pragma once
#include "Article.h"

class Apple : public Article {
private:
  int price;
  int quantity;
  std::string origin;

public:
  Apple(int price, int quantity, std::string origin);
  std::string GetType() override;
  int GetQuantity() override;
  int GetPrice() override;
  void Print() override;
};
