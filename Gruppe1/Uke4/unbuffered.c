
#include <fcntl.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
// Skriv in man 2 open i terminalen for a se pa open()

#define BUFFSIZE 255

int check_error(int v, char* s) {
    if (v == -1) {
        perror(s);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(void) {

    int fd, wc, rc; //rc;
    char buf[BUFFSIZE];

    // Ved a bruke O_TRUNK sletter man alt innholdet fra filen hvis den eksisterer fra for av.
    // O_CREAT lager en ny fil, hvis den ikke eksisterer
    fd = open("test.txt", O_RDONLY /*O_WRONLY | O_TRUNC | O_CREAT*/); //Tre forskjellige aksessmetoder, O_READONLY, O_WRONLY, O_RDWR.
    
    if (fd == -1) {
        perror("open-funksjonen koblet til variabelen fd");
        // fprintf(stderr, "open() failure");
        return EXIT_FAILURE;
    }

    rc = read(fd, buf, BUFFSIZE-1);

    if (rc == -1) {
        perror("open-funksjonen koblet til variabelen fd");
        // fprintf(stderr, "open() failure");
        return EXIT_FAILURE;
    }

    buf[rc] = 0;

    printf("%s\n", buf);
    
    // write er et systemkall (man 2 write)
    // Denne maten vil overskrive deler av filen.
    
    
    /*wc = write(fd, "Hallo, det er meg", 17);

    if (wc == -1) {
        perror("wc = write()");
        close(fd);
        return EXIT_FAILURE;
    }*/

    /*
    rc = read(fd, buf, BUFFSIZE-1);
    checke_error(rc, "Feil i rc");

    buf[rc] = 0;
    printf("%s\n",buf);
    */

    close(fd);


    return 0;
}