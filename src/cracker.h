/*
 * Reaver - Main WPS pin cracking functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */


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
