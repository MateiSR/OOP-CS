#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

template <typename T> class Compare {
public:
  bool operator()(const T &a, const T &b) {
    if (a.second != b.second)
      return a.second < b.second;
    return a.first > b.first;
  }
};

int main() {

  string separators = " ,?!.";

  ifstream fin("input.txt");

  if (!fin.is_open()) {
    cerr << "Error opening file!" << endl;
    return 1;
  }

  string inputBuffer;
  map<string, int> wordCount;

  while (getline(fin, inputBuffer)) {
    cout << "input buffer: " << inputBuffer << endl;
    string currentWord = "";
    for (char ch : inputBuffer) {
      // printf("%c | %d\n", ch, separators.find(ch));
      if (separators.find(ch) == -1) {
        currentWord += tolower(ch);
      } else if (!currentWord.empty()) {
        wordCount[currentWord]++;
        currentWord.clear();
      }
    }
    // if last ch isn't separator, but is end of sentence (for loop ended)
    if (!currentWord.empty()) {
      wordCount[currentWord]++;
      currentWord.clear();
    }
  }

  fin.close();

  cout << "--MAP--" << endl;
  for (auto it : wordCount) {
    cout << it.first << ": " << it.second << endl;
  }

  typedef pair<string, int> wordPair;

  priority_queue<wordPair, vector<wordPair>, Compare<wordPair>> wordQueue;

  for (auto &it : wordCount) {
    wordQueue.push(make_pair(it.first, it.second));
  }

  cout << "--PRIORITY QUEUE--" << endl;
  while (!wordQueue.empty()) {
    cout << wordQueue.top().first << " => " << wordQueue.top().second << endl;
    wordQueue.pop();
  }

  return 0;
}
