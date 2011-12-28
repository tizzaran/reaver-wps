/*
 * Reaver - Wireless interface functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef IFACE_H
#define IFACE_H

#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include "lwe/iwlib.h"

#include "defs.h"
#include "globule.h"
#include "misc.h"

#define BG_BAND			0
#define AN_BAND			1

#define BG_CHANNELS		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }
#define AN_CHANNELS		{ 16, 34, 36, 38, 40, 42, 44, 46, 48, 52, 56, 60, 64, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 149, 153, 157, 161, 165, 183, 184, 185, 187, 188, 189, 192, 196 }

int read_iface_mac();
int next_channel();
int change_channel(int channel);

#endif
