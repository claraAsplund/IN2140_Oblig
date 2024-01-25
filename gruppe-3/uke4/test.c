#include <stdio.h>
#include <stdlib.h>


int main(void) {
    
    char streng1[] = "Hallo!"; // jeg er på stacken
    char *streng2 = "Hello!"; // jeg readonly
    char *streng3 = malloc(sizeof(char) * 7); // jeg er på heapen

    int *arr = malloc(sizeof(int) * 3);
    arr[0] = 3;
    // *arr = 4;

    *(arr + (sizeof(int) * 2)) = 5;

    printf("Første tall: %d\nAndre tall: %d\n", *arr, *(arr + sizeof(int)));

    streng3[0] = 'H';
    streng3[1] = 'a';
    // ....
    streng3[6] = '\0';


    // printf("Her er pekerverdien:\n%c\n", *(streng3 + sizeof(char)));

    free(streng3);
    free(arr);

    return EXIT_SUCCESS;
}


/*
-------------
--STRENG 1---
0x01 : H
0x02 : a
...
0x08 : \0




eksempel 2
STACK
-----------
0x01 : H
0x02 : a
...
0x08 : \0

....

0x400 : 3
0x404 : 5
0x408 : 32038457209348


0x480 : H
0x481 : a
...
0x487 : \0
-----------
HEAP

*/