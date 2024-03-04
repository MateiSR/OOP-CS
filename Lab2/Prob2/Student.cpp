#include "Student.h"

Student::Student() {
  Student::grades.math = Student::grades.english = Student::grades.history = 0;
}

void Student::setName(char *name, int length) {
  for (int i = 0; i < length; i++)
    Student::name[i] = *(name + i);
  Student::name[length] = '\0';
}

char *Student::getName() { return Student::name; }

void Student::setEnglishGrade(float grade) { Student::grades.english = grade; }

void Student::setMathGrade(float grade) { Student::grades.math = grade; }

void Student::setHistoryGrade(float grade) { Student::grades.history = grade; }

float Student::getEnglishGrade() { return Student::grades.english; };
float Student::getMathGrade() { return Student::grades.math; };
float Student::getHistoryGrade() { return Student::grades.history; };

float Student::getAvgGrade() {
  return (Student::grades.math + Student::grades.history +
          Student::grades.english) /
         3.0;
}
