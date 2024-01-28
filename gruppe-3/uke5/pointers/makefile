CFLAGS = -std=gnu11 -g -Wall -Wextra
BIN = pekere

all: $(BIN)

pekere: pekere.c
	gcc $(CFLAGS) $^ -o $@
	./$@

clean:
	rm -f $(BIN)