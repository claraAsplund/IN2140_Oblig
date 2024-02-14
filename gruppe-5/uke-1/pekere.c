#include <stdio.h>

void endre_tall(int *nr, int nr2){
	*nr = nr2;
}

int main(void){

	char a = 'a';
	char *test = &a;

	int x = 2;
	endre_tall(&x, 42);

	printf("%d\n", x);

	return 0;
}
