/*
 * Reaver - Misc functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef MISC_H
#define MISC_H

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "defs.h"
#include "globule.h"

unsigned char *mac2str(unsigned char *mac, char delim);
void str2mac(unsigned char *str, unsigned char *mac);
void cprintf(enum debug_level level, const char *fmt, ...);
void daemonize(void);

#endif
