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

#ifndef SIGALRM_H
#define SIGALRM_H

#include <signal.h>
#include <sys/time.h>

#include "defs.h"
#include "globule.h"
#include "misc.h"

void sigalrm_init();
void start_timer();
void stop_timer();
void alarm_handler(int x);

#endif
