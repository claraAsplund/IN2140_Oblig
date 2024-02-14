#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sang{
    char *artist;
    char *tittel;
    int lengde_sec;
};

void fyll_sang(struct sang *s, char *artist, char *tittel, int lengde){
    s->lengde_sec = lengde;
    s->tittel = strdup(tittel);
    s->artist = strdup(artist);
}

void print_sang(struct sang *s){
    printf("*********************************\n");
    printf("\tArtist:\t%s\n", s->artist);
    printf("\tTittel:\t%s\n", s->tittel);
    printf("\tLengde:\t%d\n", s->lengde_sec);
    printf("*********************************\n");
}

int main(int argc, char const *argv[]) {
    struct sang *min_sang = malloc(sizeof(struct sang));

    fyll_sang(min_sang, "Adele", "Skyfall", 220);
    print_sang(min_sang);

    free(min_sang);
}
