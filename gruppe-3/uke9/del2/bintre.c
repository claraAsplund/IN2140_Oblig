#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *venstre, *hoyre;
    int verdi;
};

void print_bintre(struct node *rot)
{
    printf("%d\n", rot->verdi);

    if (rot->venstre != NULL)
        print_bintre(rot->venstre);

    if (rot->hoyre != NULL)
        print_bintre(rot->hoyre);
}

int main(void)
{
    struct node rot = {NULL, NULL, 10};

    struct node n1 = {NULL, NULL, 5};
    struct node n2 = {NULL, NULL, 20};
    struct node n3 = {NULL, NULL, 30};

    n1.hoyre = &n3;

    rot.hoyre = &n1;
    rot.venstre = &n2;

    print_bintre(&rot);

    return 0;
}
