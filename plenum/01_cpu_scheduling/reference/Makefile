scheduler: scheduler.o sl_list.o
	gcc -g -o scheduler scheduler.o sl_list.o

scheduler.o: scheduler.c sl_list.h
	gcc -g -c scheduler.c

sl_list.o: sl_list.c sl_list.h
	gcc -g -c sl_list.c

clean:
	rm -f scheduler.o
	rm -f sl_list.o

realclean: clean
	rm -f scheduler

