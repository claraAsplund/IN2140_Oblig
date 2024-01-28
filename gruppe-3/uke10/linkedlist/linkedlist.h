#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>
#include <stdlib.h>

struct node {
  void *data;
  struct node *next;
  struct node *prev;
};
typedef struct node node;

typedef struct {
  node *first;
  node *last;
  int size;
} linked_list;

linked_list *ll_init();
int ll_append(linked_list *ll, void *data);
int insert(linked_list *ll, int idx, void *data);
node *ll_pop(linked_list *ll);
node *ll_remove(linked_list *ll, int idx);

#endif // !LINKEDLIST_H
