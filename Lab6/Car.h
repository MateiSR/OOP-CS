#pragma once
#include "Weather.h"

class Car {
protected:
  int fuelCapacity, fuelConsumption[3], avgSpeed[3];
  char *name;

public:
  virtual ~Car() {
    if (this->name != nullptr)
      delete this->name;
  };
  virtual int getFuelCapacity() = 0;
  virtual int getFuelConsumption(Weather weather) = 0;
  virtual int getAvgSpeed(Weather weather) = 0;
  virtual void setFuelConsumption(Weather weather, int consumption) = 0;
  virtual void setAvgSpeed(Weather weather, int speed) = 0;
  virtual void setFuelCapacity(int capacity) = 0;
  virtual char *getCarName() { return this->name; };
};
