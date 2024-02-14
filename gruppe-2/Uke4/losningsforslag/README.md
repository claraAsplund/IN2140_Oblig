# Løsningsforslag for uke 4

### Oppgave 1.1
```c
int main() {
    int *p;
    p = malloc(sizeof(int) * 10);
    free(p);
    return 0;
}

```
****
### Oppgave 1.2
```c
void fyllArray(int *array, int lengde){
    for (int i = 0; i < lengde; i++) {
        array[i] = i * i;
    }
}

int main() {
    int *p = malloc(sizeof(int) * 10);
    fyllArray(p, 10);

    for (int i = 0; i < 10; i++) {
        printf("plass %d: %d\n", i, p[i]);
    }

    free(p);
    return 0;
}
```
****

### Oppgave 1.3
```c
void alloc_strings(char *strs[], int lengde){
    char *valgfri_streng = "Cbra! Hver tirsdag kl 12:15!";
    int alloc_size = strlen(valgfri_streng) + 1; // +1 for null-byte

    for (int i = 0; i < lengde; i++) {
        strs[i] = malloc(sizeof(char) * alloc_size);
        strcpy(strs[i], valgfri_streng);
    }
}

int main() {
    char *strs[10];
    alloc_strings(strs, 10);

    for (int i = 0; i < 10; i++) {
        printf("%s\n", strs[i]);
        free(strs[i]);
    }

    return 0;
}
```

Kommentarer:
- Vi allokerer alltid 1 plass mer enn verdien ``strlen`` returnerer. Dette er fordi ``strlen`` ikke teller med nullbyten.
- Her kunne vi også brukt `memcpy` eller kopiert over ett og ett tegn i en løkke.
****

### Oppgave 2.1
```c
struct tall {
    int number;
};

int main(void) {
    struct tall mitt_tall;
    mitt_tall.number = 7;
    printf("Tallet er %d\n", mitt_tall.number);
    return 0;
}
```
##### Kommentar:
Dersom vi ikke setter `number` før vi printer, er det tilfeldig hvilket tall som kommer opp.

****

### Oppgave 2.2
```c
struct person {
    int alder;
    char *navn;
};

int main(void) {
    struct person pers;
    pers.alder = 39;
    pers.navn = "Olav";

    printf("%s er %d år\n", pers.navn, pers.alder);
    return 0;
}
```
##### Kommentar:
Dersom `navn` er et array istedenfor en `char *`, ville selve strengen ligget i structen istedenfor bare en peker til den. Da måtte man også kopiert over en og en byte, enten selv eller med f.eks `strcpy`, og man måtte passet på at arrayet er stort nok.

****

### Oppgaver 2.3
```c
struct bil {
    int hjul;
    int kilometerstand;
    char *merke;
};

void init_cars(struct bil arr[], int length) {
    for (size_t i = 0; i < length; i++) {
        arr[i].hjul = 4;
        arr[i].kilometerstand = 0;
        arr[i].merke = "Toyota";
    }
}

int main(void) {
    struct bil garasje[10];
    init_cars(garasje, 10);
    printf("%s\n", garasje[5].merke);
    return 0;
}
```
##### Kommentarer:
Vi må vite hvor mange elementer vi har i `arr`, og sender dermed inn lengden på arrayet også.

Merk også at `struct bil array[2]` er det samme som å opprette to instanser av `struct bil`. Dermed kan man lese og forandre på alle elementene i arrayet direkte (men dersom du leser før noe er satt, er det tilfeldig hva som ligger der). Dette er til forskjell fra f.eks java, hvor et `new Bil[10]`-array egentlig er et array av 10 pekere initialisert til `null`.

****

### Oppgave 3.1
```c
#include <stdio.h>
#include <stdlib.h>

struct person {
    unsigned char alder;
    char *navn;
    unsigned long fnr;
};

struct person *kostruerPerson(char *navn, unsigned char alder, unsigned long fnr) {
    struct person *ny = malloc(sizeof(struct person));
    ny->alder = alder;
    ny->navn = navn;
    ny->fnr = fnr;
    return ny;
}

void printPerson(struct person *pers) {
    printf("Navn: %s\nalder: %u\nfodselsnummer: %lu\n",
                pers->navn, pers->alder, pers->fnr);
}

int main() {
    printf("sizeof(struct person) = %ld\n", sizeof(struct person));

    struct person *magnus = kostruerPerson("Magnus", 29, 11019112345);
    printPerson(magnus);
    free(magnus);

    return 0;
}
```

##### Kommentarer:
Ved å skrive ut størrelsen til structen ved `printf("%ld\n", sizeof(struct person));` finner vi ut at structen er 24 bytes stor. Dette er fordi kompilatoren legger til 'padding' slik at ting skal gå fortere. Uansett kan det være vanskelig å vite hvor stor en struct er bare ved å se på egenskapene siden man aldri har helt kontroll over hva kompilatoren gjør, og man burde dermed bruke `sizeof` for å sjekke størrelsen.

Når man kjører programmet, får man sannsynligvis en segmentation fault. Det er fordi vi returnerer adressen til en tidligere lokal variabel fra en funksjon som lå på stacken. Dette er ikke trygt da slike verdier kan bli overskrevet når man gjør andre funksjonskall som overskriver verdien som lå på stacken. Generelt sett må man bruke `malloc`, eller en funksjon som bruker `malloc`, når man vil returnere en peker til et minneområde som man allokerer i funksjonen.

****

### Oppgave 3.2
Her er det originale programmet:
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getAllocatedString(char *s){
    char *str = malloc(strlen(s) + 1);
    strcpy(str, s);
    return str;
}

int main(int argc, char const *argv[]) {
    char *s = getAllocatedString("Hello, World!");

    int lengde = strlen(s);
    for (int i = 0; i < lengde; i++) {
        printf("%c", *(s++));
    }
    printf("\n");

    free(s);
    return 0;
}
```

- Merk at vi printer ved å printe hver bokstav i en løkke.
- Når vi gjør det flyttes pekeren ``s`` fremover.
- Til slutt er ``s`` kommet helt til nullbyten.
- Når vi så kaller free, peker ikke `s` på samme adresse som malloc returnerte.

Vi kan løse oppgaven ved å bytte ut løkken med et vanlig kall på printf. Men hva om vi ønsker å printe i en løkke?

Svaret er enkelt! Vi lager ny peker før løkken som starter  med å peke på samme sted som `s`. Denne kan flyttes fremover uten at det går utover `s`.

Løsning:
```c
char *getAllocatedString(char *s){
    char *str = malloc(strlen(s) + 1);
    strcpy(str, s);
    return str;
}

int main() {
    char *tmp, *s = getAllocatedString("Hello, World!");

    int lengde = strlen(s);
    tmp = s;
    for (int i = 0; i < lengde; i++) {
        printf("%c", *(tmp++));
    }
    printf("\n");

    free(s);
    return 0;
}
```
****
### Oppgave 3.3

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sang{
    char *artist;
    char *tittel;
    int lengde_sec;
};

void fyll_sang(struct sang *s, char *artist, char *tittel, int lengde){
    s->lengde_sec = lengde;
    s->tittel = strdup(tittel);
    s->artist = strdup(artist);
}

void print_sang(struct sang *s){
    printf("*********************************\n");
    printf("\tArtist:\t%s\n", s->artist);
    printf("\tTittel:\t%s\n", s->tittel);
    printf("\tLengde:\t%d\n", s->lengde_sec);
    printf("*********************************\n");
}

void free_sang(struct sang *sang) {
    free(sang->tittel);
    free(sang->artist);
    free(sang);
}

int main() {
    struct sang *min_sang = malloc(sizeof(struct sang));

    fyll_sang(min_sang, "Adele", "Skyfall", 220);
    print_sang(min_sang);

    free_sang(min_sang);
    return 0;
}
```
**Kommentarer:**
- Funksjonen `strdup` allokerer plass til en ny streng med `malloc`, og kopierer den (inkludert nullbyten) til det nye minneområdet.
- Den originale versjonen frigjorde ikke minnet som ble allokert med `strdup`. Dette gjør vi nå i `free_sang`!
- Merk at vi må frigjøre de to strengene *før* vi kan frigjøre selve sang-structen ettersom vi ikke kan bruke en peker etter den er frigjort.
****
### Oppgave 3.4

```c
struct event {
    char *navn;
    int prioritet;
    char beskrivelse[20];
};

void print_event(struct event * e){
    printf("\n********EVENT********\n");
    printf("Navn:        %s\n", e->navn);
    printf("Prioritet:   %d\n", e->prioritet);
    printf("Beskrivelse: %s\n", e->beskrivelse);
    printf("*********************\n\n");
}

struct event *create_event(char *navn, int prioritet, char *desc) {
    struct event *e = malloc( sizeof(struct event) );
    e->navn = navn;
    e->prioritet = prioritet;
    int lengde = (( strlen(desc) >= 19 ) ? 19 : strlen(desc) + 1 );
    strncpy(e->beskrivelse, desc, lengde);
    e->beskrivelse[19] = '\0';
    return e;
}

int main() {
    struct event *cbra, *plenum;

    cbra = create_event("Cbra", 10, "Ukens hoydepunkt!");
    plenum = create_event("Plenum", 9, "Gjennomgang av viktige temaer");

    print_event(cbra); // -> "Navn: Cbra. Prioritet: 10. Beskrivelse: Ukens hoydepunkt!"
    print_event(plenum); // -> "Navn: Plenum. Prioritet: 9. Beskrivelse: Gjennomgang av vikt"

    free(cbra);
    free(plenum);
    return 0;
}
```
**Kommentarer:**
- Merk at vi ikke bare kan si at `e->beskrivelse = ...`. Vi kan aldri å endre selve pekeren til et array, kun innholde (altså det som blir pekt på).
- Dersom `strlen` av lengden til beskrivelsen overstiger 19 har vi ikke plass til strengen med nullbyte. I denne løsningen bruker vi funksjonen `strncpy` til å velge et maks-antall bokstaver som skal kopieres til arrayet vårt. Dersom lengden er mindre enn 19, vil nullbyten også kopieres. Vi setter uansett en null-byte på indeks 19 slik at strengen er null-terminert selv om strengen er lengre enn 19 bytes stor.
****

### Memory leaks
De ferdige filene ligger under `makefile` og `memleak.c` i denne mappen, men her er en gjennomgang av oppgaven.
- Når vi kompilerer og kjører får vi ut noen utskrifter og til slutt en segmentation fault. I denne oppgaven er det ikke viktig å vite hva programmet egentlig gjør, bare å finne feilene som valgrind klager på og rette opp i dem på en fornuftig måte.
- Først setter vi inn de nyttige flaggene i makefilen, slik som ble foreslått i oppgaven.
- Når vi nå skriver `make check` kjøres programmet med valgrind og alle flaggene. La oss starte på toppen med den aller første feilen vi får: `Conditional jump or move depends on uninitialised value(s)`.
    - Dette vil si at vi har brukt en variabel uten å si hva den skal være (initialisert den). F.eks når vi skriver `int a;` vil `a` sin verdi være hva som å på stacken på det tidspunktet, altså en tilfeldig verdi. Dette vil føre til at programmet kan oppføre seg forskjellig fra gang til gang, og skape frustrerende debugging-situasjoner siden slike feil kan være vanskelige å gjenskape.
    - Vi løser altså problemet ved å sette en slik variabel til en start-verdi. Men hvilken variabel er det snakk om?
    - På linjen under finner vi mer informasjon: `at 0x4E4AEB8: sqrt (w_sqrt_compat.c:30)` (adressen kan variere).
    - Vi ser at på linje 30 i filen `w_sqrt_compat.c` brukes denne variabelen. Men dette er ikke en fil vi har skrevet selv, så vi må lengre ned i call-stacken for å finne svaret. La oss se på neste linje.
    - ` by 0x1087FD: daarlig_funksjonsnavn_1 (memleak.c:7)`. Så linje 7 i funksjonen `daarlig_funksjonsnavn_1`. Dette har vi kontroll på! Der ser vi at vi kaller funksjonen `sqrt` med en verdi basert på variabelen `x`. Ettersom dette er den eneste variabelen her, må det være den som er uinitialisert. Men den tas jo inn som et parameter? Da må vi lengre ned i call-stacken for å se hvor variabelen kommer fra.
    - `by 0x10886D: daarlig_funksjonsnavn_2 (memleak.c:21)`. Her ligger svaret! Vi ser at funksjonen `daarlig_funksjonsnavn_1` kalles med variabelen `val`, og selv om den "settes" på samme linje så skjer ikke dette før funksjonskallet er ferdig. Dermed vil denne verdien være uinitialisert i første gjennomgang av løkken. Dersom vi setter `val = 1` over, løser vi dette problemet.
- Nå får vi ingen feil før utskriftene av "superverdiene" kommer, men etterpå får vi en annen type feil: `Invalid free() / delete / delete[] / realloc()`
    - En slik feilmelding kommer når vi prøver å bruke en av funksjonene over på en "ugyldig" peker.
    - Fra neste linje `at 0x4C30D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)` ser vi at det gjelder et kall på funksjonen `free`
    - Neste linje `by 0x108954: daarlig_funksjonsnavn_3 (memleak.c:39)` sier hvor vi har gjort dette ugyldige kallet: linje 39.
    - Her ser vi at vi prøver å frigjøre minnet pekt på av variabelen `dup`.
    - I `daarlig_funksjonsnavn_3` kopierer vi en og en byte fra `str` til `dup`, som er allokert med `malloc`. Men måten dette er gjort på er ved å skrive `*dup++ = *str++;`. Dette fungerer fint, og flytter pekeren til både `dup` og `str` en byte lengre frem for hver gjennomgang av løkken. Problemet er at vi ikke har en referanse til den originale pekeren når vi er ferdig. I dette tilfellet brukes heller ikke pekeren til noe fornuftig. Dette vil altså si at når vi skriver `free(dup)`, så peker ikke lenger `dup` til det samme minneområdet, men til slutten av minneområdet.
    - Dette kan løses på flere måter. En kunne vært å opprette en teller `i` som plusses på med 1 hver runde, og erstatte `*dup++` med `*(dup + i++)`. Da forandrer man ikke på pekeren, og `free` vil fungere som vanlig. I løsningsforslaget har vi brukt en annen måte, som er å opprette en `char *tmp` som peker på det samme minneområdet som `dup`. Dermed kan vi forandre så mye vi vil på `dup`, og heller skrive `free(tmp)` istedenfor.
- Når dette er løst, står vi bare igjen med en siste feil: memory leaks. Under `LEAK SUMMARY` ser vi linjen `definitely lost: 314,216 bytes in 807 blocks`, som vil si at vi har noen ganske alvorlige memory leaks.
    - Også her gir valgrind oss en stack-trace slik at vi kan se hvor feilen kommer fra. Under `314,216 bytes in 807 blocks are definitely lost in loss record 1 of 1` får vi mer informasjon.
    - `at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)` sier at minneområdene som lekkes er allokert med `malloc`
    - `by 0x10881F: daarlig_funksjonsnavn_4 (memleak.c:11)` gir oss hvor i programmet vi har gjort dette kallet på `malloc`: linje 11.
    - Riktig nok allokerer vi minne på linje 11, men pekeren til dette minnetområdet returneres. Dermed er det opp til den som kaller funksjonen å frigjøre det. Vi kan følge call-stacken videre for å se hvem som gjorde det.
    -  `by 0x108881: daarlig_funksjonsnavn_2 (memleak.c:22)`. På linje 22 ser vi at peker-variabelen `sup` settes til å peke på det som returneres av `daarlig_funksjonsnavn_4`. Lengre nede i funksjonen ser vi at det gjøres et kall på `free(sup)`, men dette skjer utenfor for-løkken. Altså er det kun minnet som allokeres den siste gangen som blir frigjort. For å løse dette kan vi flytte opp dette kallet slik at den frigjør *i* løkken. Da vil programmet frigjøre minnet før pekeren til det minnet overskrives med pekeren til et annet.
- Kjører vi programmet igjen med valgrind nå, får vi nederst se meldingen `All heap blocks were freed -- no leaks are possible`. Dette er målet når man retter opp i minne-feil, og programmet kjører nå fint. Helt nederst kan vi også se `ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)`, altså har valgrind ingen flere klager til oss :)
