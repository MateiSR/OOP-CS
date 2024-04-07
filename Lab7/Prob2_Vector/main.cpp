#include "Vector.h"
#include <initializer_list>
#include <stdio.h>

bool inverseSort(int a, int b) { return a < b; }

int main() {

  Vector<int> vecInt;
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 7, 1, 2, 10};

  printf("Sizeof(v): %lu\n", sizeof(v));
  for (int i = 0; i < sizeof(v) / sizeof(int); i++) {
    vecInt.push(v[i]);
  }
  printf("vecInt used size: %d, vecInt allocated size: %d\n", vecInt.getSize(),
         vecInt.getAllocSize());

  int testInt = 101;
  vecInt.insert(testInt, 10);
  const int *test = vecInt.get(10);
  if (test == 0)
    printf("Error: test - nullptr\n");
  else
    printf("Test value: %d\n", *test);

  int int0 = 10000;
  vecInt.set(int0, 1);

  vecInt.sort(nullptr);
  printf("Default sort:\n");
  for (int i = 0; i < vecInt.count(); i++) {
    printf("%d ", *vecInt.get(i));
  }
  printf("\n");

  vecInt.sort(inverseSort);
  printf("Callback function inverse sort:\n");
  for (int i = 0; i < vecInt.count(); i++) {
    printf("%d ", *vecInt.get(i));
  }
  printf("\n");

  printf("First index of int0 (%d): %d\n", int0, vecInt.firstIndexOf(int0));

  int intNOTINVEC = -10;
  printf("First index of intNOTINVEC (%d): %d\n", intNOTINVEC,
         vecInt.firstIndexOf(intNOTINVEC));

  for (auto indexToSearch : {1, 2, 3, 100, 101})
    printf("vec[%d] = %d;\n", indexToSearch, vecInt[indexToSearch]);

  return 0;
}
