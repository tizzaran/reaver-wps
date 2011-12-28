/*
 * Reaver - 80211 transmit functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef SEND_H
#define SEND_H

#include "defs.h"
#include "globule.h"
#include "builder.h"
#include "sigalrm.h"

#define WFA_REGISTRAR "WFA-SimpleConfig-Registrar-1-0"

int send_eapol_start();
int send_identity_response();
int send_msg();
void send_termination();
void send_wsc_nack();
int send_packet(const void *packet, size_t len);

#endif
