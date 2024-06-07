#include "VideoGame.h"
#include <iostream>

VideoGame::VideoGame(int price, int quantity, std::string platform,
                     std::string name)
    : price(price), quantity(quantity), platform(platform), name(name) {}
std::string VideoGame::GetType() { return "VideoGame"; }
int VideoGame::GetQuantity() { return quantity; }
int VideoGame::GetPrice() { return price; }
void VideoGame::Print() {
  std::cout << "VideoGame | "
            << " Platform: " << platform << " Name: " << name
            << " Price: " << price << " Quantity: " << quantity << std::endl;
}
