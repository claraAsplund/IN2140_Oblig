# Uke 4
Her finner du oppgaver om structs og minnefeil.

- [Opptak fra ukens Cbra](https://www.youtube.com/watch?v=pLFEds_SXjs&t=5s).  

Her finner du lenkelisten vi skrev i ukens gruppetime.   

- [Lenkeliste](/gruppe-2/Uke4/Lenkeliste)

Prøv gjerne å skrive funksjonen 

```c
void pop();
``` 

## Snarveier
#### [Repetisjon om pekere](#repetisjon)
#### [Oppgaver om structs](#structs)
#### [Oppgaver om minnefeil](#minnefeil)

## Repetisjon
### Oppgave 1.1
- Deklarer en int-peker.
- Initialiser pekeren ved bruk av malloc. Pekeren skal ha plass til 10 int'er.
- Husk å kall på `free` når du ikke trenger pekeren lenger :)

### Oppgave 1.2
- Skriv en funksjon som tar inn et int-array, og fyller arrayet med valgfrie verdier.
- Kall på funksjonen med pekeren fra oppgave 1.1 som argument.
- Print ut verdiene etter funksjonskallet.
- Husk å kall på `free` når du ikke trenger pekeren lenger :)

### Oppgave 1.3
- Skriv en funksjon som tar inn et array av char-pekere (strings). Hint: Hva er det main ofte tar inn som parameter?
- I funksjonen:
    - Bruk malloc til å allokere plass til hvert element i arrayet.
    - Deretter bruker du en valgfri metode for å legge inn en string på hver plass (du kan f eks lage en string på forhånd og kopiere den over på alle plassene).
    - Strukturen skal se slik ut:
```
char *array[] inneholder:
            array[0] ---> "en streng"
            array[1] ---> "en streng"
            ...
            array[i] ---> "en streng"
```
Hint: For å kopiere strengen over, sjekk ut f.eks `man 3 memcpy`. Evt bruk en loop.

## Structs
### Oppgave 2.1
- Opprett en `struct tall`, som inneholder en int tall.
- Opprett en instans av `struct tall`, print ut tallet den inneholder!

### Oppgave 2.2
- Opprett en `struct person`, med `int alder` og `char[et stort nok tall]` navn (evt `char *navn`). Opprett instans av `struct person`, gi den en alder og et navn.
- Print ut navn og alder
- Er det noen forskjell på om du brukte `char[et stort nok tall]` navn, eller `char *navn`?

### Oppgave 2.3
- Opprett en `struct bil`, gi den de "egenskapene" du vil.
- Opprett et `struct bil`-array.
- Skriv en funksjon som tar inn et `struct bil` array (og eventuelle andre parametere), og fyller arrayet med bil-structer.

## Minnefeil

### Oppgave 3.1
- Last ned filen `malloc_og_struct.c`.
- Hvor stor (hvor mange bytes) er `struct person`?
- Endre funksjonen kostruerPerson() slik at den fungerer.

### Oppgave 3.2
- Last ned filen `free_1.c` og kjør den.
- Prøv i finne ut hvorfor vi får segmentation fault.
- Rett opp i koden slik at vi ikke lenger får feilen.

### Oppgave 3.3
- Last ned filen `sang.c` og kjør med valgrind
- Hvorfor får vi memory leaks?
- Skriv funksjonen `void free_sang` som tar inn en sang-peker og free-er structen slik at vi ikke får memory leaks
- HINT: bruk valgrind med valget `--leak-check=full` for å se hvor minne blir allokert.

### Oppgave 3.4
```c
struct event {
    char *navn;
    int prioritet;
    char beskrivelse[20];
};
```

- Skriv en funksjon `create_event` som tar inn `char *navn`, `int prioritet` og `char *desc`, og som returnerer `struct event *` (en peker)
    - Opprett en `struct event` i funksjonen og fyll den med verdien til parameterne. Returner pekeren til structen.
- Skriv en ny funksjon som tar inn en peker `struct event *`, og som skriver ut verdiene til structen
- Sørg for at det ikke er noen minnelekasjer under programmet (test med valgrind)
- Ekstra: Sørg for at programmet aldri krasjer uansett input til `create_event`-funksjonen

Eksempel på kjøring:

```c
int main() {
    struct event *cbra, *plenum;

    cbra = create_event("Cbra", 10, "Ukens hoydepunkt!");
    plenum = create_event("Plenum", 9, "Gjennomgang av viktige temaer");

    print_event(cbra); // -> "Navn: Cbra. Prioritet: 10. Beskrivelse: Ukens hoydepunkt!"
    print_event(plenum); // -> "Navn: Plenum. Prioritet: 9. Beskrivelse: Gjennomgang av vikt"

    // Trengs noe mer?
}
```

# Bonus-nøtt!
### Memory leaks
Først: last ned filene i `memleak`-mappen (`makefile` og `memleak.c`)

I denne oppgaven er det førstemann til å finne og rette alle feilene i `memleak.c`!
Her er noen hint for oppgaven:
- Det finnes tre ulike feil
    - Kanskje forekommer noen flere ganger?
- Bruk Valgrind til å finne ut hva slags feil som finnes, og hvor de forekommer
- Kompiler filene med flagget `-g` for å vise linjenummer i valgrind
- Kjør valgrind med flagget `--track-origins=yes` for å få mer informasjon om feilene
- Kjør valgrind med flagget `--leak-check=full` for å få mer informasjon om minnelekasjene
    - For å gjøre ting enklere, legg til disse flaggene i makefilen

