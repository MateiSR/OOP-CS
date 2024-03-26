#include "Number.h"
#include <cstdio>
#include <string.h>
#include <math.h>

/*
void Number::reallocHeap() {
  char *newVal;
  if (this->value == nullptr) {
    newVal = new char[this->charSize + 1];
    for (int i = 0; i < this->charSize; i++)
      newVal[i] = '\0';
  } else {
    newVal = new char[this->charSize * 2 + 1];
    for (int i = this->charSize; i < this->charSize * 2; i++)
      newVal[i] = '\0';
    for (int i = 0; i < this->charSize; i++)
      newVal[i] = this->value[i];
    this->charSize *= 2;
    delete[] this->value;
  }
  this->value = newVal;
}
*/

int Number::GetBase() { return this->base; }
int Number::GetDigitsCount() { return this->length; }
Number::Number(const char *value, int base) {
  int len = strlen(value);
  this->base = base;
  this->value = new char[len + 1];
  this->length = len;
  strcpy(this->value, value);
}

Number::~Number() { delete[] this->value; }

Number::Number(const Number &other) : base(other.base), length(other.length) {
  value = new char[this->length + 1];
  strcpy(value, other.value);
}

Number::Number(Number &&other)
    : value(other.value), base(other.base), length(other.length) {
  other.value = nullptr;
  other.length = 0;
}

void Number::Print() { printf("%s\n", this->value); }

int charToInt(char ch) {
  if (ch >= '0' && ch <= '9')
    return ch - '0';
  else if (ch >= 'A' && ch <= 'F')
    return ch - 'A' + 10;
  else if (ch >= 'a' && ch <= 'f')
    return ch - 'a' + 10;
  return 0;
}

char intToChar(int d) {
  if (d >= 0 && d <= 9) return d + '0';
  else if (d >= 10 && d <= 15) return 'A' + d - 10;
  return 'X';
}

void Number::SwitchBase(int newBase) {
  // assume base is between 2 and 16
  unsigned long long int valueB10 = 0;
  for (int i = 0; i < this->length; i++) {
    valueB10 = valueB10 * this->base + charToInt(this->value[i]);
  }
  // printf("valueb10: %d\n", valueB10);
  char *buf = new char[1024];
  int bufLength = 0;
  while (valueB10) {
    int digit = valueB10 % newBase;
    buf[bufLength++] = intToChar(digit);
    valueB10 /= newBase;
  }
  buf[bufLength] = '\0';
  // printf("buf: %s\n", buf);
  // 
  // reverse buf
  int start = 0, end = bufLength - 1;
  while (start < end) {
    char aux = buf[start];
    buf[start] = buf[end];
    buf[end] = aux;
    start++; end--;
  }

  // printf("bufnew: %s\n", buf);
  // alloc new space on heap of corresponding size
  char *newVal = new char[bufLength + 1];
  for (int i = 0; i <= bufLength; i++)
    newVal[i] = buf[i];
  

  delete[] buf; // delete the buffer
  delete[] this->value; // delete old value 
  this->base = newBase;
  this->length = bufLength;
  this->value = newVal;
}


