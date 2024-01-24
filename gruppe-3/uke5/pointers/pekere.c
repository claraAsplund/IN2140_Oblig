// program for å forklare pekere
#include <stdio.h>

void funksjon_uten_pekere(int i)
{
    i = i + 1;
}

void funksjon(int *i)
{
    *i = *i + 1; // vi endrer det pekeren peker på
}

int main(void)
{
    int var = 20;

    // En peker = en variabel som lagrer addressen til en annen variabel.
    // Deklarer pekervariabelen. For å gjøre dette må vi ha en * foran variabelnavnet.
    int *ptr;

    // Setter pekeren til å peke på addressen til var.
    ptr = &var;

    // &ptr     addressen til selve pekeren.
    // *ptr     det som ligger på minneaddressen. Innholdet. Å hente ut dette kalles også dereferencing (?)

    printf("%p\n", ptr);
    printf("%p\n", &var); // addressen til var
    printf("%p\n", &ptr); // addressen til ptr
    printf("%d\n", *ptr); // det som ligger på minneaddressen

    // Peker med arrayer
    char a[] = "hello";
    char *p = "World";

    /* Forskjellen illustrert:
        +---+---+---+---+---+---+
    a:  | h | e | l | l | o |\0 |
        +---+---+---+---+---+---+
        +-----+     +---+---+---+---+---+---+
    p:  |  *======> | w | o | r | l | d |\0 |
        +-----+     +---+---+---+---+---+---+
    */

    // Peker i funksjon
    int tall = 5;
    printf("tall: %d\n", tall); // Gir 5
    funksjon(&tall);
    printf("tall: %d\n", tall); // Gir 6

    // Dersom vi IKKE bruker pekere
    funksjon_uten_pekere(tall);
    printf("tall: %d\n", tall); // tallet forblir 6 og vi har ikke klart å endre det.

    // Vi kan også ha pekere til pekere
    int **p2;

    p2 = &ptr; // p2 er en peker til en annen peker.
    printf("%p\n", p2);

    return 0;
}
