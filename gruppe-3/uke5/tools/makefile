CFLAGS = -std=gnu11 -g -Wall -Wextra
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --malloc-fill=0x40 --free-fill=0x23
BIN = ...

all: $(BIN)

...: ...
	gcc $(CFLAGS) $^ -o $@
	./$@
 
valgrind_...: ...
	valgrind $(VFLAGS) ./$@

clean:
	rm -f $(BIN)