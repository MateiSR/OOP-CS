#pragma once
#include "Processor.h"
#include <string>

class ComputeVowels : public Processor {
private:
  std::string name;

public:
  ComputeVowels(std::string name);
  std::string GetName() override;
  int Compute(std::string input) override;

};
