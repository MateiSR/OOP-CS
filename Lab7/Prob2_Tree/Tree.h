#pragma once
#include <iostream>

template <class T> class Tree {
private:
public:
  T data;
  Tree<T> *parent = nullptr;
  Tree<T> **children = nullptr;
  unsigned int childrenCount;
  unsigned int childrenCapacity;
  Tree();
  Tree(T data, Tree<T> *parent = nullptr);
  ~Tree();
  // add a node to the tree. if parent is null, set it as the root
  void addNode(Tree<T> *parent, T data);
  // get the index-th child of the parent node
  T *getNode(Tree<T> *parent, unsigned int index);
  // delete a node and all its children
  void deleteNode(Tree<T> *node);
  // recursively search all nodes for a parameter
  Tree<T> *find(T data, bool (*function)(T, T) = nullptr);
  // insert a new node in the tree at a specific index, given its parent node
  void insertNode(Tree<T> *parent, T data, unsigned int index);
  // sort all children from a specific node using a callback function
  void sortChildren(Tree<T> *node, bool (*function)(T, T) = nullptr);
  // return how many children a node has, recursively counting all children.
  // if called with nullptr, returns the number of children of the root node
  unsigned int getChildrenCount(Tree<T> *node);
  // static unsigned int getChildrenCount(Tree<T>*);
  // prints all nodes in the tree, using a callback function.
  // if the function is null, it will print the data using std::cout
  void print(void (*function)(T) = nullptr, bool recurse = true);
};

template <class T> Tree<T>::Tree() {
  this->children = nullptr;
  this->childrenCount = 0;
  this->childrenCapacity = 0;
}

template <class T> Tree<T>::Tree(T data, Tree<T> *parent) {
  this->data = data;
  this->children = nullptr;
  this->childrenCount = 0;
  this->childrenCapacity = 0;
  this->parent = parent;
}

template <class T> void Tree<T>::print(void (*function)(T), bool recurse) {
  if (function == nullptr)
    std::cout << data << std::endl;
  else
    function(data);
  if (children == nullptr)
    return;
  for (unsigned int i = 0; i < childrenCount; i++)
    if (children[i] != nullptr)
      children[i]->print(function);
}

template <class T> Tree<T>::~Tree() {
  if (this->children == nullptr)
    return;
  // delete all children
  for (unsigned int i = 0; i < childrenCount; i++)
    if (children[i] != nullptr)
      delete children[i];
  delete[] children;
}

template <class T> void Tree<T>::addNode(Tree<T> *parent, T data) {
  printf("> Adding %d to %d\n", data, parent == nullptr ? 0 : parent->data);
  if (parent == nullptr) {
    this->data = data;
    return;
  }
  if (parent->children == nullptr) {
    printf("> Creating children for %d\n", parent->data);
    parent->children = new Tree<T> *[2];
    parent->childrenCapacity = 2;
  }
  if (parent->childrenCount == parent->childrenCapacity) {
    Tree<T> **newChildren = new Tree<T> *[childrenCapacity * 2];
    // for (unsigned int i = 0; i < childrenCount; i++) newChildren[i] =
    // children[i];
    memcpy(newChildren, parent->children,
           parent->childrenCount * sizeof(Tree<T> *));
    delete[] parent->children;
    parent->children = newChildren;
    parent->childrenCapacity *= 2;
  }
  parent->children[parent->childrenCount] = new Tree<T>(data, parent);
  parent->childrenCount++;
}

template <class T> T *Tree<T>::getNode(Tree<T> *parent, unsigned int index) {
  if (parent == nullptr)
    return nullptr;
  if (index >= parent->childrenCount)
    return nullptr;
  return &parent->children[index]->data;
}

template <class T> void Tree<T>::deleteNode(Tree<T> *node) {
  if (node == nullptr)
    return;
  // remove the node from the parent's children list
  if (node->parent != nullptr) {
    for (unsigned int i = 0; i < node->parent->childrenCount; i++) {
      if (node->parent->children[i] == node) {
        node->parent->children[i] = nullptr;
        memcpy(node->parent->children + i, node->parent->children + i + 1,
               (node->parent->childrenCount - i - 1) * sizeof(Tree<T> *));
        break;
      }
    }
    node->parent->childrenCount--;
  }
  delete node;
}

template <class T> Tree<T> *Tree<T>::find(T data, bool (*function)(T, T)) {
  if (function == nullptr) {
    if (this->data == data)
      return this;
  } else {
    if (function(this->data, data))
      return this;
  }
  if (children == nullptr)
    return nullptr;
  for (unsigned int i = 0; i < this->childrenCount; i++) {
    Tree<T> *result = children[i]->find(data, function);
    if (result != nullptr)
      return result;
  }
  return nullptr;
}

template <class T>
void Tree<T>::insertNode(Tree<T> *parent, T data, unsigned int index) {
  if (parent == nullptr) {
    addNode(nullptr, data);
    return;
  }
  if (parent->children == nullptr) {
    parent->children = new Tree<T> *[2];
    parent->childrenCapacity = 2;
  }
  if (parent->childrenCount == parent->childrenCapacity) {
    Tree<T> **newChildren = new Tree<T> *[childrenCapacity * 2];
    memcpy(newChildren, parent->children,
           parent->childrenCount * sizeof(Tree<T> *));
    delete[] parent->children;
    parent->children = newChildren;
    parent->childrenCapacity *= 2;
  }
  // move all children to the right
  for (unsigned int i = parent->childrenCount; i > index; i--) {
    parent->children[i] = parent->children[i - 1];
  }
  parent->children[index] = new Tree<T>(data, parent);
  parent->childrenCount++;
}

template <class T>
void Tree<T>::sortChildren(Tree<T> *node, bool (*function)(T, T)) {
  if (node == nullptr)
    return;
  if (children == nullptr)
    return;
  for (int i = 0; i < node->childrenCount - 1; i++) {
    for (int j = i + 1; j < node->childrenCount; j++) {
      if (function != nullptr) {
        if (function(node->children[i]->data, node->children[j]->data)) {
          Tree<T> *temp = node->children[i];
          node->children[i] = node->children[j];
          node->children[j] = temp;
        }
      } else {
        if (node->children[i]->data < node->children[j]->data) {
          Tree<T> *temp = node->children[i];
          node->children[i] = node->children[j];
          node->children[j] = temp;
        }
      }
    }
  }
}

template <class T> unsigned int Tree<T>::getChildrenCount(Tree<T> *node) {
  if (node == nullptr)
    node = this;
  if (node->children == nullptr)
    return 0;
  // printf("Counting children of node %d\n", node->data);
  unsigned int totalCount = node->childrenCount;
  for (int i = 0; i < node->childrenCount; i++) {
    unsigned int count = getChildrenCount(node->children[i]);
    // return node->childrenCount + count;
    totalCount += count;
  }
  return totalCount;
}
