#include <stdio.h>
#include <stdlib.h>


int* q2(int nr){
	int *x = malloc(sizeof(int));
	*x = nr * nr;
	return x;
}

int main(void){

	int *y = q2(4);
	printf("%d\n", *y);


	return 0;
}
