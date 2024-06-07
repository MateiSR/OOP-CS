#include "Shop.h"
#include "Article.h"

Shop &Shop::Add(Article *item) {
  items.push_back(item);
  return *this;
}

int Shop::GetTotalPrice() {
  int totalPrice = 0;
  for (Article *item : items) {
    totalPrice += item->GetPrice() * item->GetQuantity();
  }
  return totalPrice;
}

int Shop::GetQuantity(std::string name) {
  int totalQuantity = 0;
  for (Article *item : items) {
    if (item->GetType() == name)
      totalQuantity += item->GetQuantity();
  }
  return totalQuantity;
}

void Shop::List() {
  for (Article *item : items)
    item->Print();
}
