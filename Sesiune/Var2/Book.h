#pragma once
#include "Article.h"

class Book : public Article {
private:
  std::string title;
  std::string author;
  int price;
  int quantity;

public:
  Book(int price, int quantity, std::string title, std::string author);
  std::string GetType() override;
  int GetQuantity() override;
  int GetPrice() override;
  void Print() override;
};
