# Uke 3
Her finner du oppgaver om strenger og heap-allokering ved bruk av `malloc`.

- [Opptak fra ukens Cbra](https://youtu.be/dmvxEkLoLuM).

## Her er linker til denne ukens oppgaver
#### Makefile [\[link\]](#makefile)
#### Funksjoner i C [\[link\]](#funksjoner)
#### Argumenter til C-programmer [\[link\]](#argumenter-til-programmer)
#### Sizeof [\[link\]](#sizeof)
#### Malloc [\[link\]](#malloc)

## Makefile
### Oppgave 0.1
```makefile
min_fil:
    gcc -g -std=gnu11 min_fil.c -o min_fil
```

Denne makefilen så ut til å fungerer første gangen den kjørte. Dessverre ville den ikke kompilere mer enn en gang, selv ikke etter at `min_fil.c` ble forandret. Skriv om makefilen slik at den alltid kompilerer dersom `min_fil.c` blir endret (men ikke ellers).

Hint: Se Cbra-videoklipp om makefiler [her](https://youtu.be/fsWidNIjxLs?t=149)

## Funksjoner
### Oppgave 1.1
- Slå opp funksjonen `strlen` med man (skriv: `man 3 strlen`) og se hva den gjør.
- Lag en funksjon som tilsvarer `strlen` (men uten å bruke den)

### Oppgave 1.2
Skriv en funksjon som tar inn to char arrays.
Funksjonen skal kopiere ett og ett element fra det ene arrayet inn i det andre.
Ikke lov å bruke biblioteksfunksjoner :))

## Argumenter til programmer
Argumenter til programmer i C legges i det andre parameteret til main-funksjonen som typisk er kalt `char const *argv[]`. Antall argumenter ligger i det første parameteret, typisk kalt `int argc`.

### Oppgave 2.1
Lag et program som tar inn tre argumenter, og skriver dem ut. Gi en feilmelding dersom mindre enn tre argumenter er oppgitt.

Eksempel på kjøring:
```
$ ./my_file Cbra gir glede
-> arg1: 'Cbra', arg2: 'gir', arg3: 'glede'
$ ./my_file Ikke nok
-> Error: trenger tre argumenter.
```

### Oppgave 2.2
- Lag et program som tar inn en bokstav som argument.
- Skriv ut bokstaven som kommer *etter* input-bokstaven i alfabetet
- Skriv ut en feilmelding til brukeren dersom det første argumentet er lengre enn ett tegn (en bokstav).

Eksempel på kjøring:
```
$ ./my_file a
-> b
$ ./my_file G
-> H
$ ./my_file hei
-> Error: input må være bare en bokstav
```

### Oppgave 2.3
- Last ned og kompiler filen argv_1.c
- Kjør programmet på en måte som gjør at `Cbra!` printes ut.
- (Obs: Du skal ikke endre på programmet)

## Sizeof
`sizeof()` i C fungerer *ikke* som f.eks `len()` i python, og burde kun brukes for å sjekke størrelsen på datatyper.

### Oppgave 3.1
- Bruk `sizeof()` til å finne størrelsen til en float.
- Bruk `sizeof()` til å finne størrelsen til en peker.

### Oppgave 3.2
- Opprett et array med 50 plasser, og print resultatet av å bruke `sizeof` på variabelen som holder arrayet. Hva kommer ut?
- Skriv en funksjon som tar inn et array, og skriver ut resultatet av å kalle `sizeof` på det. Send inn arrayet som du opprettet fra forrige punkt. Hva skrives ut nå?

## Malloc
### Oppgave 4.1
- Hvor mange bytes må vi allokere til strengen `Cbra`?
- Se på filen malloc_1.c. Hva er problemet med dette programmet?

### Oppgave 4.2
- Deklarer en int peker.
- Initialiser pekeren med et kall på malloc (du trenger plass til én int).
- Følg pekeren og sett verdien der den peker til 10.
- Print ut adressen som pekeren peker på ved å bruke `%p` i `printf`.
- Print ut adressen til selve pekeren. Er det stor forskjell på dem? Ligger de på samme sted?
- Følg pekeren, og øk verdien den peker på med 5.
- Bruk free() til å frigjøre minnet du fikk fra malloc.
- Kjør programmet med `valgrind` og sørg for at du ikke har noen minnefeil.
- Hint: `man 3 malloc`, `man 3 free`

### Oppgave 4.3
- Last ned filen malloc_2.c
- Skriv om funksjonen `getCopy(char *original)` slik at den fungerer som den skal.
- HINT: Det kan være lurt aa bruke `malloc()`

### Oppgave 4.4
- Lag et c-program hvor du bruker `malloc` til å allokere et minneområde på 4 bytes.

- Fyll den første byten med verdien 97.
- Den andre med verdien 98
- Den tredje med verdien 99
- Den siste med en null-byte

- Bruk `printf` til å printe en streng fra starten av minneområdet.

### Oppgave 4.5
- Skriv en funksjon `int *gangetabell(int base)` som:
    - Oppretter en int peker.
    - Initialiserer pekeren med et kall på malloc og gjør plass til 10 `int`er.
    - Fyller minneområdet med produktene av å multiplisere `base` med tallene 1-10 (inklusiv).
    - Returnerer pekeren
- Kall funksjonen `gangetabell` med argumentene 1-10, samt `42` og `1337` og skriv ut resultatene.
- Husk å frigjøre minnet du brukte.
- Kjør programmet med `valgrind` og sørg for at du ikke har noen minnefeil.

### Oppgave 4.6
Skriv en funksjon som tar inn et int array, samt lengden på arrayet.
Funksjonen skal bruke malloc til å allokere plass til et nytt array med samme størrelse, kopiere over hvert element fra det opprinnelige arrayet og returnere det nye arrayet.

## Structs
### Oppgave 5.1
- Opprett en `struct tall`, som inneholder en int tall.
- Opprett en instans av `struct tall`, print ut tallet den inneholder!

### Oppgave 5.2
- Opprett en `struct person`, med `int alder` og `char[et stort nok tall]` navn (evt `char *navn`). Opprett instans av `struct person`, gi den en alder og et navn.
- Print ut navn og alder
- Er det noen forskjell på om du brukte `char[et stort nok tall]` navn, eller `char *navn`?

### Oppgave 5.3
- Opprett en `struct bil`, gi den de "egenskapene" du vil.
- Opprett et `struct bil`-array.
- Skriv en funksjon som tar inn et `struct bil` array (og eventuelle andre parametere), og fyller arrayet med bil-structer.