CC = gcc
CFLAGS = -std=gnu11 -g -Wall -Wextra

TARGETS = deserialisering serialisering minne bintre enkel_lenkeliste

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS) data.bin