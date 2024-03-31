#include "Ford.h"
#include "Weather.h"

Ford::Ford() {
  this->name = new char[]{"Ford"};
  this->fuelCapacity = 100;
  this->fuelConsumption[Sunny] = 10;
  this->fuelConsumption[Rainy] = 15;
  this->fuelConsumption[Snowy] = 18;

  this->avgSpeed[Sunny] = 69;
  this->avgSpeed[Rainy] = 55;
  this->avgSpeed[Snowy] = 45;
}

int Ford::getFuelCapacity() { return this->fuelCapacity; };
int Ford::getFuelConsumption(Weather weather) {
  return this->fuelConsumption[weather];
};
int Ford::getAvgSpeed(Weather weather) { return this->avgSpeed[weather]; };
char *Ford::getCarName() { return this->name; };
void Ford::setFuelCapacity(int capacity) { this->fuelCapacity = capacity; };
void Ford::setAvgSpeed(Weather weather, int speed) {
  this->avgSpeed[weather] = speed;
};
void Ford::setFuelConsumption(Weather weather, int consumption) {
  this->fuelConsumption[weather] = consumption;
};
