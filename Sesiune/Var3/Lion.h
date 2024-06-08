#pragma once
#include "Feline.h"

class Lion : public Feline {
public:
  std::string GetName() override;
  bool IsAFish() override;
  bool IsABird() override;
  bool IsAMammal() override;
  int GetSpeed() override;
};
