
CFLAGS = -g -Wall -Wextra -std=gnu11
BIN = alloc string

all: $(BIN)

alloc: alloc.c
	gcc $(CFLAGS) alloc.c -o alloc

string: string.c
	gcc $(CFLAGS) string.c -o string

clean:
	rm -f $(BIN)
