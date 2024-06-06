#pragma once
#include "Processor.h"
#include <functional>
#include <string>

class CountLetters : public Processor {
private:
  std::string name;
  std::function<bool(char)> pred;

public:
  std::string GetName() override;
  CountLetters(std::string name, std::function<bool(char)> pred);
  int Compute(std::string input) override;
};
