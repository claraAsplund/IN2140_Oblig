#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *next;
    struct node *prev;
    int value;
} node_t;

node_t *head, *tail;

void set_between(node_t *left, node_t *middle, node_t *right) {
    /* ... */
}

void remove_node(node_t *node) {
    /* ... */
}

void push(int number) {
    /* ... */
}

int pop(void) {
    /* ... */
}

void print_list() {
    /* ... */
}

void free_list() {
    /* ... */
}

int main(void) {
    head = malloc(sizeof(node_t));
    tail = malloc(sizeof(node_t));
    /* ... */
    return EXIT_SUCCESS;
}
