#include "Circuit.h"
#include <cstdio>

Circuit::Circuit() {
  this->length = 100;
  this->currWeather = Sunny;
  this->carCount = this->vecSize = 0;
}

Circuit::~Circuit() {
  if (this->vecSize == 0)
    return;
  delete[] this->cars;
  delete[] this->finishTime;
}

void Circuit::SetLength(int length) { this->length = length; }

void Circuit::SetWeather(Weather weather) { this->currWeather = weather; }

void Circuit::AddCar(Car *car) {
  printf("Adding car: %s, carCount: %d, vecSize: %d\n", car->getCarName(),
         this->carCount, this->vecSize);
  if (this->carCount == 0) {
    this->carCount = 1;
    this->vecSize = 1;
    this->cars = new Car *[1];
    this->finishTime = new float[1];
    this->cars[0] = car;
    this->finishTime[0] = 0;
    printf(">> Adding first car\n");
  } else if (this->carCount >= this->vecSize) {
    printf(">> Increasing heap size\n");
    // increase vector size
    Car **newCarVec = new Car *[this->vecSize * 2];
    float *newFinishVec = new float[this->vecSize * 2];
    for (int i = 0; i < this->vecSize; i++) {
      newCarVec[i] = this->cars[i];
      newFinishVec[i] = this->finishTime[i];
    }
    delete[] this->cars;
    delete[] this->finishTime;
    this->cars = newCarVec;
    this->finishTime = newFinishVec;
    // add cars
    this->cars[this->carCount] = car;
    this->finishTime[this->carCount] = 0;
    this->carCount++;
    this->vecSize *= 2;
  } else {
    printf(">> Adding car to pre-allocated array\n");
    this->cars[carCount] = car;
    this->finishTime[carCount] = 0;
    this->carCount++;
  }
}

float Circuit::RaceCar(int id) {
  if (id >= this->carCount)
    return -1.0;
  float driveHrs =
      (float)this->cars[id]->getFuelCapacity() * 1.0 /
      (float)this->cars[id]->getFuelConsumption(this->currWeather) * 1.0;
  float distanceDriven =
      driveHrs * (float)this->cars[id]->getAvgSpeed(this->currWeather) * 1.0;
  if (distanceDriven < this->length)
    return -1.0;
  return (driveHrs * length) / distanceDriven;
}

void Circuit::Race() {
  for (int i = 0; i < this->carCount; i++) {
    this->finishTime[i] = this->RaceCar(i);
  }
  this->SortCars();
}

void Circuit::SortCars() {
  printf("Sorting cars..\n");
  for (int i = 0; i < this->carCount - 1; i++)
    for (int j = i + 1; j < this->carCount; j++) {
      printf("cars[%d] = %.3f > cars[%d] = %.3f: %d ||| ", i,
             this->finishTime[i], j, this->finishTime[j],
             this->finishTime[i] > this->finishTime[j]);
      if (this->finishTime[i] > this->finishTime[j] &&
          this->finishTime[i] > 0 && this->finishTime[j] > 0) {
        printf("Swapping car[%d] (%s) with car[%d] (%s) | ", i,
               this->cars[i]->getCarName(), j, this->cars[j]->getCarName());
        Car *carAtIndexI = this->cars[i];
        this->cars[i] = this->cars[j];
        this->cars[j] = carAtIndexI;
        float finishTimeAtIndexI = this->finishTime[i];
        this->finishTime[i] = this->finishTime[j];
        this->finishTime[j] = finishTimeAtIndexI;
      }
    }
  printf("\n");
}

void Circuit::ShowFinalRanks() {
  unsigned int totalCars = 0;
  for (int i = 0; i < this->carCount; i++)
    if (this->finishTime[i] != -1.0)
      printf("#%d - %s: %.2f hrs\n", ++totalCars, this->cars[i]->getCarName(),
             this->finishTime[i]);
}

void Circuit::ShowDNF() {
  for (int i = 0; i < this->carCount; i++)
    if (this->finishTime[i] == -1.0)
      printf("DNF - %s\n", this->cars[i]->getCarName());
}
