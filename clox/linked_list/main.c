#include <stdio.h>
#include <string.h>

#include "linked_list.h"

int main(int argc, char **argv) {
  List *list = list_new();
  list_print(list);

  list_insert_first(list, strdup("aaa"));
  list_print(list);

  list_insert_first(list, strdup("bb"));
  list_print(list);

  list_insert_last(list, strdup("ccccc"));
  list_print(list);

  list_delete(list, "ccccc");
  list_print(list);

  list_delete(list, "bbbbb");
  list_print(list);

  list_delete(list, "bb");
  list_print(list);

  list_insert_last(list, strdup("goodbye"));
  list_print(list);

  list_free(list);

  return 0;
}
