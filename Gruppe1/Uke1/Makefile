CFLAGS = -std=gnu11 -g -Wall -Wextra
CC = gcc
BIN = uke1

all: $(BIN)

#^$ er alle filer som ligger etter ':'. $@ er alle filene som ligger til venstre for ':'. 
uke1: uke1.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BIN)

run:
	./uke1