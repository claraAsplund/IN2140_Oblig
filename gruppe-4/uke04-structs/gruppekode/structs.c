#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// du kan forkorte også syntax i C med bruk av typedef. 
// Vær forsiktig med denne slik at du ikke overskiver andre standard syntax.
// Dette er godt bruk av typedef:
typedef unsigned char uint8;

// Slik lager man struct
struct person {
    char *navn;
    uint8 alder;
    unsigned int personnr;
};

// Her kan man bruke typedef slik at man ikke trenger å skrive "struct person" hver gang.
typedef struct person person;

// Frigjør først alt som har allokert minne på heap før du frigjør struct. Ellers taper du minne!
void freeThisPerson(person *p) {
    free(p->navn);
    free(p);
}


int main(void) {
    // struct på stack
    struct person p1;
    p1.navn = "Jonas";
    p1.alder = 23;
    p1.personnr = 12345;

    printf("Han heter %s, han er %d år gammel.\n", p1.navn, p1.alder);

    // struct på heap

    printf("struct person bruker %d bytes.\n", (int) sizeof(person));
    person *p2 = malloc(sizeof(person));
    p2->navn = malloc(10);
    p2->alder = 100;
    p2->personnr = 54321;


    printf("Han andre heter %s, han er %d år gammel.\n", p2->navn, p2->alder);

    freeThisPerson(p2);

    // Akkurat samme som "return 0;"
    return EXIT_SUCCESS;
}