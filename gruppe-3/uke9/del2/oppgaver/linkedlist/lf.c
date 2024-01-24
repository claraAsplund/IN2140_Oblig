#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lenkeliste
{
    struct node *first;
};

struct node
{
    int value;
    struct node *next;
};

void push_front(struct lenkeliste *ll, struct node *new_node); // Legger til et element forrerst i lista
void push_back(struct lenkeliste *llstruct node *new_node);    // Legger til et element bakerst i lista
struct node pop_front(struct lenkeliste *ll);                  // Fjerner og returnerer det første elementet i lista
struct node pop_back(struct lenkeliste *ll);                   // Fjerner og returnerer det siste elementet i lista
int number_of_elements(struct lenkeliste *ll);                 // Returnerer antallet elementer i lenkelista