#include "stdio.h"
int main(void) {

    // Nar vi skal printe en variabel til terminalen, ma den skrives pa denne formen.
    // C har ikke typen String som Java. Nar vi skal lagre en streng-variabel ma den lagres som 
    // i en char* peker eller char[] (en array med bestemt lengde). 
    // Nar du bruker bruker en peker, vil variabelen anses som read-only, som betyr at du ikke kan modifieres. 
    char* var = "hello";
    printf("Denne variablen printes ut: %s\n", var);
    var += 'h';
    printf("Denne variablen printes ut: %s\n", var);



    // min verdier ble introdusert i C99 og alle store revisjoner av C siden har det (C99, C11 og C17)
    // char: for oss (-128)-127 (signed), ARM er typisk 0-255 (unsigned), opp til implementasjon
    printf("\nSize of char %lu\n", sizeof(char));

    // minst 2 bytes, for oss 2 bytes
    printf("\nSize of short %lu\n", sizeof(short) );

    // minst 2 bytes, for oss 4 bytes 
    printf("\nSize of int %lu\n", sizeof(int) );

    // minst 4 bytes, for oss 8 bytes
    printf("\nSize of long %lu\n", sizeof(long) );

    // minst 8 bytes, for oss 8 bytes
    printf("\nSize of long long %lu\n\n", sizeof(long long) );
    
    // char, unsigned char, int, long 


    return 0;
}