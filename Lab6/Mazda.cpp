#include "Mazda.h"
#include "Weather.h"

Mazda::Mazda() {
  this->name = new char[]{"Mazda"};
  this->fuelCapacity = 100;
  this->fuelConsumption[Sunny] = 10;
  this->fuelConsumption[Rainy] = 15;
  this->fuelConsumption[Snowy] = 18;

  this->avgSpeed[Sunny] = 49;
  this->avgSpeed[Rainy] = 55;
  this->avgSpeed[Snowy] = 45;
}

int Mazda::getFuelCapacity() { return this->fuelCapacity; };
int Mazda::getFuelConsumption(Weather weather) {
  return this->fuelConsumption[weather];
};
int Mazda::getAvgSpeed(Weather weather) { return this->avgSpeed[weather]; };
char *Mazda::getCarName() { return this->name; };
void Mazda::setFuelCapacity(int capacity) { this->fuelCapacity = capacity; };
void Mazda::setAvgSpeed(Weather weather, int speed) {
  this->avgSpeed[weather] = speed;
};
void Mazda::setFuelConsumption(Weather weather, int consumption) {
  this->fuelConsumption[weather] = consumption;
};
