#include "Car.h"
#pragma once

class Mercedes : public Car {

public:
  Mercedes();
  int getFuelCapacity() override;
  int getFuelConsumption(Weather weather) override;
  int getAvgSpeed(Weather weather) override;
  char *getCarName() override;
  void setFuelCapacity(int capacity) override;
  void setAvgSpeed(Weather weather, int speed) override;
  void setFuelConsumption(Weather weather, int consumption) override;
};
