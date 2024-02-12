#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    // med buffring
    printf("Hei");
    sleep(2);
    printf(", paa deg!\n");


    sleep(1);

    // uten buffring
    fprintf(stderr, "Hei");
    sleep(2);
    fprintf(stderr, ", paa deg!\n");
    return EXIT_SUCCESS;
}
