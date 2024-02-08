// Libraries som importeres.
#include <stdio.h> // Input, output, osv.
#include <stdlib.h> // malloc, free, osv.
#include <string.h> // Alle string operasjoner



int main(void) {
    // Kort intro til string funksjoner.

    // comparing
    char *s1 = "BC";
    char *s2 = "ABC";
    if (strcmp(s1,s2) == 0) {
        printf("Equal strings\n");
    } else if(strcmp(s1,s2) == -1) {
        printf("%s kommer før %s i alfabetisk rekkefølge\n", s1, s2);        
    } else if(strcmp(s1,s2) == 1) {
        printf("%s kommer før %s i alfabetisk rekkefølge\n", s2, s1);        
    } 

    // kopier string fra source til destination
    char *s3 = "Dette er en ny string!";
    char s4[256];

    // s4 er ikke peker, dermed må vi bruke & for å sende adressen til s4. 
    // Du får warnings i kompilator hvis du ikke caster &s4 til char*, viktig å huske.
    strcpy((char*) &s4, s3); 
    printf("s4 er nå: \"%s\"\n", s4);

    strcpy((char*) &s4, "Nå skal s4 overskrives!");
    printf("s4 er nå: \"%s\n", s4);

    // lengde av string
    printf("String med lengde %d bytes: %s\n", (int) strlen(s4), s4);

    // iterere over string (mange måter å gjøre det på, dette er opp til deg), men jeg liker å gjøre slikt:
    for(int i = 0; s3[i] != '\0'; i++) {
        printf("%c", s3[i]);
    }
    printf("\n");

    // Duplisering av string
    // NB! Her bruker vi strdup() som returnerer peker til en kopiert streng som har allokert minne med malloc. 
    // Da må vi huske å bruke free()!! Se "man 3 strdup"
    char s5[256] = "String som dupliseres. Husk å frigjøre denne stringen!";
    char *s6 = strdup((char*) &s5);

    printf("Duplisert string: %s\n", s6);
    free(s6);
    printf("Stringen ovenfor har blitt frigjort!\n");

    // Det finnes mange andre funksjoner i string.h library. Se mer på "man 3 string", der finner du alt du trenger!
    return 0;
}