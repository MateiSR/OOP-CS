#pragma once

#include "Car.h"
#include "Weather.h"
// #define CAR_LIMIT 20

void sortCars(Car **cars);

class Circuit {

  float RaceCar(int id);
  int length;
  int carCount;
  int vecSize;
  Weather currWeather;
  Car **cars;
  float *finishTime;
  // Car *cars[CAR_LIMIT];
  // float finishTime[CAR_LIMIT];
  void SortCars();

public:
  Circuit();
  ~Circuit();
  void SetLength(int length);
  void SetWeather(Weather weather);
  void Race();
  void ShowFinalRanks();
  void ShowDNF();
  void AddCar(Car *car);
};
