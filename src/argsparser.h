/*
 * Reaver - Command line processing functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <stdio.h>
#include <getopt.h>
#include "defs.h"
#include "iface.h"
#include "config.h"

int process_arguments(int argc, char **argv);
void init_default_settings(void);
void parse_recurring_delay(char *arg);

#endif
