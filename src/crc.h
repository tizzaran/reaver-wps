/*
 * Reaver - CRC functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef _CRC_H_
#define _CRC_H_

#include <stdlib.h>
#include <stdint.h>

uint32_t crc32(char *buf, size_t len);

#endif
