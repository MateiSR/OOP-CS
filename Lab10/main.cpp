#include "Array.hpp"
#include <exception>
#include <iostream>

using namespace std;

class IntComparator : public Comparator {
public:
  int CompareElements(void *elem1, void *elem2) override {
    int intElem1 = *(int *)elem1;
    int intElem2 = *(int *)elem2;
    if (intElem1 == intElem2)
      return 0;
    return (intElem1 > intElem2) ? 1 : -1;
  }
};

int intComparer(const int &elem1, const int &elem2) {
  if (elem1 == elem2)
    return 0;
  return (elem1 > elem2) ? 1 : -1;
}

int main() {
  IntComparator intComp;
  Array<int> array1(2);

  array1 += 2;
  array1 += 4;
  array1 += 3;
  array1 += 5;

  array1.Print();

  array1.Sort();
  array1.Print();

  array1.Clear();
  array1 += 2;
  array1 += 4;
  array1 += 3;
  array1 += 5;

  array1.Sort(&intComparer);
  array1.Print();

  array1.Clear();
  array1 += 2;
  array1 += 4;
  array1 += 3;
  array1 += 5;

  array1.Sort(&intComp);
  array1.Print();

  array1.Insert(1, 10);
  array1.Print();

  Array<int> array2(array1);
  array2.Delete(2);
  array2.Print();

  cout << array2.Find(10) << endl;
  cout << array2.Find(2, &intComparer) << endl;

  array2.Sort();
  array2.Print();

  cout << array2.BinarySearch(10) << endl;
  cout << array2.BinarySearch(2, &intComparer) << endl;

  try {
    array2.Insert(100, 5);
  } catch (const exception &e) {
    cout << "Exception: " << e.what() << endl;
  }

  try {
    array2[100];
  } catch (const exception &e) {
    cout << "Exception: " << e.what() << endl;
  }

  array1.Print();
  array2.Print();

  array2.Insert(1, array1);
  array2.Print();

  try {
    array2.Insert(111, array1);
  } catch (const exception &e) {
    cout << "Exception: " << e.what() << endl;
  }

  try {
    array2.Delete(111);
  } catch (const exception &e) {
    cout << "Exception: " << e.what() << endl;
  }

  for (auto it = array2.GetBeginIterator(); it != array2.GetEndIterator();
       ++it) {
    cout << *it.GetElement() << ' ';
  }
  cout << '\n';

  array2 = array1;
  array2.Print();

  return 0;
}
