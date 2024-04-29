#pragma once
#include <cstring>

template <typename K, typename V> struct Pair {
  K key;
  V value;
  int index;
};

template <typename K, typename V> class Map {
private:
  Pair<K, V> *data;
  int size;
  int capacity;
  int index = 0;

public:
  Map();
  ~Map();
  V &operator[](K key);
  Pair<K, V> *begin();
  Pair<K, V> *end();
  void set(K key, V value);
  bool get(const K &key, V &value);
  int count();
  void clear();
  bool del(const K &key);
  bool includes(const Map<K, V> &other);
};

template <typename K, typename V> Map<K, V>::Map() : size(0), capacity(2) {
  data = new Pair<K, V>[capacity];
}

template <typename K, typename V> Map<K, V>::~Map() { delete[] data; }

template <typename K, typename V> V &Map<K, V>::operator[](K key) {
  for (int i = 0; i < size; i++)
    if (data[i].key == key) {
      return data[i].value;
    }
  if (size == capacity) {
    Pair<K, V> *temp = new Pair<K, V>[capacity * 2];
    // for (int i = 0; i < size; i++) {
    //   temp[i] = data[i];
    // }
    memcpy(temp, data, sizeof(Pair<K, V>) * size);
    delete[] data;
    data = temp;
    capacity *= 2;
  }
  data[size].key = key;
  data[size].index = index++;
  return data[size++].value;
}

template <typename K, typename V> void Map<K, V>::set(K key, V value) {
  for (int i = 0; i < size; i++)
    if (data[i].key == key) {
      data[i].value = value;
      return;
    }
  if (size == capacity) {
    Pair<K, V> *temp = new Pair<K, V>[capacity * 2];
    // for (int i = 0; i < size; i++) {
    //   temp[i] = data[i];
    // }
    memcpy(temp, data, sizeof(Pair<K, V>) * size);
    delete[] data;
    data = temp;
    capacity *= 2;
  }
  data[size].key = key;
  data[size].value = value;
  data[size].index = index++;
  size++;
}

template <typename K, typename V> bool Map<K, V>::get(const K &key, V &value) {
  for (int i = 0; i < size; i++)
    if (data[i].key == key) {
      value = data[i].value;
      return true;
    }
  return false;
}

template <typename K, typename V> int Map<K, V>::count() { return size; }

template <typename K, typename V> void Map<K, V>::clear() {
  delete[] data;
  capacity = 2;
  data = new Pair<K, V>[capacity];
  size = 0;
  index = 0;
}

template <typename K, typename V> Pair<K, V> *Map<K, V>::begin() {
  index = 0;
  return data;
}

template <typename K, typename V> Pair<K, V> *Map<K, V>::end() {
  return data + size;
}

template <typename K, typename V> bool Map<K, V>::del(const K &key) {
  for (int i = 0; i < size; i++)
    if (data[i].key == key) {
      // for (int j = i; j < size - 1; j++) {
      //   data[j] = data[j + 1];
      // }
      memcpy(data + i, data + i + 1, sizeof(Pair<K, V>) * (size - i - 1));
      memcpy(data + size - 1, data + size, sizeof(Pair<K, V>) * 1);
      size--;
      return true;
    }
  return false;
}

template <typename K, typename V>
bool Map<K, V>::includes(const Map<K, V> &other) {
  for (int i = 0; i < other.size; i++) {
    for (int j = 0; j < size; j++) {
      const char *temp;
      if (!this->get(other.data[i].key, temp)) {
        return false;
      }
      if (strcmp(temp, other.data[i].value) != 0) {
        return false;
      }
    }
  }
  return true;
}
