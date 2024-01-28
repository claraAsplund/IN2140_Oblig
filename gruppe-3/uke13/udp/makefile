CC = gcc
CFLAGS = -g -std=gnu11


all: server client

client: client.o
	$(CC) $(CFLAGS) client.o -o client

client.o : client.c
	$(CC) $(CFLAGS) -c client.c

server: server.o
	$(CC) $(CFLAGS) server.o -o server

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

.PHONY: clean

clean:
	rm *.o client server