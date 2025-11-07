#include "./include/DLList.h"

int main() {
  // Create empty list
  DLList *list = new DLList{nullptr, nullptr};

  DLNode *firstNode = new DLNode{
      .next = nullptr, .prev = nullptr, .data = new std::string("A")};
  DLNode *secondNode = new DLNode{
      .next = nullptr, .prev = nullptr, .data = new std::string("B")};
  DLNode *thirdNode = new DLNode{
      .next = nullptr, .prev = nullptr, .data = new std::string("C")};

  // insert two nodes
  insert(list, firstNode);
  insert(list, secondNode);
  insert(list, thirdNode);

  print(list, length(list));

  removeNode(list, find(list, 1));
  print(list, length(list));
}
