#pragma once
class Student {
private:
  char name[256];
  struct {
    float history, math, english;
  } grades;

public:
  Student();
  void setName(char *name, int length);
  char *getName();
  float getAvgGrade();
  void setMathGrade(float grade);
  void setEnglishGrade(float grade);
  void setHistoryGrade(float grade);
  float getMathGrade();
  float getEnglishGrade();
  float getHistoryGrade();
};
