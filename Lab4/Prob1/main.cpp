#include "Sort.h"
#include <stdio.h>

int main() {

  // debug
  Sort l;
  l.Add(1);
  l.Add(3);
  l.Add(2);
  l.Print();
  l.QuickSort();
  l.Print();
  l.Remove(1);
  l.Print();

  // constructor 1
  printf("---Constructor1---\n");
  Sort l1(5, 1, 7);
  l1.Print();
  l1.InsertSort(true);
  l1.Print();

  // constructor 2
  printf("---Constructor2---\n");
  Sort l2{1,2,3,5,6,8,9};
  l2.Print();
  l2.QuickSort();
  l2.Print();


  // constructor 3
  printf("---Constructor3---\n");
  int v[] = {1, 4, 6};
  Sort l3(v, 3);
  l3.Print();

  // constructor 4
  printf("---Constructor4---\n");
  Sort l4(5, 10, 30, 20, 70, 50);
  l4.Print();
  l4.BubbleSort();
  l4.Print();

  // constructor 5
  printf("---Constructor5---\n");
  char in[] = "10,1,3,4,7";
  Sort l5(in);
  l5.Print();
  l5.BubbleSort();
  l5.Print();

  return 0;
}
