/*
 * Reaver - Initialization functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef INIT_H
#define INIT_H

#include "defs.h"
#include "misc.h"

#define DEFAULT_UUID            "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F"
#define UUID_LEN                16

struct wps_data *initialize_wps_data();
pcap_t *capture_init(char *capture_source);

#endif
