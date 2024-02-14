* Oppgaver

** Tekstfiler

*** Oppgave 1.1
Åpne filen =text.txt= med =fopen()=, du skal åpne den i lese-modus. Opprett et
buffer (et char-array i dette tilfellet) med stor nok størrelse (ok å lage et
stort array!). Bruk =fread()= til å lese en og en byte fra filen inn i bufferet,
helt til returverdien av =fread()= er 0. Husk å lukke filen når du er ferdig med
den! \\
Hint: =man fopen=, =man fread=, =man fclose=, veldig viktig å lese på argumenter og
returverdi!

*** Oppgave 1.2
Forts. oppgave 1.1 Åpne en ny fil i skrivemodus (bruker du =fopen= med "w" som
andre argument, opprettes det en ny fil (dersom en fil med samme filnavn ikke
finnes)).

Skriv resultatet fra oppgave 1.1 inn i filen, men skriv ditt eget navn
istedenfor "name"! Her kan du skrive en og en byte (dvs en og en char) fra
bufferet fra oppgave 1.1, helt til du kommer til "name". Hint: =man fwrite=.
Hvordan vet du at du har kommet til "name", og skal sette inn ditt eget navn?
Når du skal legge inn ditt eget navn, må du skrive inn en og en byte? Eller kan
du gjøre det i en operasjon? ;)

*** Oppgave 1.3
Åpne en fil (f.eks fra oppgave 1.1 eller 1.2, eller skriv en helt nye en) som har noe innhold.
Denne gangen skal den åpnes i modus "r+", dette gir deg både skrive- og lese-rettigheter.
Les først filens innhold inn i et buffer (slik som i oppgave 1.1).

Når du skriver/leser fra fil, flyttes fil-pekeren (pekeren du mottar fra =fopen=)
etterhvert som du beveger deg i filen. Når du har lest alt fra filen inn i
bufferet, vil fil-pekeren peke til slutten av filen. Flytt nå pekeren til
starten av filen igjen! Hint: =man fseek=

Nå skal du overskrive filen med bufferet, men baklengs!
Hvis filen så slik ut:

=Hello Ole!=

Skal den etterpå se slik ut:

=!elO olleH=

** Binærfiler

*** Oppgave 2.1
- Bruk =xxd= til å se på filen =tall.numbers=. Klarer du å se at det ligger 10 4-byte integers på rad her?
- Opprett et array med plass til 10 integers.
- Åpne filen =tall.numbers= (bruk "rb" som modus).
- Les inn tallene fra =tall.numbers= inn i arrayet.
- Skriv ut hvert tall på hex-format
    - Hint: Bruk =%x= i =printf=.

*** Oppgave 2.2

#+begin_src c
struct zebra {
    unsigned char number_of_legs;
    unsigned int number_of_stripes;
};
#+end_src

I filene =zebra_legs= og =zebra_stripes= er det skrevet inn informasjon om 4 zebra-structer. For å se på filene, skriv kommandoen =xxd filnavn=.

Lag et program som:

1. Åpner filene (bruk "rb" som modus)
2. Leser inn ett og ett element fra hver fil. (OBS! =zebra_legs= inneholder =char=, mens =zebra_stripes= inneholder =int=)
3. Opprett en =struct zebra= for hvert element, og sett =number_of_legs= og =number_of_stripes= til de leste verdiene.
4. Multipliser =number_of_legs= med 10, og halver antall =number_of_stripes=.
5. Skriv informasjon om de muterte zebraene inn i en ny fil (bruk "wb" som modus når du åpner den).
    - Den nye filen skal inneholde først en byte for den første structen sin =number_of_legs=, så fire bytes for =number_of_stripes=, og tilsvarende for de andre structene.

* Bonus-nøtt!
Den zoologiske etterretningstjenesten har mottat en hemmelig melding, og trenger *DIN* hjelp for å lese den!

Filen =secret= inneholder en hemmelig melding, formatert på et spesielt format:
- Den første byten i filen er *offset* til det første ordet i meldingen, altså
  hvor mange bytes *fra toppen av filen* dette ordet befinner seg.
- Slik som i C, slutter hvert ord med en null-byte
- Etter hver null-byte ligger en byte som beskriver offset *fra toppen av filen*
  til neste ord
- Dersom offset til neste ord er lik 0, er setningen ferdig.
- Ettersom en byte maks kan representere tall fra 0-255, kan du anta at et
  offset aldri vil være større enn 255

Hint:
- Husk at nå jobber du med binær-filer! Bruk "rb" som mode når du åpner filen
  (man fopen)
- Se på funksjonen =fseek()=, den vil gjøre offsets enklere (=man fseek=)
- Du kan anta at ingen ord i filen er større enn 12 bytes.
- Bruk kommandoen =xxd= for å lese binærfilen.
- Det er mange måter å løse denne oppgaven på. Her er det bare å ta kreativiteten fatt!

****** Eksempel:

I filen secret_sample ligger en fil som har enkodet setningen "The end" på samme format.
Ved å inspisere filen med =xxd=, får vi følgende output:

#+begin_src
0b65 6e64 0000 6e6f 7400 0654 6865 0001  .end..not..The..
#+end_src

Her ser vi at første byten er 0b (hex for 11), og på byte nr 11 (starter på 0)
ligger bokstaven T, eller hex-verdien 54 som tilsvarer T i ASCII-tabellen.
Etterpå ligger 0x68 (h) og 0x65 (e), og så kommer en null-byte. Byten etterpå
beskriver hvor neste ord befinner seg i filen, og det tallet er 0x01, altså på
den andre byten i filen. Derfra ligger de tre bokstavene e, n og d, etterfulgt
av en null-byte og så enda en null-byte som signaliserer at setningen er ferdig.

Hva er den hemmelige meldingen i filen =secret=?