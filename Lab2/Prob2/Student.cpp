#include "Student.h"

Student::Student() {
  this->grades.math = this->grades.english = this->grades.history = 0;
}

void Student::setName(char *name, int length) {
  for (int i = 0; i < length; i++)
    this->name[i] = *(name + i);
  this->name[length] = '\0';
}

char *Student::getName() { return this->name; }

void Student::setEnglishGrade(float grade) { this->grades.english = grade; }

void Student::setMathGrade(float grade) { this->grades.math = grade; }

void Student::setHistoryGrade(float grade) { this->grades.history = grade; }

float Student::getEnglishGrade() { return this->grades.english; };
float Student::getMathGrade() { return this->grades.math; };
float Student::getHistoryGrade() { return this->grades.history; };

float Student::getAvgGrade() {
  return (this->grades.math + this->grades.history +
          this->grades.english) /
         3.0;
}
