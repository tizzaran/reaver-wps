#ifndef DOT11_H
#define DOT11_H

#include "defs.h"
#include "globule.h"
#include "builder.h"
#include "iface.h"
#include "crc.h"
#include "libwps.h"

#define AUTH_OK                 1
#define ASSOCIATE_OK            2

#define ASSOCIATE_WAIT_TIME     1               /* Seconds */
#define ASSOCIATION_SUCCESS     0x0000
#define AUTHENTICATION_SUCCESS  0x0000

#define DEAUTH_REASON_CODE      "\x03\x00"
#define DEAUTH_REASON_CODE_SIZE 2

#define FC_AUTHENTICATE         0x00B0
#define FC_ASSOCIATE            0x0000
#define FC_DEAUTHENTICATE       0x00C0

#define FC_FLAGS_MASK           0xFF
#define FC_VERSION_MASK         0x03
#define FC_TYPE_MASK            0x0C
#define FC_TO_DS                0x01
#define FC_FROM_DS              0x02
#define FC_MORE_FRAG            0x04
#define FC_RETRY                0x08
#define FC_PWR_MGT              0x10
#define FC_MORE_DATA            0x20
#define FC_WEP                  0x40
#define FC_ORDER                0x80

#define RADIO_TAP_VERSION	0x00
#define FAKE_RADIO_TAP_HEADER	"\x00\x00\x00\x00\x00\x00\x00\x00"

#define MAX_AUTH_TRIES          5

#define MIN_AUTH_SIZE           (sizeof(struct radio_tap_header) + sizeof(struct dot11_frame_header) + sizeof(struct authentication_management_frame))

#define SUBTYPE_AUTHENTICATION  0x0B
#define SUBTYPE_ASSOCIATION     0x01

const u_char *next_packet(struct pcap_pkthdr *header);
void read_ap_beacon();
int is_wps_locked();
int reassociate();
void deauthenticate();
void authenticate();
void associate();
int associate_recv_loop();
enum encryption_type supported_encryption(const u_char *packet, size_t len);
int parse_beacon_tags(const u_char *data, size_t len);
unsigned char *parse_ie_data(const u_char *data, size_t len, uint8_t tag_number, size_t *ie_len, size_t *ie_offset);
int is_target(struct dot11_frame_header *frame_header);
int check_fcs(const u_char *packet, size_t len);
int has_rt_header(void);
const u_char *radio_header(const u_char *packet, size_t len);

#endif
