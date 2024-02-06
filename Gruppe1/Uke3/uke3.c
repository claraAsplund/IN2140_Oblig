/*avanserte datatyper med struct, aksess med og uten peker, dereferensering av pekere*/

#include "stdio.h"
#include "stdlib.h" //malloc
#include "string.h" //strdup

struct bil {
    char* regNr;
    int prodYear;
};

typedef struct bil Bil;

//lager en struct bil
struct bil *createBil(char *regNr, int prodYear){
    struct bil *car = malloc(sizeof(struct bil));

    if(car == NULL){ //sjekker om malloc fungerte
        printf("malloc failed\n");
        exit(1);
    }

    car ->prodYear = prodYear;
    car->regNr = strdup(regNr);

    
    if (car ->regNr == NULL){
        perror("strdup\n");
        exit(1);
    }
    return car;
}

void printBil(Bil *b) {
    printf("Registreringsnummer: %s\nProduction year: %d\n", b->regNr, b->prodYear);
}

int main(){
    //minst 12
    printf("size of bil = %ld\n", sizeof(struct bil));

    //lager struct
    struct bil ford;
    ford.prodYear = 1999;
    ford.regNr = "AB12345";

    printf("RegNr = %s, prodYear = %d\n",ford.regNr, ford.prodYear );


    //lager struct i heap
    struct bil *fiat = malloc(sizeof(struct bil));
    if(fiat == NULL){
        printf("malloc failed\n");
        return 1;
    }

    // -> er det samme som derefere og så sette verdien
    fiat -> prodYear = 2000;
    fiat -> regNr = "123";
  

    printf("RegNr = %s, prodYear = %d\n",fiat->regNr, fiat ->prodYear);


    struct bil *car = createBil("Abd3223", 2020);

    printBil(car);

    free(car->regNr); 
    free(car);
    free(fiat);

    return 0;
}