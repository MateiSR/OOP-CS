#pragma once
#include "Animal.h"

class Eagle : public Animal {
public:
  std::string GetName() override;
  bool IsAFish() override;
  bool IsABird() override;
  bool IsAMammal() override;
};
