#pragma once

#include <initializer_list>
class Sort {
  // add data members
private:
  int *list = nullptr;
  int size = 0;

public:
  //int *list;
  void Add(int x);
  void Remove(int index);
  // add constuctors
  Sort();
  Sort(int count, int min, int max);         // c1
  Sort(std::initializer_list<int> initList); // c2?
  Sort(int *v, int count);                   // c3
  Sort(int count, ...);                      // c4
  Sort(char *s);                             // c5
  void InsertSort(bool ascendent = false);
  void QuickSort(bool ascendent = false, int left = 0, int right = -1);
  void BubbleSort(bool ascendent = false);
  void Print();
  int GetElementsCount();
  int GetElementFromIndex(int index);
  ~Sort();
};
