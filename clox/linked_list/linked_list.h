#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h>

typedef struct Node_struct {
  char *data;
  struct Node_struct *next;
  struct Node_struct *prev;
} Node;

typedef struct List_struct {
  Node *first;
  Node *last;
} List;

List *list_new();
void list_free(List *list);

void list_insert_first(List *list, char *data);
void list_insert_last(List *list, char *data);
Node *list_find(List *list, char *data);
void list_delete(List *list, char *data);

void list_debug(List *list);
void list_print(List *list);

#endif
