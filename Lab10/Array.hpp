#include <exception>
#include <iostream>
using namespace std;

class InvalidIndexException : public exception {
  virtual const char *what() const throw() { return "Invalid index!"; }
} invalidIndexException;

class Comparator {
public:
  virtual int CompareElements(void *e1, void *e2) = 0;
};

template <class T> class ArrayIterator {
private:
  T **list;
  int current;

public:
  ArrayIterator() : list(nullptr), current(0) {}
  ArrayIterator(T **list, int current) : list(list), current(current) {}
  ArrayIterator &operator++(int) {
    current++;
    return *this;
  }
  ArrayIterator &operator++() {
    current++;
    return *this;
  }
  ArrayIterator &operator--() {
    if (current <= 0)
      return *this;
    current--;
    return *this;
  }
  bool operator==(const ArrayIterator<T> &it) { return current == it.current; }
  bool operator!=(const ArrayIterator<T> &it) { return current != it.current; }
  T *GetElement() { return list[current]; }
};

template <class T> class Array {
private:
  T **list;
  int capacity;
  int size;

public:
  Array() : list(nullptr), capacity(0), size(0) {}
  ~Array() {
    for (int i = 0; i < size; i++) {
      delete list[i];
    }
    delete[] list;
  }
  Array(int capacity) : capacity(capacity), size(0) {
    list = new T *[capacity];
  }
  Array(const Array<T> &otherArray)
      : capacity(otherArray.capacity), size(otherArray.size) {
    list = new T *[capacity];
    for (int i = 0; i < size; i++) {
      list[i] = new T(*otherArray.list[i]);
    }
  }
  T &operator[](int index) {
    if (index < 0 || index >= size) {
      throw invalidIndexException;
    }
    return *list[index];
  }
  const Array<T> &operator+=(const T &newElem) {
    if (size >= capacity) {
      capacity = (capacity == 0) ? 5 : capacity * 2;
      T **temp = new T *[capacity];
      for (int i = 0; i < size; i++) {
        temp[i] = list[i];
      }
      delete[] list;
      list = temp;
    }
    list[size++] = new T(newElem);
    return *this;
  }
  const Array<T> &Insert(int index, const T &newElem) {
    if (index < 0 || index > size) {
      throw invalidIndexException;
    }
    if (size >= capacity) {
      capacity = (capacity == 0) ? 5 : capacity * 2;
      T **temp = new T *[capacity];
      for (int i = 0; i < size; i++) {
        temp[i] = list[i];
      }
      delete[] list;
      list = temp;
    }
    for (int i = size; i > index; i--) {
      list[i] = list[i - 1];
    }
    list[index] = new T(newElem);
    size++;
    return *this;
  }
  const Array<T> &Insert(int index, const Array<T> &otherArray) {
    if (index < 0 || index > size) {
      throw invalidIndexException;
    }
    while (size + otherArray.size >= capacity) {
      capacity = (capacity == 0) ? 5 : capacity * 2;
      T **temp = new T *[capacity];
      for (int i = 0; i < size; i++) {
        temp[i] = list[i];
      }
      delete[] list;
      list = temp;
    }
    for (int i = size - 1; i >= index; i--) {
      list[i + otherArray.size] = list[i];
    }
    for (int i = 0; i < otherArray.size; i++) {
      list[index + i] = new T(*otherArray.list[i]);
    }
    size += otherArray.size;
    return *this;
  }
  const Array<T> &Delete(int index) {
    if (index < 0 || index >= size) {
      throw invalidIndexException;
    }
    delete list[index];
    for (int i = index; i < size - 1; i++) {
      list[i] = list[i + 1];
    }
    size--;
    return *this;
  }
  bool operator=(const Array<T> &otherArray) {
    for (int i = 0; i < size; i++) {
      delete list[i];
    }
    delete[] list;

    size = otherArray.size;
    capacity = otherArray.capacity;

    list = new T *[capacity];
    for (int i = 0; i < size; i++) {
      list[i] = new T(*otherArray.list[i]);
    }

    return true;
  }
  void Sort() {
    if (list == nullptr)
      return;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (*list[i] > *list[j]) {
          T *temp = list[i];
          list[i] = list[j];
          list[j] = temp;
        }
      }
    }
  }
  void Sort(int (*compare)(const T &, const T &)) {
    if (list == nullptr)
      return;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (compare(*list[i], *list[j]) > 0) {
          T *temp = list[i];
          list[i] = list[j];
          list[j] = temp;
        }
      }
    }
  }
  void Sort(Comparator *comparator) {
    if (list == nullptr)
      return;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (comparator->CompareElements(list[i], list[j]) > 0) {
          T *temp = list[i];
          list[i] = list[j];
          list[j] = temp;
        }
      }
    }
  }
  int BinarySearch(const T &elem) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (*list[mid] == elem) {
        return mid;
      } else if (*list[mid] > elem) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
  int BinarySearch(const T &elem, int (*compare)(const T &, const T &)) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (compare(*list[mid], elem) == 0) {
        return mid;
      } else if (compare(*list[mid], elem) > 0) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
  int BinarySearch(T &elem, Comparator *comparator) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (comparator->CompareElements(list[mid], &elem) == 0) {
        return mid;
      } else if (comparator->CompareElements(list[mid], &elem) > 0) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
  int Find(const T &elem) {
    for (int i = 0; i < size; i++) {
      if (*list[i] == elem)
        return i;
    }
    return -1;
  }
  int Find(const T &elem, int (*compare)(const T &, const T &)) {
    for (int i = 0; i < size; i++) {
      if (compare(elem, *list[i]) == 0)
        return i;
    }
    return -1;
  }
  int Find(T &elem, Comparator *comparator) {
    for (int i = 0; i < size; i++) {
      if (comparator->CompareElements(&elem, list[i]) == 0)
        return i;
    }
    return -1;
  }
  int GetSize() { return size; }
  int GetCapacity() { return capacity; }
  void Clear() {
    for (int i = 0; i < size; i++) {
      delete list[i];
    }
    size = 0;
  }
  void Print() {
    for (int i = 0; i < size; i++) {
      cout << *list[i] << ' ';
    }
    cout << '\n';
  }
  ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(list, 0); }
  ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(list, size); }
};
