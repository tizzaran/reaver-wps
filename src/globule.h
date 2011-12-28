#ifndef GLOBULE_H
#define GLOBULE_H

#include "defs.h"

struct globals
{
        int last_wps_state;             /* Holds the previous WPS state as stored in wps->state */

        int p1_index;                   /* Index into p1 array for building WPS pins */

        int p2_index;                   /* Index into p2 array for building WPS pins */

        char *p1[P1_SIZE];              /* Array of all possible values for the firt half of the pin */

        char *p2[P2_SIZE];              /* Array of all possible values for the second half of the pin */

        enum key_state key_status;      /* Indicates the status of the key cracking: KEY1_WIP | KEY2_WIP | KEY_DONE */

        int delay;                      /* Seconds to sleep in between key attempts */

        int fail_delay;                 /* Seconds to sleep after WARN_FAILURE_COUNT WPS exchange failures */

        int recurring_delay;            /* Sleep recurring_delay seconds for every recurring_delay_count attempts */

	int lock_delay;			/* Sleep lock_delay seconds when wpscrack detects that the AP has locked WPS pin attempts */

	int ignore_locks;		/* Ignore locked state */

        int recurring_delay_count;	/* Enter a recurring delay after recurring_delay_count pin attempts */

        int eap_terminate;              /* Experimental */

        int max_pin_attempts;           /* Maximum number of pin attempts */

        int rx_timeout;                 /* Receive timeout period (seconds) */

        int timeout_is_nack;            /* Treat M5/M7 receive timeouts as NACKs (only needed for shoddy WPS implementations) */

        int m57_timeout;                /* Timeout period for receiving an M5/M7 response (uSeconds) */

        int out_of_time;                /* Set to 1 when sigalrm sounds */

        enum debug_level debug;         /* Current debug level: INFO | CRITICAL | WARNING | VERBOSE */

        int eapol_start_count;          /* Tracks how many times in a row we've attempted to start and EAP session */

        int fixed_channel;              /* Disables channel hopping if set */

	int auto_channel_select;	/* Diables automatic parsing and changing of the current channel number, as specified in the AP's beacon packet */

	int auto_detect_options;	/* If true, Reaver will auto detect the best command line options for the attack */

	int wifi_band;			/* Determines if we use the A/N bands or B/G bands */

	int channel;			/* Holds the current channel number */

	int max_num_probes;		/* Maximum number of probe requests to send to an AP during survey mode */
	
	int validate_fcs;		/* If 1, validate each packet's FCS. If 0, process packets even with invalid FCS. */

        enum wsc_op_code opcode;        /* WFA opcode, received by exchange.c and used by builder.c */

        uint8_t eap_id;                 /* Tracks the EAP ID value for building EAP repsonse headers */

        uint16_t ap_capability;         /* Capability information of the target AP as specified in the AP's beacon packets */

        unsigned char bssid[MAC_ADDR_LEN];      /* Target BSSID */

        unsigned char mac[MAC_ADDR_LEN];                /* Source MAC address */

	FILE *fp;			/* Handle to log file */

        char *ssid;                     /* Target SSID */

        char *iface;                    /* Interface name */

        char *pin;                      /* Pointer to the recovered WPS pin value */

        enum nack_code nack_reason;     /* Stores the nack code for the last received WSC_NACK message */

        pcap_t *handle;                 /* Pcap handle */

        struct wps_data *wps;           /* 
					 * wpa_supplicant's wps_data structure, needed for almost all wpa_supplicant
                                         * function calls.
                                         */
} *globule;

int globule_init();
void globule_deinit();
void set_log_file(FILE *fp);
FILE *get_log_file(void);
void set_last_wps_state(int state);
int get_last_wps_state();
void set_p1_index(int index);
int get_p1_index();
void set_p2_index(int index);
int get_p2_index();
void set_p1(int index, char *value);
char *get_p1(int index);
void set_p2(int index, char *value);
char *get_p2(int index);
void set_key_status(enum key_state status);
enum key_state get_key_status();
void set_delay(int delay);
int get_delay();
void set_fail_delay(int delay);
int get_fail_delay();
void set_validate_fcs(int validate);
int get_validate_fcs(void);
void set_recurring_delay(int delay);
int get_recurring_delay();
void set_recurring_delay_count(int value);
int get_recurring_delay_count();
void set_lock_delay(int value);
int get_lock_delay();
void set_ignore_locks(int value);
int get_ignore_locks();
void set_eap_terminate(int value);
int get_eap_terminate();
void set_max_pin_attempts(int value);
int get_max_pin_attempts();
int get_max_num_probes();
void set_max_num_probes(int value);
void set_rx_timeout(int value);
int get_rx_timeout();
void set_timeout_is_nack(int value);
int get_timeout_is_nack();
void set_m57_timeout(int value);
int get_m57_timeout();
void set_out_of_time(int value);
int get_out_of_time();
void set_debug(enum debug_level value);
enum debug_level get_debug();
void set_eapol_start_count(int value);
int get_eapol_start_count();
void set_fixed_channel(int value);
int get_fixed_channel();
void set_auto_channel_select(int value);
int get_auto_channel_select();
void set_auto_detect_options(int value);
int get_auto_detect_options();
void set_wifi_band(int value);
int get_wifi_band();
void set_opcode(enum wsc_op_code value);
enum wsc_op_code get_opcode();
void set_eap_id(uint8_t value);
uint8_t get_eap_id();
void set_ap_capability(uint16_t value);
uint16_t get_ap_capability();
void set_bssid(unsigned char *value);
unsigned char *get_bssid();
void set_mac(unsigned char *value);
unsigned char *get_mac();
void set_channel(int channel);
int get_channel(void);
void set_ssid(char *value);
char *get_ssid();
void set_iface(char *value);
char *get_iface();
void set_pin(char *value);
char *get_pin();
void set_nack_reason(enum nack_code value);
enum nack_code get_nack_reason();
void set_handle(pcap_t *value);
pcap_t *get_handle();
void set_wps(struct wps_data *value);
struct wps_data *get_wps();

#endif
