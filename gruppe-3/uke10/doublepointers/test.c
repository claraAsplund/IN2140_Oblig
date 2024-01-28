#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char **navn_liste = malloc(sizeof(char *) * 3);

  char *navn = malloc(sizeof(char) * strlen("Reidar") + 1);
  strcpy(navn, "Reidar");
  char *navn2 = malloc(sizeof(char) * 4);
  strcpy(navn2, "Ida");
  char *navn3 = malloc(sizeof(char) * 4);
  strcpy(navn3, "Ole");

  navn_liste[0] = navn;
  navn_liste[1] = navn2;
  navn_liste[2] = navn3;

  for (int i = 0; i < 3; i++) {
    printf("Navn: %s\n", navn_liste[i]);
    free(navn_liste[i]);
  }

  free(navn_liste);

  return EXIT_SUCCESS;
}
