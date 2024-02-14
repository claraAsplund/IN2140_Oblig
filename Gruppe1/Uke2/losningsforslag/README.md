## Løsningsforslag uke 2

### Oppgave 1.1
```c
#include <stdio.h>

void print_hello() {
    printf("Hello world!\n");
}

int main(void) {
    printf("Hello world!\n");
    print_hello();
    return 0;
}
```
Dersom `print_hello` ligger under `main`, vil ikke kompilatoren skjønne hvilken funksjon det er snakk om og gi en warning. Dette kan unngås ved å deklarere funksjonen over main:
```c
    void print_hello();

    int main(void) {
        // ...
    }
    void print_hello() {
        // ...
    }
```

### Oppgave 1.2
Her er et eksempel på en enkel makefile:
```makefile
all:oppgave1

oppgave1:oppgave1.c
    gcc oppgave1.c -o oppgave1

run:oppgave1
    ./oppgave1

clean:
    rm -f oppgave1
```

### Oppgave 1.3

Bytt ut UiO-brukernavn med ditt UiO brukernavn. Du blir kanskje bedt om å skrive inn UiO-passordet ditt.

```bash
scp oppgave1.c makefile UiO-brukernavn@login.ifi.uio.no:~/pc/Dokumenter/.../
ssh UiO-brukernavn@login.ifi.uio.no
cd ~/pc/Dokumenter/.../
make
./oppgave1
```

### Oppgave 2.1
```c
int array[100];

for (int i = 0; i < 100; i++) {
    printf("%d ", array[i]);
}
printf("\n");
```
Her blir utskriften tilfeldig. Kanskje blir alt 0? Kanskje får du masse forksjellige tall? Det kommer an på hva som tilfeldigvis er på stacken fra før av når du opprettet arrayet.

### Oppgave 2.2
```c
// Kunne også initialisert i en løkke.
int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
array[4] = 1337;
for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
}
printf("\n");
```

### Oppgave 2.3
```c
char navn[] = "Gaute";
char kopi[strlen(navn) + 1]; // + 1 for '\0'-byte

// Kopi måte 1: for-løkke
for (int i = 0; i < strlen(navn) + 1; i++) {
    kopi[i] = navn[i];
}

// Kopi måte 2: strcpy
strcpy(kopi, navn);
```

### Oppgave 2.4
Grunnen til at dette gir segmentation fault er fordi variabelen `p` er en peker. Altså er det en variabel som har plass til en peker (8 bytes), men denne settes aldri. Dermed er verdien til `p` udefinert (enten `NULL`, eller et annet tilfeldig tall basert på hva som lå på stacken fra før), og når vi da prøver å følge pekeren vil vi få segmentation fault. Prøv å skriv ut `p` og se hva du får!

### Oppgave 2.5

```
char a;
int b;
char *p;
int *q;

printf("char: %ld", sizeof(a));
printf("int: %ld", sizeof(b));
printf("char-peker: %ld", sizeof(p));
printf("int-peker: %ld", sizeof(q));
```

### Oppgave 2.6
```c
int a = 5;
int *b = &a;
printf("%d\n", a);
printf("%d\n", *b);
```

### Oppgave 2.7
```c
#include <stdio.h>

void increase(int *tall) {
    *tall += 1;
}

int main() {
    int i = 42;
    increase(&i);
    printf("%d\n", i); // printer 43
}
```

Her må variabelen `tall` være en peker for at forandringen skal skje utenfor skopet til funksjonen `increase`. Vi sender inn adressen til `i`, i stedet for tallet `i`, dermed kan `increase` endre tallet.

### Oppgave 2.8
```c
void sett_tall(int *peker, int tall) {
    *peker = tall;
}
```

### Oppgave 3.1

```c
void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}
```

Arrays i C har faktisk ingen lengde! De beskriver bare et minneområdet som du selv har reservert, og hvor mye du har fått tildelt kommer an på hvor mye du spurte om. Når man skriver `int array[10]` har man fått plass til 10 int-er (40 bytes), men man kan fint gå utenfor dette området. F.eks kan man skrive `array[12] = 42;`, men da kan det være man overskriver verdier man ikke burde overskrive og programmet kan krasje eller oppføre seg rart. Vi kan **IKKE** bruke `sizeof`-operatoren til å finne lengden.

### Oppgave 3.2

```c
char *s = "Marie"; // samme som {'M', 'a', 'r', 'i', 'e', '\0'}

while (*s) {
    printf("%c\n", *s);
    s++;
}
```
Her vil løkken automatisk stoppe når vi har nådd slutten av strengen, da '\0' er det samme som tallet 0, som blir det samme som false. For hver iterajon i løkken vil `s` flytte seg en adresse bort, og dermed peke på neste bokstav. Det vil også si at når løkken er over sitter vi igjen med en tilsynelatende tom streng, altså en peker til en '\0'-byte.
