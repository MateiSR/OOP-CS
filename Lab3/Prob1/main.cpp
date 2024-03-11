#include "Math.h"
#include <stdio.h>

int main() {

  printf("test: %d\n", Math::Add(5, 1, 2, 3, 4, 5));

  printf("Add char*: %s\n", Math::Add("123", "345"));

  return 0;
}
