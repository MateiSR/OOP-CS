#pragma once

int charToInt(char ch);
char intToChar(int d);

class Number {
  // add data members
  char *value = nullptr;
  int base = 10;
  int length = 0;
  friend int charToInt(char ch);
  friend char intToChar(int d);

public:
  Number(const char *value, int base); // where base is between 2 and 16
  ~Number();

  // add operators and copy/move constructor
  Number(const Number &other); // remove const
  Number(Number &&other);

  // operators
  friend Number operator+(const Number& num1, const Number& num2);
  friend Number operator-(const Number& num1, const Number& num2);
  char& operator[](int index);
  bool operator>(const Number& num);
  bool operator<(const Number& num);
  bool operator>=(const Number& num);
  bool operator<=(const Number& num);
  bool operator==(const Number& num);
  bool operator!=(const Number& num);
  Number& operator+=(const Number& num);
  Number& operator--();
  Number& operator--(int);
  // 
  void SwitchBase(int newBase);
  void Print();
  int GetDigitsCount(); // returns the number of digits for the current number
  int GetBase();        // returns the current base
  // void reallocHeap();
  // void addChar(char ch);
};
