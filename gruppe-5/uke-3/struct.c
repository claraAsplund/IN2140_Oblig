#include <stdlib.h>
#include <stdio.h>

typedef struct person {
	char *name;
	char age;
}person;

person* create_person(char *name, char age){
	person *p = malloc(sizeof(person));
	p->name = name;
	p->age = age;

	return p;
}

int main(void){

	person *philip = create_person("Philip", 33);
	printf("Name: %s\nAge: %d\n", philip->name, philip->age);
	free(philip);

	return 0;
}
