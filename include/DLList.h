#ifndef DLLIST_H
#define DLLIST_H

#include <string>

struct DLNode {
  DLNode *next;
  DLNode *prev;
  std::string *data;
};

struct DLList {
  DLNode *head;
  DLNode *tail;
};

int length(DLList *list);
void insert(DLList *list, DLNode *newNode);
void insertAfter(DLList *list, DLNode *node, DLNode *newNode);
DLNode *find(DLList *list, int index);
void removeNode(DLList *list, DLNode *node);
void print(DLList *list, int length);

#endif // DLLIST_H
