#include "Dacia.h"
#include "Weather.h"
#include <cstring>

Dacia::Dacia() {
  this->name = new char[]{"Dacia"};
  this->fuelCapacity = 50;
  this->fuelConsumption[Sunny] = 10;
  this->fuelConsumption[Rainy] = 15;
  this->fuelConsumption[Snowy] = 18;

  this->avgSpeed[Sunny] = 29;
  this->avgSpeed[Rainy] = 25;
  this->avgSpeed[Snowy] = 15;
}

Dacia::Dacia(char *carName) {
  this->name = new char[strlen(carName) + 1];
  strcpy(this->name, carName);
  this->fuelCapacity = 50;
  this->fuelConsumption[Sunny] = 10;
  this->fuelConsumption[Rainy] = 15;
  this->fuelConsumption[Snowy] = 18;

  this->avgSpeed[Sunny] = 29;
  this->avgSpeed[Rainy] = 25;
  this->avgSpeed[Snowy] = 15;
}

int Dacia::getFuelCapacity() { return this->fuelCapacity; };
int Dacia::getFuelConsumption(Weather weather) {
  return this->fuelConsumption[weather];
};
int Dacia::getAvgSpeed(Weather weather) { return this->avgSpeed[weather]; };
char *Dacia::getCarName() { return this->name; };
void Dacia::setFuelCapacity(int capacity) { this->fuelCapacity = capacity; };
void Dacia::setAvgSpeed(Weather weather, int speed) {
  this->avgSpeed[weather] = speed;
};
void Dacia::setFuelConsumption(Weather weather, int consumption) {
  this->fuelConsumption[weather] = consumption;
};
