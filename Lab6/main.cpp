#include "Circuit.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include <stdio.h>

int main() {
  Circuit c;
  c.SetLength(100);
  c.SetWeather(Weather::Rainy);
  c.AddCar(new Dacia());
  c.AddCar(new Toyota());
  c.AddCar(new Mercedes());
  c.AddCar(new Ford());
  c.AddCar(new Mazda());
  c.AddCar(new Dacia("Dacia Sandero"));
  printf("Weather: Rainy (%d)\n", Weather::Rainy);
  c.Race();
  c.ShowFinalRanks(); // it will print the time each car needed to finish the
                      // circuit sorted from the fastest car to the slowest.
  c.ShowDNF();        // it is possible that some cars don't have enough
  printf("Weather: Sunny (%d)\n", Weather::Sunny);
  c.SetWeather(Weather::Sunny);
  c.Race();
  c.ShowFinalRanks();
  c.ShowDNF();
  printf("Weather: Snowy (%d)\n", Weather::Snowy); 
  Car *winningDacia = new Dacia("Dacia Castigatorului");
  winningDacia->setAvgSpeed(Weather::Snowy, 100);
  winningDacia->setFuelCapacity(500);
  winningDacia->setFuelConsumption(Weather::Snowy, 1);
  c.SetLength(125);
  c.AddCar(winningDacia);
  c.SetWeather(Weather::Snowy);
  c.Race();
  c.ShowFinalRanks();
  c.ShowDNF();
  return 0;
}
