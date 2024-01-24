#include <stdio.h>
#include <stdlib.h>

int *malloc_function() {
  int *myArray = malloc(15 * sizeof(int));

  if (myArray == NULL) {
    fprintf(stderr, "Noe gikk galt\n");
    exit(EXIT_FAILURE);
  }
  return myArray;
}

int main(void) {

  srand(10);
  int *myArray = malloc(10 * sizeof(int));

  if (myArray == NULL) {
    fprintf(stderr, "Noe gikk galt");
    return EXIT_FAILURE;
  }

  int *myArray2;

  myArray2 = malloc_function();

  for (int i = 0; i < 10; i++) {
    myArray[i] = rand() % 20;
  }

  free(myArray);
  free(myArray2);
  return EXIT_SUCCESS;
}
