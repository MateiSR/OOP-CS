#pragma once
#include "Animal.h"

class Shark : public Animal {
public:
  std::string GetName() override;
  bool IsAFish() override;
  bool IsABird() override;
  bool IsAMammal() override;
};
