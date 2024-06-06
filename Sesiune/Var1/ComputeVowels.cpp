#include "ComputeVowels.h"
ComputeVowels::ComputeVowels(std::string name) : name(name) {}
std::string ComputeVowels::GetName() { return name; }
int ComputeVowels::Compute(std::string input) {
  int count = 0;
  for (char ch : input) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      count++;
    }
  }
  return count;
}
