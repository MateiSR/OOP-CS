#include "Compare.h"
#include <cstring>

int cmpName(Student *s1, Student *s2) {
  char *s1Name = s1->getName();
  char *s2Name = s2->getName();
  for (int i = 0; i < strlen(s1Name); i++) {
    int diff = (int)s1Name[i] - (int)s2Name[i];
    if (diff == 0)
      continue;
    else if (diff > 0)
      return 1;
    else if (diff < 0)
      return -1;
  }
  return 0;
}

int cmpMathGrade(Student *s1, Student *s2) {
  float s1Grade = s1->getMathGrade(), s2Grade = s2->getMathGrade();
  if (s1Grade == s2Grade)
    return 0;
  else if (s1Grade > s2Grade)
    return 1;
  return -1;
}

int cmpEnglishGrade(Student *s1, Student *s2) {
  float s1Grade = s1->getEnglishGrade(), s2Grade = s2->getEnglishGrade();
  if (s1Grade == s2Grade)
    return 0;
  else if (s1Grade > s2Grade)
    return 1;
  return -1;
}

int cmpHistoryGrade(Student *s1, Student *s2) {
  float s1Grade = s1->getHistoryGrade(), s2Grade = s2->getHistoryGrade();
  if (s1Grade == s2Grade)
    return 0;
  else if (s1Grade > s2Grade)
    return 1;
  return -1;
}

int cmpAvgGrade(Student *s1, Student *s2) {
  float s1Avg = s1->getAvgGrade(), s2Avg = s2->getAvgGrade();
  if (s1Avg == s2Avg)
    return 0;
  else if (s1Avg > s2Avg)
    return 1;
  return -1;
}
