
CFLAGS = -g -Wall -Wextra -std=gnu11
BIN = unbuffered filemaster3000

all: $(BIN)

unbuffered: unbuffered.c
	gcc $(CFLAGS) unbuffered.c -o unbuffered

filemaster3000: filemaster3000.c
	gcc $(CFLAGS) filemaster3000.c -o filemaster3000

clean:
	rm -f $(BIN)
