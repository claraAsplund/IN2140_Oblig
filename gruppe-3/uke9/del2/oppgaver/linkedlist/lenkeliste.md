# Oppgave (Middels vanskelig)

Ukens oppgaver er delt i to ulike nivåer. Du er nå på den middels vanskelige oppgaven!

Oppgaven er her å implementere en `lenkeliste` der hver node lagrer ett tall. `Lenkelisten` skal implementeres ved bruk av `structs`. Du trenger her to forskjellige structs, en for nodene og en for selve lenkelisten. Under ligger et eksempler på hvordan disse kan se ut, men det er rom for å forbedre kjøretiden til funksjonene under ved å legge til et par ekstra elementer i structsene.

```cpp

struct lenkeliste {
    struct node* first;
}

struct node {
    int value;
    struct node* next;
}

```

Start med å lage structen og gå videre til å implementere de følgende hjelpefunksjonene:

```cpp

void push_front(struct lenkeliste* ll, struct node* new_node);       // Legger til et element forrerste i lista
void push_back(struct lenkeliste* llstruct node* new_node);       // Legger til et element bakerst i lista
struct node pop_front(struct lenkeliste* ll);                      // Fjerner og returnerer det første elementet i lista
struct node pop_back(struct lenkeliste* ll);                      // Fjerner og returnerer det siste elementet i lista
int number_of_elements(struct lenkeliste* ll);                  // Returnerer antallet elementer i lenkelista

```
