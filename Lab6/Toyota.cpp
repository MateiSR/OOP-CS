#include "Toyota.h"
#include "Weather.h"

Toyota::Toyota() {
  this->name = new char[]{"Toyota"};
  this->fuelCapacity = 100;
  this->fuelConsumption[Sunny] = 12;
  this->fuelConsumption[Rainy] = 17;
  this->fuelConsumption[Snowy] = 20;

  this->avgSpeed[Sunny] = 80;
  this->avgSpeed[Rainy] = 65;
  this->avgSpeed[Snowy] = 50;
}

int Toyota::getFuelCapacity() { return this->fuelCapacity; };
int Toyota::getFuelConsumption(Weather weather) {
  return this->fuelConsumption[weather];
};
int Toyota::getAvgSpeed(Weather weather) { return this->avgSpeed[weather]; };
char *Toyota::getCarName() { return this->name; };
void Toyota::setFuelCapacity(int capacity) { this->fuelCapacity = capacity; };
void Toyota::setAvgSpeed(Weather weather, int speed) {
  this->avgSpeed[weather] = speed;
};
void Toyota::setFuelConsumption(Weather weather, int consumption) {
  this->fuelConsumption[weather] = consumption;
};
