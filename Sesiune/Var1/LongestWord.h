#pragma once
#include "Processor.h"
#include <string>

class LongestWord : public Processor {
private:
  std::string name;

public:
  LongestWord(std::string name);
  std::string GetName() override;
  int Compute(std::string input) override;
};
