#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* lag_streng(int nr, char letter){

	char string[nr+1];

	for (int i=0; i<nr; i++){
		string[i] = letter++;
	}
	string[nr] = 0;
	char *string2 = malloc(nr+1);
	strncpy(string2, string, nr+1);

	return string2;
}

int main(void){

	char *string = lag_streng(26, 'a');
	printf("%s\n", string);

	free(string);
	return 0;
}
