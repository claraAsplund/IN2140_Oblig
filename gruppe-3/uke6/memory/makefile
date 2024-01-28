CFLAGS = -std=gnu11 -g -Wall -Wextra
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --malloc-fill=0x40 --free-fill=0x23
BIN = memory test

all: $(BIN)

memory: memory.c
	gcc $(CFLAGS) $^ -o $@
	./$@
	
test: test.c
	gcc $(CFLAGS) $^ -o $@

clean:
	rm -f $(BIN)
