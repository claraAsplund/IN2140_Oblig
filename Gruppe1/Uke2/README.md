## Oppgave 1.1
Skriv en main-funksjon som skriver ut "Hello world!" til terminalen.
Skriv en funksjon print_hello() som gjør det samme. Kall denne funksjonen fra main.
Er det noen forskjell på om print_hello() ligger over/under main?

## Oppgave 1.2
Lag en enkel Makefile som kompilerer koden din.

## Oppgave 1.3
Dersom du jobber på egen maskin: kopier makefilen og kodefilen du lagde i 1.1 og 1.2 til IFI. Fjerninlogg så på IFI og kompiler og kjør koden der.

## Oppgave 2.1
Deklarer et int-array med plass til 100 elementer uten å initialisere det (uten å "fylle" det). Print det ut med en vanlig for-løkke. Ble utskriften som du forventet? Hvorfor/hvorfor ikke?

## Oppgave 2.2
Deklarer et int array a, og initialiser det med verdier fra 0 til 9 (på hvilken måte du vil).
Endre verdi på plass 5 til 1337.
Print ut arrayet.

## Oppgave 2.3
Deklarer og initialiser et char-array navn (f eks med navnet ditt).
Deklarer et nytt char-array med samme lengde.
Kopier det som ligger i navn over i det andre arrayet.

## Oppgave 2.4
```
int *p;
*p = 3;
```
Kodesnutten over vil føre til segmentation fault. Hvorfor det?

## Oppgave 2.5
Opprett en char a og en int b
Print ut størrelsen til a og b ved å bruke operatoren sizeof()
Lag så en char-peker p og en int-peker q
Print ut størrelsen til p og q på samme måte som sist.

## Oppgave 2.6
Opprett en int a = 5
Opprett en int-peker b som peker på a
Print ut både a og verdien som b peker på (målet er å få ut 5 begge gangene). Hint: hvordan "følge" en peker dit den peker? Dereferencing

## Oppgave 2.7
Skriv en funksjon void increase som tar inn en int-peker, og øker verdien den peker på med 1.
Lag så en int-variabel som du initialiserer til 42.
Send inn pekeren til variabelen som argument til funksjonen increase.
Print ut variabelen. Har den endret seg?
Hva er forskjellen på funksjonen increase om den tar inn en int-peker eller en "vanlig" int?

## Oppgave 2.8
Lag en funksjon som tar inn en int-peker og et tall, og setter det pekeren peker på til input-tallet.

## Oppgave 3.1
Skriv en funksjon som tar inn et array (f eks med int'er), og printer ut alle elementene.
Hvordan vet du når du har kommet til slutten av arrayet? Må funksjonen ta inn flere parametere?

## Oppgave 3.2
Opprett en streng med de verdiene du vil.
Bruk en løkke til å gå gjennom strengen, og print ut hver bokstav.
Istedenfor å indeksere strengen på vanlig vis (f.eks min_streng[i]), bruk dereferencing (*) til å hente ut bokstavene.
Hvordan vet løkken at enden på strengen er nådd? Kan man slippe unna å huske på lengden til strengen? Hint: hvilket symbol skal en streng alltid ende med?