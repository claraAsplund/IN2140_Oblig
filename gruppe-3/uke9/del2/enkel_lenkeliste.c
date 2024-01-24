#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

struct person
{
    int alder;
    char *navn;
    struct person *next;
};

void print_list(struct person *liste)
{
    while (liste)
    { // equiv: liste != NULL
        printf("%s er %d aar\n", liste->navn, liste->alder);
        liste = liste->next;
    }

    // evt:
    // struct person *tmp;
    // for (tmp = liste; tmp != NULL; tmp = tmp->next)
    // {
    //     printf("%s er %d aar\n", tmp->navn, tmp->alder);
    // }
}

int main(void)
{
    struct person p;
    p.alder = 39;
    p.navn = "Olav";

    struct person *p2 = malloc(sizeof(struct person));
    if (p2 == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return EXIT_FAILURE;
    }
    p2->alder = 12; // eqv: (*p2).alder = 12
    p2->navn = "Gaute";

    p.next = p2;
    p2->next = NULL;

    print_list(&p);
    free(p2);

    return EXIT_SUCCESS;
}