CFLAGS=-lm
VFLAGS=

run:memleak
	./memleak

memleak:memleak.c
	gcc memleak.c -o memleak $(CFLAGS)

check:clean memleak
	valgrind $(VFLAGS) ./memleak

clean:
	rm -f memleak
