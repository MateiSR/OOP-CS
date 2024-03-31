#include "Mercedes.h"
#include "Weather.h"

Mercedes::Mercedes() {
  this->name = new char[]{"Mercedes"};
  this->fuelCapacity = 100;
  this->fuelConsumption[Sunny] = 10;
  this->fuelConsumption[Rainy] = 15;
  this->fuelConsumption[Snowy] = 18;

  this->avgSpeed[Sunny] = 63;
  this->avgSpeed[Rainy] = 50;
  this->avgSpeed[Snowy] = 42;
}

int Mercedes::getFuelCapacity() { return this->fuelCapacity; };
int Mercedes::getFuelConsumption(Weather weather) {
  return this->fuelConsumption[weather];
};
int Mercedes::getAvgSpeed(Weather weather) { return this->avgSpeed[weather]; };
char *Mercedes::getCarName() { return this->name; };
void Mercedes::setFuelCapacity(int capacity) { this->fuelCapacity = capacity; };
void Mercedes::setAvgSpeed(Weather weather, int speed) {
  this->avgSpeed[weather] = speed;
};
void Mercedes::setFuelConsumption(Weather weather, int consumption) {
  this->fuelConsumption[weather] = consumption;
};
