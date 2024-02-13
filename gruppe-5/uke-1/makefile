
CFLAGS = -g -Wall -Wextra -std=gnu11
BIN = types arr pekere

all: $(BIN)

types: types.c
	gcc $(CFLAGS) types.c -o types

arr: arr.c
	gcc $(CFLAGS) arr.c -o arr

pekere: pekere.c
	gcc $(CFLAGS) pekere.c -o pekere

clean:
	rm -f $(BIN)

