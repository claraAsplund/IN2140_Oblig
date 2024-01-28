CC = gcc
CFLAGS = -std=gnu11 -g
VECTOR = vector
TEST = test
BINOUT = test


test: test.o vector.o
	$(CC) $(CFLAGS) $(VECTOR).o $(TEST).o -o $(BINOUT)

test.o: test.c
	$(CC) $(CFLAGS) -c $(TEST).c

vector.o : vector.c
	$(CC) $(CFLAGS) -c $(VECTOR).c

.PHONY: clean


clean:
	echo '\033[2J' && rm -f *.o && rm -f test


