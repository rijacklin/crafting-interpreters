#include "DLList.h"
#include <iostream>

int length(DLList *list) {
  int count = 0;

  // start at the head of list
  DLNode *node = list->head;

  // traverse forward through the list
  while (node != nullptr) {
    count++;
    node = node->next;
  }

  return count;
}

// insert into empty list
void insert(DLList *list, DLNode *newNode) {
  // check if head of list is empty
  if (list->head == nullptr) {
    list->head = newNode;
    list->tail = newNode;

    newNode->prev = nullptr;
    newNode->next = nullptr;
  } else {
    insertAfter(list, list->tail, newNode);
  }
}

void insertAfter(DLList *list, DLNode *node, DLNode *newNode) {
  // attach prev pointer of newNode to node being inserted after
  newNode->prev = node;

  // if the current node is the end of the list
  if (node->next == nullptr) {
    // ensure the newNode's next pointer isn't pointing to anything
    newNode->next = nullptr;

    // set newNode as the tail of the list
    list->tail = newNode;
  } else {
    // point newNode's next to what the previous node's next was pointing to
    newNode->next = node->next;

    // point the next node's previous pointer to newNode
    node->next->prev = newNode;
  }

  // point the previous node's next pointer to newNode
  node->next = newNode;
}

DLNode *find(DLList *list, int index) {
  // start at the head of list
  DLNode *node = list->head;

  // traverse forward through the list
  for (int i = 0; i < index; i++) {
    if (node->next != nullptr) {
      node = node->next;
    }
  }

  return node;
}

void removeNode(DLList *list, DLNode *node) {
  if (node->prev == nullptr) {
    list->head = node->next;
  } else {
    node->prev->next = node->next;
  }

  if (node->next == nullptr) {
    list->tail = node->prev;
  } else
    node->next->prev = node->prev;
}

void print(DLList *list, int length) {
  std::cout << "Doubly-Linked List: [";

  for (int i = 0; i < length; i++) {
    DLNode *current = find(list, i);

    if (current->next != nullptr) {
      std::cout << *(current->data) << " => ";
    } else {
      std::cout << *(current->data) << "]" << std::endl;
    }
  }
}
