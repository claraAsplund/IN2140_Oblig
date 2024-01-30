// stack og heap, dynamic memory allocation (malloc og free), levetid for allokerte data, sizeof og strlen

#include "stdio.h"
#include "stdlib.h" //trenger denne headeren for a bruke malloc
#include "string.h"

int main(void) {
    int* peker; 
    int verdi = 54;
    *peker = &verdi;

    printf("%p\n", peker);
    printf("%d\n", *peker); // Vi dereferenser peker for a fa tak i den faktiske verdien til variabelen var. 

    char array[] = "Hei";
    int array2[4] = {1, 2, 3, 4};
    int array3[4];

    array[2] = 'o';

    printf("%s\n", array);
    printf("%p\n", array);

    printf("size: %lu\n", sizeof(array2));

    for (int i = 0; i < 4; i++) {
        printf("%c\n", array[i]);
        //printf("%c", *(array + i));
    }

    int verdi2 = 4;
    int *peker2 = &verdi;

    printf("%d\n", verdi);

    char* name = malloc(20);
    if (name == NULL) {
        printf("feil med malloc\n");
        return -1;
    }

    //strcpy(name, "Ola nordmann");
    char var2[] = "Ola Nordmann";
    for(int i = 0; i < strlen(var2); i++) {
        name[i] = var2[i];
    }

    printf("%s\n", name);

    free(name);

    return 0;
}