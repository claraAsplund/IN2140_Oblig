#ifndef DATA_H
#define DATA_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define EU_FLAG 0
#define USED_CAR 1

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define CHECK_EU(var) (CHECK_BIT(var, EU_FLAG))
#define CHECK_USED(var) (CHECK_BIT(var, USED_CAR))

#define EU_APPROVED (1 << EU_FLAG)
#define IS_USED (1 << USED_CAR)

typedef struct {
  char *license_plate;
  uint16_t model_year;
  uint8_t flag;
} car;

car *make_car(char *license_plate, uint16_t model_year, uint8_t is_eu_approved,
              uint8_t is_used);

#endif // !DATA_H
