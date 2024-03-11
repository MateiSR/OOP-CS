#include "Math.h"
#include <cstring>
#include <stdarg.h>

int Math::Add(int x, int y) { return (x + y); }
int Math::Add(int x, int y, int z) { return (x + y + z); }
double Math::Add(double x, double y) { return (x + y); }
double Math::Add(double x, double y, double z) { return (x + y + z); }
int Math::Mul(int x, int y) { return (x * y); }
int Math::Mul(int x, int y, int z) { return (x * y * z); }
double Math::Mul(double x, double y) { return (x * y); }
double Math::Mul(double x, double y, double z) { return (x * y * z); }
int Math::Add(int count, ...) {
  va_list list;
  va_start(list, count);
  int sum = 0;
  for (int i = 0; i < count; i++) {
    sum += va_arg(list, int);
  }
  va_end(list);
  return sum;
}

char *Math::Add(const char *s1, const char *s2) {
  if (s1 == nullptr || s2 == nullptr)
    return nullptr;
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int lenTotal = len1 + len2 + 1;
  char *res = new char[lenTotal];
  strcpy(res, s1);
  strcat(res, s2);
  return res;
}
