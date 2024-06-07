#pragma once
#include "Article.h"

class VideoGame : public Article {
private:
  std::string platform;
  std::string name;
  int price;
  int quantity;

public:
  VideoGame(int price, int quantity, std::string platform, std::string name);
  std::string GetType() override;
  int GetQuantity() override;
  int GetPrice() override;
  void Print() override;
};
