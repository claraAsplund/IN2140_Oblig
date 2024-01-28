CC = gcc
CFLAGS = -g -std=gnu11
BINNAME = task



task: task.o
	$(CC) $(CFLAGS) task.o -o $(BINNAME)

task.o: task.c
	$(CC) $(CFLAGS) -c task.c


.PHONY: clean

clean:
	printf "\033c" && rm -f task && rm -f task.o