
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

    char buff[255];
    FILE *fil = fopen("hemmelig_melding.tekst", "r");
    if (fil == NULL) {
        perror("Opening file");
        exit(-1);
    }

    fread(buff, sizeof(char), 255, fil);

    fclose(fil);
    printf(buff);
}
