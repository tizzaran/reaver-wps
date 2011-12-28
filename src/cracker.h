#ifndef CRACKER_H
#define CRACKER_H

#include "defs.h"
#include "globule.h"
#include "80211.h"
#include "init.h"
#include "exchange.h"
#include "pins.h"

#define DISPLAY_PIN_COUNT	5

void crack();
void advance_pin_count();
void display_status(float pin_count, time_t start_time);

#endif
