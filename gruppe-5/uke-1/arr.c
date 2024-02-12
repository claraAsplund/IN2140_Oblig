#include <stdio.h>

int main(void){

	char arr[5] = {0};
	int test[20] = {1, 2, 23, 4};
	char arr2[4];

	char *string = "Hei dette er en streng";
	char string2[20] = "Dette er en test";

	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = 'c';
	arr[3] = 0;
	arr[4] = 'd';


	printf("%s\n", string);

	return 0;
}
