#include <fcntl.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"

#define BUFFSIZE 255

int main(void) {
    FILE *fil;
    char* msg = "Det er litt kaotisk";
    char buf[BUFFSIZE];

    size_t wc; // size_t
    size_t rc;

    fil = fopen("new_file.txt", "r"); //en biblioteksfunksjon
    if (fil == NULL) {
        perror("somehting");
        return EXIT_FAILURE;
    }

    /*
    wc = fwrite(msg, sizeof(char), strlen(msg), fil);
    if (wc < strlen(msg)) {
        perror("Feil i fwrite");
        fclose(fil);
        return EXIT_FAILURE;
    }
    */

   rc = fread(buf, sizeof(char), BUFFSIZE-1, fil);
    if (rc < strlen(msg) && ferror(fil)) {
        //perror("Feil i fread"); Kan brukes ogsa
        fprintf(stderr, "Feil i fread()\n");
        fclose(fil);
        return EXIT_FAILURE;
    }

    buf[rc] = 0;
    printf("%s\n", buf);




    fclose(fil); // Lukker filen. Hvis glemt kan gi minnelekkasjer.

    return 0;
}