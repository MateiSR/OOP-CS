#include "LongestWord.h"
#include <vector>

LongestWord::LongestWord(std::string name) : name(name) {}
std::string LongestWord::GetName() { return name; }
int LongestWord::Compute(std::string input) {
  std::string currWord = "";
  std::vector<std::string> words;
  for (char ch : input) {
    if (ch == ' ') {
      words.push_back(currWord);
      currWord.clear();
      continue;
    }
    currWord += ch;
  }
  words.push_back(currWord);
  // get max length
  unsigned int maxLen = 0;
  for (std::string word : words) {
    if (word.length() > maxLen) {
      maxLen = word.length();
    }
  }
  return maxLen;
}
