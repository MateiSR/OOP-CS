#include "Cow.h"
#include "Eagle.h"
#include "Lion.h"
#include "Shark.h"
#include "Tiger.h"
#include "Zoo.h"
#include <iostream>

int main() {

  Zoo z;
  z += new Shark();
  z += new Eagle();
  z += new Tiger();
  z += new Lion();
  z += new Cow();

  std::cout << "Zoo animals: " << z.GetTotalAnimals() << "\n";
  for (auto a : z.GetFishes())
    std::cout << "Fish: " << a->GetName() << "\n";
  for (auto a : z.GetBirds())
    std::cout << "Bird: " << a->GetName() << "\n";
  for (auto a : z.GetMammals())
    std::cout << "Mammal: " << a->GetName() << "\n";
  for (auto a : z.GetFelines())
    std::cout << "Feline: " << a->GetName() << "Speed: " << a->GetSpeed()
              << "\n";

  std::cout << "Zoo contains a tiger " << std::boolalpha << z("Tiger") << "\n";
  std::cout << "Zoo contains a monkey " << std::boolalpha << z("Monkey")
            << "\n";

  return 0;
}
