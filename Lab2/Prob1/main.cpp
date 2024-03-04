#include "NumberList.h"
#include <stdio.h>

int main() {
  NumberList list;
  list.Add(10);
  list.Add(5);
  list.Add(1);

  list.Print();
  printf("\n");
  list.Sort();
  list.Print();
  printf("\n");
  return 0;
}
