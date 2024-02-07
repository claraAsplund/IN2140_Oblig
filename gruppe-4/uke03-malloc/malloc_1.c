#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char const *argv[]) {
    char *tekst = malloc(4);
    tekst[0] = 'C';
    tekst[1] = 'b';
    tekst[2] = 'r';
    tekst[3] = 'a';
    printf("%s\n", tekst);
    return 0;
}
