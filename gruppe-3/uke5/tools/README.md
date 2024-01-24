[Tilbake til oversikt](./../README.md)

# Nyttige verktøy for C-programmering

## Make-fil og kompilering

**Kompilering i C**

```bash
gcc <flagg> <fil.c> -o <output>
```

For å kjøre:
`./<output>`

**Make-fil**

```make
CFLAGS = -std=gnu11 -g -Wall -Wextra
BIN = test

all: $(BIN)

# test.c er en dependency
test: test.c
	gcc $(CFLAGS) test.c -o test
    ./test

# hack:
#   $^ forkortelse for det HØYRE for kolon
#   $@ det til VENSTRE for kolon

# det er altså ekvivalent å skrive
test: test.c
    gcc $(CFLAGS) $^ -o $@
    ./$@

clean:
	rm -f $(BIN)
	echo Clean done
```

- Konvensjon å kalle regelen det samme som output-filen. Så i dette tilfellet test.

Bruk:

```
make test
make all
make clean
```

## Valgrind

Viktig å frigjøre minne man har allokert. Dette får man oversikt over ved å kjøre valgrind. Alloc skal være lik freed. Ved å frigjøre sier man at man ikke skal bruke det minne lenger. Går man tom for minne kan malloc feile.

Kjør valgrind ofte. Da blir det lettere å se hvor man introduserer feil.

```make
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --malloc-fill=0x40 --free-fill=0x23

# kjøre ved hjelp av makefil:
valgrind: test
    valgrind $(VFLAGS) ./test
```

Kjøre i terminal: `valgrind ./test`

Flagg

- `--track-origins=yes`
  - viser hvor minnet som ble feil ble opprettet
- `--malloc-fill=0x40` (0x40 er ASCII for @)
  - hvis du har glemt å terminere en streng med null-byte, så vil denne erstatte den tilfeldige nullbyten med alfakrøll.
- `--free-fill=0x23`
  - bytter ut minneområdet du har free'et med gitt bokstav i ASCII tabellen. Ser man flere 23-ere etter hverandre kan det hende denne har slått ut.
- `--leak-check=full`
- `--show-leak-kinds=all`
  - begge for minnelekkasje

## Manualen

Man kan slå opp rett i linuxterminalen for ulike funksjoner. For eksempel `man 3 printf`, `man strncpy`. \
2 betyr at det er en systemfunksjon. \
3 betyr at det er en biblioteksfunksjon.

## GDB

Kompiler vanlig først:

```bash
gcc -std=gnu11 -g -Wall -Wextra <en_fil.c> -o <en_fil>
```

Start gdb:

```bash
gdb ./<exectuable>
```

**Kommandoer** \
**run** - kjører hele programmet \
**s** - step, kan steppe gjennom linje for linje \
**b** - sette breakpoint \
**c** - continue \
**n** - next (hopper videre, men bare i skopet den er i) \
**list** - lister opp linjene med kode som kjøres \
**print \<variabel>** - kan brukes til å se verdien til en variabel under kjøring.

Har du VSCode kan du bruke den innebygde debuggeren ved å sette røde prikker for breakpointsene.
