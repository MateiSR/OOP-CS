#include <stdio.h>
#include "Canvas.h"

int main() {

  Canvas c1(6, 6);
  c1.DrawRect(1, 1, 4, 5, '*');
  c1.Print();

  c1.Clear();
  c1.FillRect(1,1,5,6, '0');
  c1.Print();

  Canvas c2(15, 15);
  c2.DrawLine(0,0,10,10, '-');
  c2.Print();

  c2.DrawCircle(5, 5, 5, 'A');
  c2.Print();

  c2.Clear();
  c2.FillCircle(5,5,4, 'B');
  c2.SetPoint(6,6,'*');
  c2.Print();

  return 0;
}
