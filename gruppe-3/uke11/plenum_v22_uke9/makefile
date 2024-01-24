main: main.c
	gcc -o main main.c

run: main
	./main processes.bin

valgrind: main
	valgrind --track-origins=yes --malloc-fill=0x42 --free-fill=0x23 ./main processes.bin

file:
	dd count=100 if=/dev/random of=./large-file 

clean:
	rm -f main
