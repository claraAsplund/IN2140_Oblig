#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct __attribute__((__packed__)) person {
  char *navn;
  uint8_t alder;
  char gender;
  int personnummer;
};

#define WOMAN 1
#define MAN 2

void fyller_bursdag(struct person p) { p.alder += 1; }

struct person *make_person(char *navn, uint8_t alder, char gender) {
  struct person *p = malloc(sizeof(struct person));
  p->navn = malloc(sizeof(char) * strlen(navn));
  char *dest = strcpy(p->navn, navn);
  p->alder = alder;
  p->gender = gender;

  return p;
}

int main(int argc, char *argv[]) {
  struct person *p1 = make_person("Reidar", 23, MAN);
  printf("Alder: %d\nNavn: %s\n", p1->alder, p1->navn);
  printf("\n\nSizeof: %ld\n", sizeof(struct person));
  return EXIT_SUCCESS;
}
