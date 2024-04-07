#include <cstdio>

float operator"" _Kelvin(unsigned long long temp) {
  return temp - 273.15;
}

float operator"" _Fahrenheit(unsigned long long temp) {
  return (temp - 32) / 1.8;
}

int main() {
  float a = 300_Kelvin;
  float b = 300_Fahrenheit;
  printf("a: %.3f, b: %.3f\n", a, b);
  return 0;
}
