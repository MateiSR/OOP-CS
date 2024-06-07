#include "Book.h"
#include <iostream>

Book::Book(int price, int quantity, std::string title, std::string author)
    : price(price), quantity(quantity), title(title), author(author) {}

std::string Book::GetType() { return "Book"; }
int Book::GetQuantity() { return quantity; }
int Book::GetPrice() { return price; }
void Book::Print() {
  std::cout << "Book | "
            << "Title: " << title << " Author: " << author
            << " Price: " << price << " Quantity: " << quantity << std::endl;
}
