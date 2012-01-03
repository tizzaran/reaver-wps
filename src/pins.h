#ifndef PINS_H
#define PINS_H

#include "defs.h"
#include "globule.h"
#include "keys.h"

#define PIN_SIZE	8

/* Defined in keys.c */
extern struct key k1[P1_SIZE];
extern struct key k2[P2_SIZE];

char *build_wps_pin();
char *build_next_pin();
void randomize_pins();

#endif
