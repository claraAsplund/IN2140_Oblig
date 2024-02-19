#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("beholdning.log", "r");
    int rc;

    unsigned int antall;
    rc = fread(&antall, sizeof(int), 1, file);
    if (rc != 1) {
        fprintf(stderr, "error");
        exit(-1);
    }
    
    unsigned char lengde;
    rc = fread(&lengde, sizeof(char), 1, file);
        if (rc != 1) {
        fprintf(stderr, "error");
        exit(-1);
    }

    char buffer[lengde + 1];
    rc = fread(buffer, sizeof(char), lengde, file);
    if (rc != lengde) {
        fprintf(stderr, "error");
        exit(-1);
    }
    buffer[lengde] = 0;




    

    printf("antall: %d\nNavn: %s\n", antall, buffer);

    fclose(file);
}
