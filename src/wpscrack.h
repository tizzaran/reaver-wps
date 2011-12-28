/*
 * Reaver - Main and usage functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef WPSCRACK_H
#define WPSCRACK_H

#include "defs.h"
#include "argsparser.h"
#include "sigint.h"
#include "cracker.h"

void parse_recurring_delay(char *arg);
int usage(char *prog_name);

#endif
