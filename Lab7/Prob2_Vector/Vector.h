#pragma once
#include <cstring>
#include <stdio.h>

/*
 * Info on template files:
 * https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
 * https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file
 */

template <class T> class Vector {
private:
  T *vec;
  int size;
  int allocatedSize;

public:
  Vector();
  int getSize();
  int getAllocSize();
  void push(T &x);
  T pop();
  void remove(int index);
  void insert(T &obj, int index);
  void sort(bool (*function)(T, T));
  const T *get(int index);
  void set(T &obj, int index);
  int count();
  int firstIndexOf(T &obj, bool (*function)(T, T) = nullptr);
  T &operator[](int index);
};

template <class T> Vector<T>::Vector() {
  this->vec = new T[8];
  this->size = 0;
  this->allocatedSize = 8;
}

template <class T> int Vector<T>::getSize() { return this->size; }
template <class T> int Vector<T>::getAllocSize() { return this->allocatedSize; }

template <class T> void Vector<T>::push(T &obj) {
  if (this->size + 1 >= this->allocatedSize) {
    this->allocatedSize *= 2;
    T *newVec = new T[this->allocatedSize];
    // copy memory into newvec
    memcpy(newVec, this->vec, this->size * sizeof(T));
    delete[] this->vec;
    this->vec = newVec;
    newVec = nullptr;
  }
  this->vec[this->size++] = obj;
}

template <class T> T Vector<T>::pop() {
  return (this->size > 0) ? this->vec[--this->size] : nullptr;
}

template <class T> void Vector<T>::remove(int index) {
  if (this->size == 0)
    return;
  // move from vec+index+1 to vec+index with a size of <size - index -1> bytes
  memmove(this->vec + index, this->vec + (index + 1),
          (this->size - index - 1) * sizeof(T));
}

template <class T> void Vector<T>::insert(T &obj, int index) {
  if (index >= this->size)
    return;
  if (this->size + 1 >= this->allocatedSize) {
    this->allocatedSize *= 2;
    T *newVec = new T[this->allocatedSize];
    // copy memory into newvec
    memcpy(newVec, this->vec, this->size * sizeof(T));
    delete[] this->vec;
    this->vec = newVec;
    newVec = nullptr;
  }

  // move vec memory 1 step further to allow insertion
  memmove(this->vec + index + 1, this->vec + index,
          (this->size - index - 1) * sizeof(T));
  this->vec[index] = obj;
  this->size++;
}

template <class T> const T *Vector<T>::get(int index) {
  if (index > this->size)
    return nullptr;
  return &this->vec[index];
}

template <class T> void Vector<T>::set(T &obj, int index) {
  this->vec[index] = obj;
}

template <class T> int Vector<T>::count() { return this->size; }

template <class T> void Vector<T>::sort(bool (*function)(T, T)) {
  for (int i = 0; i < this->size - 1; i++)
    for (int j = i + 1; j < this->size; j++)
      if (function == nullptr) {
        if (this->vec[i] > this->vec[j]) {
          T aux = this->vec[i];
          this->vec[i] = this->vec[j];
          this->vec[j] = aux;
        }
      } else {
        if (function(this->vec[i], this->vec[j])) {
          T aux = this->vec[i];
          this->vec[i] = this->vec[j];
          this->vec[j] = aux;
        }
      }
}

template <class T> int Vector<T>::firstIndexOf(T &obj, bool (*function)(T, T)) {
  for (int i = 0; i < this->size; i++) {
    if (function != nullptr) {
      if (function(obj, this->vec[i]))
        return i;
    } else if (obj == this->vec[i])
      return i;
  }

  return -1;
}
template <class T> T &Vector<T>::operator[](int index) {
  static T defaultReturnValue;
  if (!(0 <= index < this->size))
    return defaultReturnValue;
  return this->vec[index];
};
