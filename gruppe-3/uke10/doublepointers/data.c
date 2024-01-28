#include "data.h"
#include <string.h>

car *make_car(char *license_plate, uint16_t model_year, uint8_t is_eu_approved,
              uint8_t is_used) {
  car *new_car = malloc(sizeof(car));
  if (new_car == NULL)
    return NULL;

  new_car->license_plate = malloc(sizeof(char) * (strlen(license_plate)) + 1);

  for (size_t i = 0; i < strlen(license_plate); i++) {
    new_car->license_plate[i] = license_plate[i];
  }
  new_car->license_plate[strlen(license_plate)] = '\0';

  new_car->model_year = model_year;

  new_car->flag = 0b0;

  if (is_eu_approved)
    new_car->flag |= EU_APPROVED;
  if (is_used)
    new_car->flag |= IS_USED;

  return new_car;
}
