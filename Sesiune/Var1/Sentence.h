#pragma once
#include "Processor.h"
#include <string>
#include <vector>

class Sentence {
private:
  std::vector<Processor*> procesators;
  std::string name;

public:
  Sentence(std::string sentence);
  void RunAll();
  void ListAll();
  void Run(std::string name);
  Sentence &operator+=(Processor* p);
};
