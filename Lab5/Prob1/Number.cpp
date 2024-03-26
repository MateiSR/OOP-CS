#include "Number.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>

int Number::GetBase() { return this->base; }
int Number::GetDigitsCount() { return this->length; }
Number::Number(const char *value, int base) {
  int len = strlen(value);
  this->base = base;
  this->value = new char[len + 1];
  this->length = len;
  strcpy(this->value, value);
}

Number::Number(int num) : base(10) {
  int copyNum = num, _len = 0;
  do {
    _len++;
    copyNum /= 10;
  } while (copyNum != 0);
  char *newVal = new char[_len + 1];
  sprintf(newVal, "%d", num);
  this->value = newVal;
  this->length = _len;
}

Number::Number(const char *value) : base(10) {
  this->length = strlen(value);
  char *newVal = new char[this->length + 1];
  strcpy(newVal, value);
  this->value = newVal;
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
  if (d >= 0 && d <= 9)
    return d + '0';
  else if (d >= 10 && d <= 15)
    return 'A' + d - 10;
  return 'X';
}

void Number::SwitchBase(int newBase) {
  if (this->base == newBase)
    return;
  // assume base is between 2 and 16
  unsigned long long int valueB10 = 0;
  for (int i = 0; i < this->length; i++) {
    valueB10 = valueB10 * this->base + charToInt(this->value[i]);
  }
  // printf("original value, base: %d\n", this->base);
  // this->Print();
  // printf("valueb10: %llu\n", valueB10);
  char *buf = new char[this->MAXBUFSIZE];
  int bufLength = 0;
  while (valueB10) {
    int digit = valueB10 % newBase;
    // printf("curr digit: %d\n", digit);
    buf[bufLength++] = intToChar(digit);
    valueB10 /= newBase;
  }
  // printf("newbase: %d\n", newBase);
  buf[bufLength] = '\0';
  // printf("value of buf:%s\n", buf);
  // printf("buf: %s\n", buf);
  // reverse buf
  int start = 0, end = bufLength - 1;
  while (start < end) {
    char aux = buf[start];
    buf[start] = buf[end];
    buf[end] = aux;
    start++;
    end--;
  }

  // printf("bufnew: %s\n", buf);
  // alloc new space on heap of corresponding size
  char *newVal = new char[bufLength + 1];
  for (int i = 0; i <= bufLength; i++)
    newVal[i] = buf[i];

  delete[] buf;         // delete the buffer
  delete[] this->value; // delete old value
  this->base = newBase;
  this->length = bufLength;
  this->value = newVal;
}

Number &Number::operator=(const Number &num) {
  if (this != &num) {
    base = num.base;
    if (this->value != nullptr)
      delete[] this->value;
    char *newVal = new char[num.length + 1];
    strcpy(newVal, num.value);
    this->value = newVal;
    this->length = num.length;
  }
  return *this;
}

char &Number::operator[](int index) { return this->value[index]; }

Number operator+(const Number &num1, const Number &num2) {
  Number num1c(num1.value, num1.base);
  Number num2c(num2.value, num2.base);
  unsigned int resultBase = num1.base > num2.base ? num1.base : num2.base;
  num1c.SwitchBase(10);
  num2c.SwitchBase(10);
  // printf("num1c:\n");
  // num1c.Print();
  // printf("num2c:\n");
  // num2c.Print();
  unsigned int numRes = atoi(num1c.value) + atoi(num2c.value);
  int _len = 0;
  unsigned int resCopy = numRes;
  do {
    _len++;
    resCopy /= 10;
  } while (resCopy != 0);
  char *additionRes = new char[_len + 1];
  sprintf(additionRes, "%d", numRes);
  Number res(additionRes, 10);
  // printf("---");
  // res.Print();
  res.SwitchBase(resultBase);
  return res;
};

Number operator-(const Number &num1, const Number &num2) {
  Number num1c(num1.value, num1.base);
  Number num2c(num2.value, num2.base);
  unsigned int resultBase = num1.base > num2.base ? num1.base : num2.base;
  num1c.SwitchBase(10);
  num2c.SwitchBase(10);
  // printf("num1c:\n");
  // num1c.Print();
  // printf("num2c:\n");
  // num2c.Print();
  unsigned int numRes = atoi(num1c.value) - atoi(num2c.value);
  int _len = 0;
  unsigned int resCopy = numRes;
  do {
    _len++;
    resCopy /= 10;
  } while (resCopy != 0);
  char *subtractionRes = new char[_len + 1];
  sprintf(subtractionRes, "%d", numRes);
  Number res(subtractionRes, 10);
  // printf("---");
  // res.Print();
  res.SwitchBase(resultBase);
  return res;
};

bool Number::operator>(const Number &num) {
  Number thisB10 = *this;
  thisB10.SwitchBase(10);
  Number cmpB10 = num;
  cmpB10.SwitchBase(10);
  return atoi(thisB10.value) > atoi(cmpB10.value);
}

Number &Number::operator+=(const Number &num) {
  const int resultBase = this->base > num.base ? this->base : num.base;
  Number numCopy = num;
  this->SwitchBase(10);
  numCopy.SwitchBase(10);
  unsigned int numRes = atoi(numCopy.value) + atoi(this->value);
  int _len = 0;
  unsigned int resCopy = numRes;
  do {
    _len++;
    resCopy /= 10;
  } while (resCopy != 0);
  char *additionRes = new char[_len + 1];
  if (this->value != nullptr)
    delete[] this->value;
  this->value = additionRes;
  this->length = _len;
  this->base = 10;
  this->SwitchBase(resultBase);
  return *this;
}

Number &Number::operator--() { // prefix
  char *oldVal = this->value;
  if (this->value != nullptr)
    delete[] this->value;
  if (this->length <= 1) {
    char *newVal = new char[1];
    newVal[0] = 0;
    this->value = newVal;
    this->length = 0;
  } else {
    char *newVal = new char[this->length];
    for (int i = 1; i < this->length; i++)
      newVal[i] = oldVal[i - 1];
    newVal[--this->length] = 0;
  }
  return *this;
}

Number &Number::operator--(int) { // postfix
  char *oldVal = this->value;
  if (this->value != nullptr)
    delete[] this->value;
  char *newVal = new char[this->length];
  for (int i = 0; i < this->length - 1; i++)
    newVal[i] = oldVal[i];
  newVal[--this->length] = 0;
  this->value = newVal;
  return *this;
}
