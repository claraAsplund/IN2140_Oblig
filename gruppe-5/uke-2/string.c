
#include <string.h>
#include <stdio.h>

int strlen2(char *string){
	int nr = 0;
	for (; string[nr]; nr++);
	return nr;
}

int main(void){

	char *string = "abcd";
	char string2[] = "Dette er ogsaa en streng";

	int arr[4] = {1, 2, 3, 4};

	printf("%d\n", strlen2(string));

	return 0;
}
