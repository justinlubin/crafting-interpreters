#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linked_list.h"

List *list_new() {
  List *list = malloc(sizeof (List));
  list->first = NULL;
  list->last = NULL;
  return list;
}

void list_free(List *list) {
  Node *node = list->first;
  while(node) {
    free(node->data);

    if (node->prev) {
      free(node->prev);
    }

    if (node->next) {
      node = node->next;
    } else {
      free(node);
      break;
    }
  }
  free(list);
}

void list_insert_first(List *list, char *data) {
  Node *node = malloc(sizeof (Node));
  node->data = data;
  node->next = list->first;
  node->prev = NULL;

  if (list->first) {
    list->first->prev = node;
  }

  list->first = node;

  if (!list->last) {
    list->last = node;
  }
}

void list_insert_last(List *list, char *data) {
  Node *node = malloc(sizeof (Node));
  node->data = data;
  node->prev = list->last;
  node->next = NULL;

  if (list->last) {
    list->last->next = node;
  }

  list->last = node;

  if (!list->first) {
    list->first = node;
  }
}

Node *list_find(List *list, char *data) {
  Node *current = list->first;
  while (current) {
    if (strcmp(data, current->data) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void list_delete(List *list, char *data) {
  Node *node = list_find(list, data);

  if (node) {
    if (node == list->first) {
      list->first = node->next;
    }
    if (node == list->last) {
      list->last = node->prev;
    }
    if (node->prev) {
      node->prev->next = node->next;
    }
    if (node->next) {
      node->next->prev = node->prev;
    }
    free(node);
  }
}

void node_debug(Node *node) {
  printf("me (node): %p\n", node);
  printf("prev: %p\n", node->prev);
  printf("data: %s\n", node->data);
  printf("next: %p\n", node->next);
}

void list_debug(List *list) {
  printf("====================\n");
  printf("me (list): %p\n", list);
  printf("first: %p\n", list->first);
  printf("last: %p\n", list->last);
  Node *current = list->first;
  while (current) {
    printf("----------\n");
    node_debug(current);
    current = current->next;
  }
}

void list_print(List *list) {
  Node *current = list->first;
  printf("[");
  while (current) {
    printf("%s", current->data);
    if (current->next) {
      printf(", ");
      current = current->next;
    } else {
      break;
    }
  }
  printf("]\n");
}
