CFLAGS = -std=gnu11 -g -Wextra -Wall
CC = gcc

BIN = unbuffered buffered ub_vs_b

unbuffered: unbuffered.c 
	$(CC) $(CFLAGS) unbuffered.c -o unbuffered

run:
	./unbuffered

run_vs:
	./ub_vs_b

run_b:
	./buffered

clean:
	rm -r $(BIN)

buffered: buffered.c 
	$(CC) $(CFLAGS) buffered.c -o buffered

ub_vs_b: ub_vs_b.c 
	$(CC) $(CFLAGS) ub_vs_b.c -o ub_vs_b
