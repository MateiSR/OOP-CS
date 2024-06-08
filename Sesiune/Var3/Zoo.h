#pragma once
#include "Animal.h"
#include "Feline.h"
#include <vector>

class Zoo {
private:
  std::vector<Animal *> animals;

public:
  std::vector<Animal *> GetFishes();
  std::vector<Animal *> GetBirds();
  std::vector<Animal *> GetMammals();
  std::vector<Feline *> GetFelines();
  int GetTotalAnimals();
  void operator+=(Animal *other);
  bool operator()(std::string name);
};
