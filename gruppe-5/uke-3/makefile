
CFLAGS = -g -Wall -Wextra -std=gnu11
BIN = mem struct peker

all: $(BIN)

mem: mem.c
	gcc $(CFLAGS) mem.c -o mem

struct: struct.c
	gcc $(CFLAGS) struct.c -o struct

peker: peker.c
	gcc $(CFLAGS) peker.c -o peker

clean:
	rm -f $(BIN)
