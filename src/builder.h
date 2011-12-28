/*
 * Reaver - Packet building functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef BUILDER_H
#define BUILDER_H

#include <arpa/inet.h>
#include "defs.h"
#include "globule.h"

#define SRATES_TAG_SIZE         8
#define ERATES_TAG_SIZE         4
#define SRATES_TAG_NUMBER       0x01
#define ERATES_TAG_NUMBER       0x32
#define WPS_TAG_SIZE            14
#define WPS_REGISTRAR_TAG       "\x00\x50\xF2\x04\x10\x4A\x00\x01\x10\x10\x3A\x00\x01\x02"
#define EXTENDED_RATES_TAG      "\x30\x48\x60\x6C"
#define SUPPORTED_RATES_TAG     "\x02\x04\x0B\x16\x0C\x12\x18\x24"
#define WPS_REGISTRAR_TAG       "\x00\x50\xF2\x04\x10\x4A\x00\x01\x10\x10\x3A\x00\x01\x02"

#define DEFAULT_DURATION        52

#define DOT1X_VERSION           0x01
#define DOT1X_START             0x01

#define FC_PROBE_REQUEST        0x0040
#define FC_STANDARD		0x0108

#define LLC_SNAP                0xAA
#define SEQ_MASK                0x10

#define LISTEN_INTERVAL         0x0001
#define OPEN_SYSTEM             0

#define UNNUMBERED_FRAME        0x03
#define WFA_VENDOR_ID           "\x00\x37\x2A"

#define WPS_PROBE_IE            "\xdd\x09\x00\x50\xf2\x04\x10\x4a\x00\x01\x10"
#define WPS_PROBE_IE_SIZE       11

const void *build_radio_tap_header(size_t *len);
const void *build_dot11_frame_header(uint16_t fc, size_t *len);
const void *build_authentication_management_frame(size_t *len);
const void *build_association_management_frame(size_t *len);
const void *build_llc_header(size_t *len);
const void *build_wps_probe_request(unsigned char *bssid, char *essid, size_t *len);
const void *build_snap_packet(size_t *len);
const void *build_dot1X_header(uint8_t type, uint16_t payload_len, size_t *len);
const void *build_eap_header(uint8_t id, uint8_t code, uint8_t type, uint16_t payload_len, size_t *len);
const void *build_eapol_start_packet(size_t *len);
const void *build_eap_packet(const void *payload, uint16_t payload_len, size_t *len);
const void *build_eap_failure_packet(size_t *len);
const void *build_tagged_parameter(uint8_t number, uint8_t size, size_t *len);
const void *build_ssid_tagged_parameter(size_t *len);
const void *build_wps_tagged_parameter(size_t *len);
const void *build_supported_rates_tagged_parameter(size_t *len);

#endif
