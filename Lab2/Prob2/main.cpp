#include "Compare.h"
#include "Student.h"
#include <cstdio>

int main() {
  Student s1, s2;
  s1.setName("John", 4);
  printf("%s\n", s1.getName());
  s1.setName("George", 6);
  s1.setMathGrade(10);
  s1.setEnglishGrade(5);
  s1.setHistoryGrade(6);
  s2.setEnglishGrade(9);
  s2.setMathGrade(7);
  s2.setHistoryGrade(6);

  printf("cmpavggrade: %d, cmpengl: %d, cmphist: %d, cmpmath: %d, cmpname: %d\n",
         cmpAvgGrade(&s1, &s2), cmpEnglishGrade(&s1, &s2),
         cmpHistoryGrade(&s1, &s2), cmpMathGrade(&s1, &s2), cmpName(&s1, &s2));
  return 0;
}
