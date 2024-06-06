#pragma once
#include <string>
class Processor {
public:
  virtual std::string GetName() = 0;
  virtual int Compute(std::string input) = 0;
};
