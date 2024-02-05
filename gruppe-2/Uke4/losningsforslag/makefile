CFLAGS = -g -lm
VFLAGS = --track-origins=yes --leak-check=full

run: memleak
	./memleak

memleak: memleak.c
	gcc memleak.c -o memleak $(CFLAGS)

check: clean memleak
	valgrind $(VFLAGS) ./memleak

clean:
	rm -f memleak
