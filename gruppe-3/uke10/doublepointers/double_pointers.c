#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Hello world\n");

  car **list_of_cars = malloc(sizeof(car *) * 3);

  car *new_1 = make_car("CD12345", 1986, 1, 1);
  car *new_2 = make_car("EF12345", 1992, 0, 1);
  car *new_3 = make_car("XZ12345", 2006, 1, 0);

  list_of_cars[0] = new_1;
  list_of_cars[1] = new_2;
  list_of_cars[2] = new_3;

  for (int i = 0; i < 3; i++) {
    car *tmp = list_of_cars[i];
    printf("Skiltnummer: %s\n", tmp->license_plate);
    printf("Er eu godkjent: %d\n", CHECK_EU(tmp->flag));
  }

  return EXIT_SUCCESS;
}
