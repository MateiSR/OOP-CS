#include "ComputeVowels.h"
#include "CountLetters.h"
#include "LongestWord.h"
#include "Sentence.h"
#include <iostream>

int main() {
  Sentence s("Second POO test");
  (s += new ComputeVowels("Voc")) +=
      new CountLetters("CountE", [](char ch) { return ch == 'e'; });
  s += new LongestWord("long");
  s.ListAll();
  std::cout << "======" << std::endl;
  s.RunAll();
  std::cout << "======" << std::endl;
  s.Run("CountE");
  return 0;
}
