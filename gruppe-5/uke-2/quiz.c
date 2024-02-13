#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void func1(){

	int tall = 2;
	tall++;
	printf("%d\n", tall);
}

void func2(){
	int tall = 2;
	int tall2 = 2 * tall++;
	printf("%d\n", tall2);
}

void func3(){
	int tall = 2;
	int tall2 = 2 * ++tall;
	printf("%d\n", tall2);
}

void func4(){
	int tall = 2;
	int *ptr = &tall;
	printf("%d\n", *ptr);
}

void func5(){
	int tall = 2;
	int tall2 = 1;
	int *ptr = &tall;
	ptr++;
	printf("%d\n", *ptr);
}

void func6(){
	int tall = 2;
	int tall2 = 9;
	int *ptr = &tall;

	int x = *(++ptr);
	printf("%d\n", x);
}

void func7(){
	int tall = 2;
	int tall2 = 9;
	int *ptr = &tall;

	int x = ++*ptr;
	printf("%d\n", x);
}

void func8(){
	int tall = 2;
	int tall2 = 9;
	int *ptr = &tall;

	int x = --*(++ptr);
	printf("%d\n", x);
}

int main(int argc, char **argv){

	char *ptr;

	if (argc > 1){
		int arg = strtol(argv[1], &ptr, 10); 
		switch(arg){
			case (1):
				func1();
				break;
			case (2):
				func2();
				break;
			case (3):
				func3();
				break;
			case (4):
				func4();
				break;
			case (5):
				func5();
				break;
			case (6):
				func6();
				break;
			case (7):
				func7();
				break;
			case (8):
				func8();
				break;
		}
	}
	return 0;
}
