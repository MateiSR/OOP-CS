#include "Map.h"
#include <cstdio>

int main() {
  Map<int, const char *> m;
  m[10] = "C++";
  m[20] = "test";
  m[30] = "Poo";
  for (auto [key, value, index] : m) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }
  m[20] = "result";
  m.set(30, "OOP!");
  for (auto [key, value, index] : m) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }

  printf("Count=%d\n", m.count());

  const char *testVal;
  if (m.get(20, testVal)) {
    printf("Value=%s\n", testVal);
  }

  m.del(20);
  printf("Count(after del)=%d\n", m.count());
  printf("--map1 after del--\n");
  for (auto [key, value, index] : m) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }
  Map<int, const char *> m2;
  m2[10] = "C++";
  // print map 2
  printf("--map2--\n");
  for (auto [key, value, index] : m2) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }
  printf("Includes=%d\n", m.includes(m2));

  m2[15] = "OOP!";
  // print map 2
  printf("--map2 after insert (should return includes=0)--\n");
  for (auto [key, value, index] : m2) {
    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
  }
  printf("Includes=%d\n", m.includes(m2));

  m.clear();
  printf("Count(after clear)=%d\n", m.count());

  return 0;
}
