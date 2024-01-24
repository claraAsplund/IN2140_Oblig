scheduler: scheduler.o queue.o
	gcc -g -o scheduler scheduler.o queue.o

scheduler.o: scheduler.c queue.h
	gcc -g -c scheduler.c

queue.o: queue.c queue.h
	gcc -g -c queue.c

clean:
	rm -f scheduler.o
	rm -f queue.o

realclean: clean
	rm -f scheduler

