#include <stdio.h>

int main(void){

	int x = 2;
	long int adr = &x;
	int *ptr = (int*)adr;

	printf("%ld\n", sizeof(long));
	return 0;
}
