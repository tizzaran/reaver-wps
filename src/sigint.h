/*
 * Reaver - Signal handling functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef SIGINT_H
#define SIGINT_H

#include <signal.h>
#include "globule.h"
#include "send.h"

void sigint_init();
void sigint_handler(int x);

#endif
