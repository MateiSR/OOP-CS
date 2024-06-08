#include "Zoo.h"
#include "Animal.h"
#include "Feline.h"

std::vector<Animal *> Zoo::GetFishes() {
  std::vector<Animal *> fishes;
  for (auto a : animals) {
    if (a->IsAFish())
      fishes.push_back(a);
  }
  return fishes;
}

std::vector<Animal *> Zoo::GetBirds() {
  std::vector<Animal *> birds;
  for (auto a : animals) {
    if (a->IsABird())
      birds.push_back(a);
  }
  return birds;
}

std::vector<Animal *> Zoo::GetMammals() {
  std::vector<Animal *> mammals;
  for (auto a : animals) {
    if (a->IsAMammal())
      mammals.push_back(a);
  }
  return mammals;
}

std::vector<Feline *> Zoo::GetFelines() {
  std::vector<Feline *> felines;
  for (auto a : animals) {
    if (Feline *derived = dynamic_cast<Feline *>(a))
      felines.push_back(derived);
  }
  return felines;
}

void Zoo::operator+=(Animal *other) { animals.push_back(other); }

bool Zoo::operator()(std::string name) {
  for (auto a : animals) {
    if (a->GetName() == name)
      return true;
  }
  return false;
}

int Zoo::GetTotalAnimals() { return animals.size(); }
