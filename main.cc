#include "./include/DLList.h"

int main() {
  // Create empty list
  DLList *list = new DLList{nullptr, nullptr};

  // instantiate three empty nodes
  DLNode *firstNode = new DLNode{
      .next = nullptr, .prev = nullptr, .data = new std::string("A")};
  DLNode *secondNode = new DLNode{
      .next = nullptr, .prev = nullptr, .data = new std::string("B")};
  DLNode *thirdNode = new DLNode{
      .next = nullptr, .prev = nullptr, .data = new std::string("C")};

  // insert the three nodes into the list
  insert(list, firstNode);
  insert(list, secondNode);
  insert(list, thirdNode);

  // print the current list
  print(list, length(list));

  // remove second node in list
  removeNode(list, find(list, 1));

  // print list again after removal
  print(list, length(list));
}
