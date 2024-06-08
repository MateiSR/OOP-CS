#pragma once
#include "Feline.h"

class Tiger : public Feline {
public:
  std::string GetName() override;
  bool IsAFish() override;
  bool IsABird() override;
  bool IsAMammal() override;
  int GetSpeed() override;
};
