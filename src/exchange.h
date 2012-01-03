#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <arpa/inet.h>
#include "defs.h"
#include "globule.h"
#include "send.h"
#include "misc.h"
#include "80211.h"

#define DATA_FRAME              0x02
#define SUBTYPE_DATA            0x00

#define MIN_PACKET_SIZE         (sizeof(struct radio_tap_header) + sizeof(struct dot11_frame_header) + sizeof(struct llc_header) + sizeof(struct dot1X_header))
#define EAP_PACKET_SIZE         (MIN_PACKET_SIZE + sizeof(struct eap_header))
#define WFA_PACKET_SIZE         (EAP_PACKET_SIZE + sizeof(struct wfa_expanded_header))

#define MAX_MESSAGE_RETRIES	3

enum wps_result do_wps_exchange();
enum wps_type process_packet(const u_char *packet, struct pcap_pkthdr *header);
enum wps_type process_wps_message(const void *data, size_t data_size);
int parse_nack(const void *data, size_t data_size);

#endif
