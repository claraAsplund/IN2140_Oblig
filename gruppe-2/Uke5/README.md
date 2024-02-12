# Uke 5
Her finner du oppgaver om lenkelister og filinnlesning

## Snarveier
#### [Oppgave om lenkelister](#lenkelister)
#### [FINN SVINN](#finn-svinn-1)

## Lenkelister
I denne seksjonen skal vi se mer på structs i C, og hvordan de kan brukes til å implementere en lenkeliste.

### Oppgave 1.1 - Oppvarming
Husker du hvordan man arbeider med structs? Hvis ikke kan du se tidligere oppgaver [her](../Uke4#structs)

```c
s.egenskap = 42;
s.annen_egenskap = 21;

p->egenskap = 42;
p->annen_egenskap = 21;
```
Se på kodesnutten over. Hva vet vi om variabelen `s`, og hva vet vi om variabelen `p`?

### Oppgave 1.2.1
- Opprett en `struct program` som skal ha følgende egenskaper:
    - version
    - lines_of_code
    - language
    - name
- Velg de datatypene du selv tenker passer best til egenskapene over.
- Opprett en instans av `struct program`, fyll verdiene og skriv dem ut på en oversiktlig måte.

### Oppgave 1.2.2
Denne oppgaven tar utgangspunkt i oppgaven over (oppgave 1.2.1)
- Skriv en funksjon som returnerer en `struct program *` og tar inn egenskapene den trenger som parametre. Funksjonen skal allokere minne til structen på heapen (bruk `malloc`), og sette egenskapene til structen med parametrene.
- Skriv en funksjon som tar inn en `struct program *` og skriver ut egenskapene til structen på en oversiktlig måte.
- Skriv en funksjon `free_program` som tar inn en `struct program *` og frigjør minnet du har brukt til å opprette structen.
- Kjør programmet ditt med valgrind, og sjekk at du ikke får noen minnefeil eller memory leaks.

### Oppgave 1.3 - Lenkelister
Nå skal vi bruke structs til å implementere lenkelister. Se på følgende struct:
```c
struct node {
    struct node *next;
    int data;
};
```
Her er første elementet i structen en peker til en annen node av samme type som seg selv.
****
- Skriv et program som oppretter tre noder, `a`, `b` og `c`. Gi dem forskjellige verdier til `data`.
- Sett `a` sin `next` til å peke på `b`.
- Sett `b` sin `next` til å peke på `c`.
- Sett `c` sin `next` til `NULL`.
- Lag variabel `temp` av type `struct node *` som peker på `a`. Lag en løkke som går så lenge `temp` ikke er `NULL`.
    - Skriv ut verdien til hver node i løkken (gjennom å kun bruke `temp`).

### Oppgave 1.4.1
- Lag en funksjon `new_node` som returnerer en ny `struct node *`, allokert med `malloc`
- Lag en funksjon `free_nodes` som tar inn en `struct node *` og frigjør minnet til alle elementene i lenkelisten.
- Gjør tre kall på `new_node` og lenk sammen nodene.
- Frigjør minnet til hver node ved *ett* kall på  `free_nodes`.
- Sjekk med valgrind at du ikke har noen memory leaks

### Oppgave 1.4.2 (bonus)
Legg til en egenskap `char *text` i `struct node`, og initialiser denne ved å bruke `malloc`. F.eks:
```c
struct node *my_node = malloc( ... );
...
my_node->text = malloc( ... );
```
Sørg for at `free_nodes` fremdeles frigjør alt minnet du har allokert!

### Oppgave 1.5 - Dobbelt lenket lenkeliste!
Se på filen `doubly_linked.c`. Her inneholder `struct node` både en neste og forige-peker:
```c
typedef struct node {
    struct node *next;
    struct node *prev;
    int value;
} node_t;
```
Merk at vi her også har skrevet `typedef <struct ...> node_t`. Dette gjør at vi i resten av programmet slipper å skrive `struct node` og kan heller skrive `node_t`. Dette er litt smak og behag, mange liker å spesifisere at man jobber med en struct og unngår dermed typedef i slike tilfeller.

Videre ser vi at filen inneholder to globale variabler, `head` og `tail`. Disse skal ikke inneholde noe data, men skal kun gjøre det enklere å sette inn og fjerne fra listen.

Det er fem uimplementerte funksjoner, samt en main-funksjon i denne filen. Disse skal implementeres i oppgave 1.5.1-1.5.6 :)
****
### Oppgave 1.5.1 - main
- Sett `head` sin `next` til å peke på `tail`.
- Sett `tail` sin `prev` til å peke på `head`.
- Opprett åtte noder med forskjellige verdier gjennom kall på `push`
- Gjør et kall på `print_list`
- Pop noen noder og gjør et nytt kall på `print_list`
- Frigjør alt minne gjennom et kall på `free_list`

### Oppgave 1.5.2 - set_between
- Denne funksjonen skal sette alle pekere riktig. Sørg for at `left` sin neste peker på `middle`, right sin `prev` peker på `middle` etc.

### Oppgave 1.5.3 - remove_node
- Denne funksjonen skal sette alle pekere riktig. Noden skal "fjernes" ved å forandre neste og forrige-pekerne til nodene som kommer før og etter `node`.

### Oppgave 1.5.4 - push
- Opprett en ny node (bruk `malloc`) basert på input-verdien og sett inn den nye noden først i listen gjennom et kall på `set_between`.
- Hint: Bruk `head` og dens neste-peker!

### Oppgave 1.5.4 - pop
- Fjern den første noden i listen gjennom et kall på `remove_node`, og returner verdien til noden.
- Hint: Den første noden skal ligge etter `head`!

### Oppgave 1.5.5 - print_list
- Skriv ut verdien til alle elementene i listen gjennom en while-løkke
- Hint: `head` og `tail` er ikke "elementer" i listen
- Hint: Lag en `temp`-variabel som starter som `head`. La løkken gå helt til `temp` er lik `tail`.

### Oppgave 1.5.6 - free_list
- Gå gjennom listen og frigjør hvert enkelt element gjennom kall på `free`.
- Husk å også frigjøre `head` og `tail`!
- Kjør programmet med valgrind og sørg for at du ikke får memory leaks :)


## FINN SVINN
Du har blitt butikksjef for den lokale dagligvarebutikken. De ansatte har vært så snille og tatt vareopptelling, og loggført hele opptellingen i filen `beholdning.log`. Du har også loggført hva du har fått levert til butikken (i filen `levering.log`), og en utskrift fra kasseapparatet (`salg.log`) viser hvor mye som har blitt registrert solgt fra butikken.

Dessverre går det rykter om at en nasker-bande har vært innom butikken, og du ønsker å få oversikt over hva og hvor mye som har blitt tatt. Bruk informasjonen fra de tre filene `beholdning.log`, `levering.log` og `salg.log` til å finne ut hvor mye svinn som har forekommet.

De tre filene inneholder en rekke varer og hver vare er på følgende format:
```
- Antall av vare : 1 unsigned char
- Lengde på navn : 1 unsigned char
- Navn på vare   : en rekke chars
```

Navnet på varene er ikke null-terminert, og vi vet ikke hvor mange varer hver fil inneholder.

Betydningen av antallet varer endres basert på hvilken fil den leses fra:
- Antall varer i `beholdning.log` beskriver antall varer som er registrert ved vareopptellingen.
- Antall varer i `levering.log` beskriver antall varer som er levert til butikken.
- Antall varer i `salg.log` beskriver hvor mange av en type vare som ble solgt under en enkelt-transaksjon. Det kan altså være flere forekomster av samme vare.

Dersom ingen svinn har forekommet for en type vare, burde antallet i `beholdning.log` være likt antallet fra `levering.log` minus det samlede antallet av varer med samme navn fra `salg.log`.

Skriv et program som leser inn informasjonen fra filene, og skriver ut hvilke varer som har svinn.