/*
 * Reaver - Common definitions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU General Public License in all respects
 *  for all of the code used other than OpenSSL. *  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so. *  If you
 *  do not wish to do so, delete this exception statement from your
 *  version. *  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 */

#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pcap.h>

#include "wps.h"

#define NULL_MAC		"\x00\x00\x00\x00\x00\x00"
#define DEFAULT_MAX_NUM_PROBES	15
#define MAX_ASSOC_FAILURES	10

#define TIMESTAMP_LEN		8
#define MAC_ADDR_LEN    	6
#define SSID_TAG_NUMBER		0
#define CHANNEL_TAG_NUMBER	3
#define WPS_TAG_NUMBER		0xDD
#define VENDOR_SPECIFIC_TAG	0xDD
#define RSN_TAG_NUMBER		0x30

#define CAPABILITY_WEP		0x10

#define WPA_IE_ID               "\x00\x50\xF2\x01\x01\x00"
#define WPA_IE_ID_LEN           6

#define MANAGEMENT_FRAME	0x00
#define SUBTYPE_BEACON		0x08

#define DOT1X_AUTHENTICATION	0x8E88
#define DOT1X_EAP_PACKET	0x00

#define SIMPLE_CONFIG		0x01000000

#define P1_SIZE			10000
#define P2_SIZE			1000

#define EAPOL_START_MAX_TRIES	25
#define WARN_FAILURE_COUNT	10

#define EAPOL_START		1
#define EAP_IDENTITY 		0x01
#define EAP_EXPANDED            0xFE

#define M57_DEFAULT_TIMEOUT     200000          /* uSeconds */
#define M57_MAX_TIMEOUT         1000000         /* uSeconds */
#define DEFAULT_DELAY           1               /* Seconds */
#define DEFAULT_TIMEOUT         5               /* Seconds */
#define DEFAULT_LOCK_DELAY      315             /* Seconds */
#define SEC_TO_US               1000000         /* uSeconds in a Second */

#define TSFT_SIZE 		8
#define FLAGS_SIZE 		1
#define RATE_SIZE 		1
#define CHANNEL_SIZE 		4
#define FHSS_SIZE 		2

#define WPS_DEVICE_NAME		"Glau"
#define WPS_MANUFACTURER	"Microsoft"
#define WPS_MODEL_NAME		"Windows"
#define WPS_MODEL_NUMBER	"6.1.7601"
#define WPS_DEVICE_TYPE		"\x00\x01\x00\x50\xF2\x04\x00\x01"
#define WPS_OS_VERSION		"\x01\x00\x06\x00"
#define WPS_RF_BANDS		0x01

enum encryption_type
{
        NONE,
        WEP,
        WPA
};

enum key_state
{
	KEY1_WIP = 0,
	KEY2_WIP = 1,
	KEY_DONE = 2
};

enum debug_level
{
	CRITICAL = 0,
	INFO = 1,
	WARNING = 2,
	VERBOSE = 3
};

enum eap_codes
{
	EAP_REQUEST = 1,
	EAP_RESPONSE = 2,
	EAP_SUCCESS = 3,
	EAP_FAILURE = 4
};

enum wps_result
{
	KEY_ACCEPTED = 0,
	KEY_REJECTED = 1,
	RX_TIMEOUT = 2,
	EAP_FAIL = 3,
	UNKNOWN_ERROR = 4
};

enum nack_code
{
	NO_NACK = -1,
	NO_ERROR = 0,
	OOB_RRAD_ERROR = 1,
	CRC_FAILURE = 2,
	CHANNEL_24_NS = 3,
	CHANNEL_50_NS = 4,
	WEAK_SIGNAL = 5,
	NET_AUTH_FAILURE = 6,
	NET_ASSOCIATION_FAILURE = 7,
	NO_DHCP_RESPONSE = 8,
	FAILED_DHCP_CONFIG = 9,
	IP_ADDR_CONFLICT = 10,
	REGISTRAR_CONNECT_FAILURE = 11,
	MULTIPLE_PBC = 12,
	ROGUE_ACTIVITY = 13,
	DEVICE_BUSY = 14,
	SETUP_LOCKED = 15,
	MESSAGE_TIMEOUT = 16,
	REGISTRATION_TIMEOUT = 17,
	AUTH_FAILURE = 18
};

enum wps_type
{
	TERMINATE = -1,
	UNKNOWN = 0,
	IDENTITY_REQUEST = 1,
	RXM1 = RECV_M1,
	RXM3 = RECV_M3,
	RXM5 = RECV_M5,
	RXM7 = RECV_M7,
	RXACK = RECV_M2D_ACK,
	DONE = RECV_DONE,
	NACK = SEND_WSC_NACK
};

enum rt_header_flags
{
	TSFT_FLAG = 0x01,
	FLAGS_FLAG = 0x02,
	RATE_FLAG = 0x04,
	CHANNEL_FLAG = 0x08,
	FHSS_FLAG = 0x10,
	SSI_FLAG = 0x20,
};

#pragma pack(1)
struct radio_tap_header
{
	uint8_t revision;	
	uint8_t pad;
	uint16_t len;
	uint32_t flags;
};

struct frame_control
{
        unsigned version : 2;
        unsigned type : 2;
        unsigned sub_type : 4;

        unsigned to_ds : 1;
        unsigned from_ds : 1;
        unsigned more_frag : 1;
        unsigned retry : 1;
        unsigned pwr_mgt : 1;
        unsigned more_data : 1;
        unsigned protected_frame : 1;
        unsigned order : 1;
};

struct dot11_frame_header
{
	struct frame_control fc;
        uint16_t duration;
	unsigned char addr1[MAC_ADDR_LEN];
	unsigned char addr2[MAC_ADDR_LEN];
	unsigned char addr3[MAC_ADDR_LEN];
	uint16_t frag_seq;
};

struct authentication_management_frame
{
	uint16_t algorithm;
	uint16_t sequence;
	uint16_t status;
};

struct association_request_management_frame
{
	uint16_t capability;
	uint16_t listen_interval;
};

struct association_response_management_frame
{
	uint16_t capability;
	uint16_t status;
	uint16_t id;
};

struct beacon_management_frame
{
	unsigned char timestamp[TIMESTAMP_LEN];
	uint16_t beacon_interval;
	uint16_t capability;
};

struct llc_header
{
	uint8_t dsap;
	uint8_t ssap;
	uint8_t control_field;
	unsigned char org_code[3];
	uint16_t type;
};

struct dot1X_header
{
	uint8_t version;
	uint8_t type;
	uint16_t len;
};

struct eap_header
{
	uint8_t code;
	uint8_t id;
	uint16_t len;
	uint8_t type;
};

struct wfa_expanded_header
{
	unsigned char id[3];
	uint32_t type;
	uint8_t opcode;
	uint8_t flags;
};

struct tagged_parameter
{
	uint8_t number;
	uint8_t len;
};
#pragma pack()

#define MIN_BEACON_SIZE		(sizeof(struct radio_tap_header) + sizeof(struct dot11_frame_header) + sizeof(struct beacon_management_frame))

#endif
