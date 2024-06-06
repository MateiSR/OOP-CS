#include "CountLetters.h"

CountLetters::CountLetters(std::string name, std::function<bool(char)> pred)
    : name(name), pred(pred) {}
std::string CountLetters::GetName() { return name; }
int CountLetters::Compute(std::string input) {
  int count = 0;
  for (char ch : input) {
    if (pred(ch)) {
      count++;
    }
  }
  return count;
}
