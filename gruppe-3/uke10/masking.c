#include <stdio.h>
#include <stdlib.h>

/*
Snuskedal universitet søknad
8 bits - donasjon
3 bits - karakter (heltall 1-6)
5 bits - ID
*/

// disse kaller vi makroer:
#define ID_MASK 0b0000000000011111
#define DONATION_MASK 0b1111111100000000
#define GRADE_MASK 0b0000000011100000

unsigned char hent_donasjon(unsigned short s)
{
    // må skifte bortover, ikke bare maske, fordi da får vi et for stort tall!
    return s >> 8;
}

unsigned char hent_karakter(unsigned short s)
{
    return (s & GRADE_MASK) >> 5; // viktig med parentes i bitoperasjoner
}

unsigned char hent_id(unsigned short s)
{
    return s & ID_MASK;
}

void print_soknad(unsigned short s)
{
    printf("ID %d\nKarakter %d\nDonasjon %d\n", hent_id(s), hent_karakter(s), hent_donasjon(s));
    printf("Score %d\n", hent_karakter(s) * hent_donasjon(s));
}

int main(void)
{
    unsigned short soknad1 = 0b0000000011001010;
    unsigned short soknad2 = 0b1111010000110010;

    print_soknad(soknad1);
    print_soknad(soknad2);
    return EXIT_SUCCESS;
}