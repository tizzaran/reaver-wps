#include "globule.h"

/* 
 * Reaver "watermark". md5("TNS").
 * Since both reaver and walsh use globule.c, and any future binaries will likely need access to globule.c as well, this seemed like a good place to put it... 
 */
unsigned char marker[] = "\xe3\x0f\x55\x5e\x5a\x24\xf0\x76\xa5\xd5\xbe\x70\xa4\x62\x52\x70";

int globule_init()
{
	int ret = 0;

	globule = malloc(sizeof(struct globals));
	if(globule)
	{
		memset(globule, 0, sizeof(struct globals));
		ret = 1;
	}

	return ret;
}
void globule_deinit()
{
	int i = 0;

	if(globule)
	{
		for(i=0; i<P1_SIZE; i++)
                {
                        if(globule->p1[i]) free(globule->p1[i]);
                }
                for(i=0; i<P2_SIZE; i++)
                {
                        if(globule->p2[i]) free(globule->p2[i]);
                }

		if(globule->wps) wps_deinit(globule->wps);
		if(globule->handle) pcap_close(globule->handle);
		if(globule->pin) free(globule->pin);
		if(globule->iface) free(globule->iface);
		if(globule->ssid) free(globule->ssid);
		if(globule->fp) fclose(globule->fp);
	
		free(globule);
	}
}

void set_log_file(FILE *fp)
{
	globule->fp = fp;
}
FILE *get_log_file(void)
{
	return globule->fp;
}

void set_last_wps_state(int state)
{
	globule->last_wps_state = state;
}
int get_last_wps_state()
{
	return globule->last_wps_state;
}

void set_p1_index(int index)
{
	if(index < P1_SIZE)
	{
		globule->p1_index = index;
	}
}
int get_p1_index()
{
	return globule->p1_index;
}

void set_p2_index(int index)
{
	if(index < P2_SIZE)
	{
		globule->p2_index = index;
	}
}
int get_p2_index()
{
	return globule->p2_index;
}

void set_p1(int index, char *value)
{
	if(index < P1_SIZE)
	{
		globule->p1[index] = strdup(value);
	}
}
char *get_p1(int index)
{
	if(index < P1_SIZE)
	{
		return globule->p1[index];
	}
	return NULL;
}

void set_p2(int index, char *value)
{
	if(index < P2_SIZE)
	{
		globule->p2[index] = strdup(value);
	}
}
char *get_p2(int index)
{
	if(index < P2_SIZE)
	{
		return globule->p2[index];
	}
	return NULL;
}

void set_key_status(enum key_state status)
{
	globule->key_status = status;
}
enum key_state get_key_status()
{
	return globule->key_status;
}

void set_delay(int delay)
{
	globule->delay = delay;
}
int get_delay()
{
	return globule->delay;
}

void set_fail_delay(int delay)
{
	globule->fail_delay = delay;
}
int get_fail_delay()
{
	return globule->fail_delay;
}

void set_validate_fcs(int validate)
{
	globule->validate_fcs = validate;
}
int get_validate_fcs(void)
{
	return globule->validate_fcs;
}

void set_recurring_delay(int delay)
{
	globule->recurring_delay = delay;
}
int get_recurring_delay()
{
	return globule->recurring_delay;
}

void set_recurring_delay_count(int value)
{
	globule->recurring_delay_count = value;
}
int get_recurring_delay_count()
{
	return globule->recurring_delay_count;
}

void set_lock_delay(int value)
{
	globule->lock_delay = value;
}
int get_lock_delay()
{
	return globule->lock_delay;
}

void set_ignore_locks(int value)
{
	globule->ignore_locks = value;
}
int get_ignore_locks()
{
	return globule->ignore_locks;
}

void set_eap_terminate(int value)
{
	globule->eap_terminate = value;
}
int get_eap_terminate()
{
	return globule->eap_terminate;
}

void set_max_pin_attempts(int value)
{
	globule->max_pin_attempts = value;
}
int get_max_pin_attempts()
{
	return globule->max_pin_attempts;
}

void set_max_num_probes(int value)
{
	globule->max_num_probes = value;
}
int get_max_num_probes()
{
	return globule->max_num_probes;
}

void set_rx_timeout(int value)
{
	globule->rx_timeout = value;
}
int get_rx_timeout()
{
	return globule->rx_timeout;
}

void set_timeout_is_nack(int value)
{
	globule->timeout_is_nack = value;
}
int get_timeout_is_nack()
{
	return globule->timeout_is_nack;
}

void set_m57_timeout(int value)
{
	globule->m57_timeout = value;
}
int get_m57_timeout()
{
	return globule->m57_timeout;
}

void set_out_of_time(int value)
{
	globule->out_of_time = value;
}
int get_out_of_time()
{
	return globule->out_of_time;
}

void set_debug(enum debug_level value)
{
	globule->debug = value;
}
enum debug_level get_debug()
{
	return globule->debug;
}

void set_eapol_start_count(int value)
{
	globule->eapol_start_count = value;
}
int get_eapol_start_count()
{
	return globule->eapol_start_count;
}

void set_fixed_channel(int value)
{
	globule->fixed_channel = value;
}
int get_fixed_channel()
{
	return globule->fixed_channel;
}

void set_auto_channel_select(int value)
{
	globule->auto_channel_select = value;
}
int get_auto_channel_select()
{
	return globule->auto_channel_select;
}

void set_auto_detect_options(int value)
{
	globule->auto_detect_options = value;
}
int get_auto_detect_options()
{
	return globule->auto_detect_options;
}

void set_wifi_band(int value)
{
	globule->wifi_band = value;
}
int get_wifi_band()
{
	return globule->wifi_band;
}

void set_opcode(enum wsc_op_code value)
{
	globule->opcode = value;
}
enum wsc_op_code get_opcode()
{
	return globule->opcode;
}

void set_eap_id(uint8_t value)
{
	globule->eap_id = value;
}
uint8_t get_eap_id()
{
	return globule->eap_id;
}

void set_ap_capability(uint16_t value)
{
	globule->ap_capability = value;
}
uint16_t get_ap_capability()
{
	return globule->ap_capability;
}

void set_channel(int channel)
{
	globule->channel = channel;
}
int get_channel(void)
{
	return globule->channel;
}

void set_bssid(unsigned char *value)
{
	memcpy((unsigned char *) &globule->bssid, value, MAC_ADDR_LEN);
}
unsigned char *get_bssid()
{
	return (unsigned char *) &globule->bssid;
}

void set_mac(unsigned char *value)
{
	memcpy((unsigned char *) &globule->mac, value, MAC_ADDR_LEN);
}
unsigned char *get_mac()
{
	return (unsigned char *) &globule->mac;
}

void set_ssid(char *value)
{
	if(globule->ssid)
	{
		free(globule->ssid);
		globule->ssid = NULL;
	}

	if(value)
	{
		if(strlen(value) > 0)
		{
			globule->ssid = strdup(value);
		}
	}
}
char *get_ssid()
{
	return globule->ssid;
}

void set_iface(char *value)
{
	if(value)
	{
		if(globule->iface)
		{
			free(globule->iface);
		}

		globule->iface = strdup(value);
	}
	else if(globule->iface)
	{
		free(globule->iface);
		globule->iface = NULL;
	}
}
char *get_iface()
{
	return globule->iface;
}

void set_pin(char *value)
{
	globule->pin = strdup(value);
}
char *get_pin()
{
	return globule->pin;
}

void set_nack_reason(enum nack_code value)
{
	globule->nack_reason = value;
}
enum nack_code get_nack_reason()
{
	return globule->nack_reason;
}

void set_handle(pcap_t *value)
{
	globule->handle = value;
}
pcap_t *get_handle()
{
	return globule->handle;
}

void set_wps(struct wps_data *value)
{
	globule->wps = value;
}
struct wps_data *get_wps()
{
	return globule->wps;
}
