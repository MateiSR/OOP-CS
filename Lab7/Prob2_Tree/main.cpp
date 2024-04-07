#include "Tree.h"
#include <stdio.h>
#include <string.h>

bool compare(int a, int b) { return a > b; }

int main() {
  Tree<int> root;
  root.addNode(nullptr, 1);
  root.addNode(&root, 2);
  root.addNode(&root, 22);
  root.addNode(&root, 222);
  Tree<int> *node2 = root.find(2);
  printf("Node 2 parent: %d\n", node2->parent->data);
  root.print();
  root.addNode(node2, 3);
  root.addNode(node2, 33);
  Tree<int> *node22 = root.find(22);
  root.addNode(node22, 4);
  printf("----\n");
  root.print();
  printf("Remove 2\n");
  root.deleteNode(node2);
  printf("root children: %d\n", root.childrenCount);
  root.print();
  root.addNode(&root, 5);
  root.addNode(node22, 6);
  root.insertNode(&root, -1, 0);
  printf("root children: %d\n", root.childrenCount);
  root.print();
  printf("root children:\n");
  for (int i = 0; i < root.childrenCount; i++) {
    printf("child %d: %d\n", i, root.children[i]->data);
  }
  printf("--sorting children of root--\n");
  root.sortChildren(&root);
  root.print();
  printf("--sorting children of root using compare function (>)--\n");
  root.sortChildren(&root, compare);
  root.print();
  printf("root children:\n");
  for (int i = 0; i < root.childrenCount; i++) {
    printf("child %d: %d\n", i, root.children[i]->data);
  }
  printf("root count of nodes: %d\n", root.getChildrenCount(&root));
  // printf("count of nodes: %d\n", Tree<int>::getChildrenCount(&root));
  printf("node 22 count of nodes: %d\n", root.getChildrenCount(node22));
  Tree<int> *node222 = root.find(222);
  root.addNode(node222, 7);
  printf("node 222 count of nodes: %d\n", root.getChildrenCount(node222));
  printf("root count of nodes: %d\n", root.getChildrenCount(&root));
  return 0;
}
