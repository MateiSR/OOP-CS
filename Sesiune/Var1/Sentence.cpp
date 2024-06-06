#include "Sentence.h"
#include <iostream>

Sentence::Sentence(std::string sentence) : name(sentence) {}
void Sentence::ListAll() {
  for (unsigned int i = 0; i < procesators.size(); i++) {
    std::cout << "Name: " << procesators[i]->GetName() << '\n';
  }
}
void Sentence::RunAll() {

  for (unsigned int i = 0; i < procesators.size(); i++) {
    std::cout << "Name: " << procesators[i]->GetName() << " => "
              << procesators[i]->Compute(name) << '\n';
  }
}

void Sentence::Run(std::string name) {
  bool foundProc = false;
  for (unsigned int i = 0; i < procesators.size(); i++) {
    if (procesators[i]->GetName() == name) {
      std::cout << procesators[i]->Compute(this->name) << '\n';
      foundProc = true;
      continue;
    }
  }
  if (!foundProc)
    std::cout << "Processor not found!\n";
}

Sentence &Sentence::operator+=(Processor *p) {
  procesators.push_back(p);
  return *this;
}
