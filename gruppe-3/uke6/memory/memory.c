#include <stdlib.h>
#include <stdio.h>

int main(void) {

    srand(10);
    int* myArray = malloc(10*sizeof(int));
    int* myBadArray = malloc(20*sizeof(int));

    if(myArray == NULL) {

        fprintf(stderr, "Noe gikk galt");
        exit(EXIT_FAILURE);

    }

    if(myBadArray == NULL) {

        fprintf(stderr, "Noe gikk galt");
        exit(EXIT_FAILURE);

    }

    for(int i=0; i<10; i++) {

        myArray[i] = rand() % 20;

    }



    for(int i=0; i<21; i++) {

        myBadArray[i] = rand() % 20;

    }

    free(myArray);


    


    return EXIT_SUCCESS;
}