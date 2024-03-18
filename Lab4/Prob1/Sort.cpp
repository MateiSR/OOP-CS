#include "Sort.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <initializer_list>

void Sort::Add(int x) {
  int *newList = new int[this->size + 1];
  for (int i = 0; i < this->size; i++)
    newList[i] = this->list[i];
  newList[this->size] = x;
  /*printf("newlist updated:\n");
  for (int i = 0; i < this->size + 1; i++)
    printf("%d ", newList[i]);
  printf("--end add\n");*/
  if (this->list != nullptr)
    delete[] this->list;
  this->list = newList;
  this->size++;
}

void Sort::Remove(int index) {
  if (index < 0 || index >= size)
    return;

  int *newList = new int[size - 1];
  for (int i = 0; i < index; ++i) {
    newList[i] = list[i];
  }
  for (int i = index + 1; i < size; ++i) {
    newList[i - 1] = list[i];
  }

  if (this->list != nullptr)
    delete[] this->list;
  this->list = newList;
  size--;
}

Sort::~Sort() {
  if (this->list)
    delete[] this->list;
}

Sort::Sort(){};

// constructor 1:
Sort::Sort(int count, int min, int max) {
  srand(time(NULL));
  for (int i = 0; i < count; i++) {
    Add(rand() % (max - min + 1) + max);
  }
}

// constructor 2:
Sort::Sort(std::initializer_list<int> initList) {
  for (int x : initList)
    Add(x);
}

// constructor 3:
Sort::Sort(int *v, int count) {
  for (int i = 0; i < count; i++)
    Add(v[i]);
}

// constructor 4:
Sort::Sort(int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    int x = va_arg(args, int);
    Add(x);
  }
  va_end(args);
}

// constructor 5:
Sort::Sort(char *s) {
  char *p = strtok(s, ",");
  while (p) {
    int x = atoi(p);
    Add(x);
    p = strtok(NULL, ",");
  }
}

int Sort::GetElementsCount() { return this->size; }

int Sort::GetElementFromIndex(int index) {
  if (index < 0 || index >= size)
    return -1;
  return this->list[index];
}

void Sort::InsertSort(bool ascendent) {
  for (int i = 1; i < this->size; i++) {
    int x = this->list[i];
    int p = i - 1;
    while (p >= 0 && (ascendent ? this->list[p] > x : this->list[p] < x))
      this->list[p + 1] = this->list[p], p--;
    this->list[p + 1] = x;
  }
}

void Sort::QuickSort(bool ascendent, int left, int right) {
  if (right == -1)
    right = this->size - 1;
  if (left < right) {
    // pivotul este inițial this->list[left]
    int m = (left + right) / 2;
    int aux = this->list[left];
    this->list[left] = this->list[m];
    this->list[m] = aux;
    int i = left, j = right, d = 0;
    while (i < j) {
      if (ascendent ? (this->list[i] > this->list[j])
                    : (this->list[i] < this->list[j])) {
        aux = this->list[i];
        this->list[i] = this->list[j];
        this->list[j] = aux;
        d = 1 - d;
      }
      i += d;
      j -= 1 - d;
    }
    QuickSort(ascendent, left, i - 1);
    QuickSort(ascendent, i + 1, right);
  }
}

void Sort::BubbleSort(bool ascendent) {
  bool sortat;
  do {
    sortat = true;
    for (int i = 0; i < this->size - 1; i++) {
      if (ascendent ? (this->list[i] > this->list[i + 1])
                    : (this->list[i] < this->list[i + 1])) {
        int aux = this->list[i];
        this->list[i] = this->list[i + 1];
        this->list[i + 1] = aux;
        sortat = false;
      }
    }
  } while (!sortat);
}

void Sort::Print() {
  for (int i = 0; i < this->size; i++)
    printf("%d ", this->list[i]);
  printf("\n");
}
