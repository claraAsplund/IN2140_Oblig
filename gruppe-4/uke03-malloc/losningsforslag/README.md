# Løsningsforslag for uke 3

### Oppgave 0.1
```makefile
min_fil: min_fil.c
    gcc -g -std=gnu11 min_fil.c -o min_fil
```
`min_fil.c` legges til som en dependency på høyre side av kolon.

****

### Oppgave 1.1
```c
int strlen_kopi(const char *s) {
    int counter = 0;
    while (*s++) counter++; // så lenge det s peker på ikke er `\0` ...
    return counter;
}
```

### Oppgave 1.2
```c
void copy_array(char arr1[], char arr2[]) {
    do {
        *arr2++ = *arr1;
    } while (*arr1++);
}
```
##### Kommentarer:
Her antar vi at det som ligger i `arr1` er en null-terminert streng. Dermed vil løkken automatisk avslutte når vi er på slutten av arrayet. Dersom `arr1` *ikke* er en streng, måtte vi tatt in en lengde som parameter i tillegg for å vite hvor mange bytes man skal kopiere.

Her bruker vi en kompakt variant som benytter det at vi ikke trenger pekerne til noe senere i denne funksjonen, og dermed kan forandre på dem. Vi sørger for å kopiere null-byten ved å ha en `do .. while`-løkke, som altså kjøres *før* while-testen sjekkes.
Det er mange måter å gjøre skrive denne funksjonen på, dette er bare en variant :)

****

### Oppgave 2.1
```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    if (argc < 4) printf("Error: Trenger tre argumenter.\n");
    else printf("arg1: '%s', arg2: '%s', arg3: '%s'\n", argv[1], argv[2], argv[3]);
    return 0;
}
```
##### Kommentarer:
Vi må sørge for at `argc` er minst 4, ettersom programmet alltid vil ha ett argument som ligger i `argv[0]`. Dette argumentet er navnet på selve filen som kjøres.

### Oppgave 2.2
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char const *argument;

    if (argc < 2) {
        printf("Error: Trenger ett argument.\n");
        return EXIT_FAILURE;
    }

    argument = argv[1];
    if (strlen(argument) > 1) {
        printf("Error: '%s' er ikke en bokstav\n", argument);
        return EXIT_FAILURE;
    }

    char b = *argument;
    b++;
    printf("%c\n", b);

    return EXIT_SUCCESS;
}

```
##### Kommentar:
Kan også skrives slik...
```c
printf("%c\n", argc > 1 ? *argv[1]+1 : '\0');
```

### Oppgave 2.3
```sh
./argv_1 a b c d  
```
##### Kommentar:
Her kjøres programmet med fire parametre. Programmet skriver ut like mange bokstaver som antall parametre, og den tar alltid inn ett argument. Dermed sender vi inn 4 til for å skrive ut hele strengen.

****

### Oppgave 3.1
```c
printf("Float: %ld, float pointer: %ld\n", sizeof(float), sizeof(float *));
```
##### Kommentar:
Utskrift blir "Float: 4, float pointer: 8" (på de fleste maskiner). Vi bruker `%ld` (long decimal) for å skrive ut svaret fra `sizeof()`.

### Oppgave 3.2
```c
void print_size(char arr[]) {
    printf("%ld\n", sizeof(arr));
}

int main(void) {
    char array[50];
    printf("%ld\n", sizeof(array));
    print_size(array);
    return 0;
}
```
##### Kommentar:
- Første utskrift blir `50`, siden kompilatoren vet størrelsen på arrayet (det er opprettet i samme skop med en konstant lengde).
- Andre utskrift blir `8`, ettersom kompilatoren *ikke* vet størrelsen på arrayet som blir sendt inn. Dermed gir den ut størrelsen av datatypen istedenfor, nemlig størrelsen av en `char *` som er 8.

****

### Oppgave 4.1
- Strengen "Cbra" er fire bokstaver + en null-byte, altså må vi allokere 5 bytes for denne strengen (`strlen(s) + 1`).
- Problemet med `malloc_1.c` er at det hverken allokeres plass til null-byten, og den settes ikke heller. I tillegg har man glemt å frigjøre minnet allokert med `malloc`, og man burde også sjekke returverdien. En riktig variant av programmet kan se slik ut:
```c
int main(void) {
    char *tekst = malloc(5);
    if (tekst == NULL) return EXIT_FAILURE;
    tekst[0] = 'C';
    tekst[1] = 'b';
    tekst[2] = 'r';
    tekst[3] = 'a';
    tekst[4] = '\0';
    printf("%s\n", tekst);
    free(tekst);
    return EXIT_SUCCESS;
}
```

### Oppgave 4.2
```c
int main(void) {
    int *peker;
    peker = malloc(sizeof(int));
    *peker = 10;
    printf("pekeren peker på adressen %p\n", peker);
    printf("pekeren ligger på adressen %p\n", &peker);
    *peker += 5;
    free(peker);
    return 0;
}
```
##### Kommentar:
`peker` og `&peker` har helt forskjellige verdier. Grunnen til det er at `peker` peker på en minneadresse vi fikk fra `malloc` og  peker dermed på et sted på heapen, mens `&peker` er adressen hvor variabelen `peker` ligger, som er på stacken. Her kan vi altså se at heapen og stacken ligger på veldig forskjellige steder.

### Oppgave 4.3
```c
char *getCopy(char *original){
    char *copy = malloc(strlen(original) + 1); // gjort om
    for(int i = 0; i < strlen(original) + 1; i++){
        copy[i] = original[i];
    }
    return copy;
}

int main() {
    char *string = "Alle Cbraer vil ha kopier!";
    char *stringkopi = getCopy(string);
    free(stringkopi); // lagt til
    return 0;
}
```
##### Kommentarer:
Her er eneste forskjellen at vi bruker `malloc` istedenfor å opprette et array. Grunnen til at vi må gjøre det slik er at arrayet opprettes på stacken og kan overskrives senere. Mange kompilatorer vil også automatisk gjøre pekeren til et slikt array til `NULL`, og i andre tilfeller vil det som ligger der overskrives av andre funksjoner. Dermed er det bedre å bruke `malloc` som reserverer plass på heapen, et sted som aldri vil bli overskrevet. Men da er det viktig å huske å frigjøre minnet når vi er ferdig med det :)

### Oppgave 4.4
```c
int main(void) {
    char *str = malloc(4);
    str[0] = 97;
    str[1] = 98;
    str[2] = 99;
    str[3] = 0;
    printf("%s\n", str);
    free(str);
    return 0;
}
```

### Oppgave 4.5
```c
int *gangetabell(int base) {
    int i, *tabell;

    tabell = malloc(10 * sizeof(int));
    for (i = 1; i <= 10; i++) {
        tabell[i-1] = base * i;
    }

    return tabell;
}

int main(void) {
    int i, j, *tabell, baser[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 42, 1337};

    for (i = 0; i < 12; i++) {
        tabell = gangetabell(baser[i]);
        printf("Tabell med base %d:\n", baser[i]);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabell[j]);
        }
        printf("\n");
        free(tabell);
    }
}
```

### Oppgave 4.6
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *copy_array(int array[], int length) {
    int *copy = malloc(sizeof(int) * length);
    memcpy(copy, array, length * sizeof(int));
    return copy;
}

int main(int argc, char const *argv[]) {
    int original[] = {1, 2, 3, 4, 5, 6, 7};
    int *copy = copy_array(original, 7);

    for (int i = 0; i < 7; i++) {
        printf("%d\n", copy[i]);
    }

    free(copy);
    return 0;
}
```

##### Kommentarer:
Her har vi brukt `memcpy` istedenfor å kopiere over ett og ett element med en for-løkke. `memcpy` kopierer et visst antall bytes (i dette tilfellet `sizeof(int) * length`) fra ett minneområde (`array`) til et annet (`copy`).
Vi må også huske å frigjøre minnet med `free` når vi er ferdige med det, men vi er ikke ferdige med det før vi har skrevet ut tallene i `main`. Når en funksjon returnerer en peker til et minneområde allokert med `malloc`, er det opp til den funksjonen som kaller på den å frigjøre minnet.

