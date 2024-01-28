#include "vector.c"
#include <stdio.h>
#include <stdlib.h>
#define TESTSIZE 25
int main(void) {

  Vector* vec;
  srand(111);

  int ret_val = init_vector(&vec, TESTSIZE);

  for (int i = 0; i < TESTSIZE; i++) {

    int toAdd = rand() % 200;
    add_elem(&vec, toAdd);
  }

  for (int i = 0; i < vec->currentSize; i++) {

    printf("val: %d\n", vec->elem[i]);
  }


  printf("---------------\n");
  remove_idx(&vec, 1);
  remove_idx(&vec, vec->currentSize-1);

  for (int i = 0; i < vec->currentSize; i++) {

    printf("val: %d\n", vec->elem[i]);
  }

  destruct_vector(vec);

  return 0;
}