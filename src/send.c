#include "send.h"

/* Initiate the WPS session with an EAPOL START packet */
int send_eapol_start()
{
	const void *packet = NULL;
	size_t packet_len = 0;
	int ret_val = 0;

	packet = build_eapol_start_packet(&packet_len);

	if(packet)
	{
		ret_val = send_packet(packet, packet_len);
		free((void *) packet);
	}

	/* 
	 * This is used to track how many times an EAPOL START request is sent
	 * in a row.
	 *  
	 * It is cleared by the process_packets() function when an EAP identity
	 * resquest is received.
	 * 
	 * If it reaches EAPOL_START_MAX_TRIES, do_wps_exchange() will notify
	 * the user.
	 */
	set_eapol_start_count(get_eapol_start_count() + 1);

	return ret_val;
}

/* Send an identity response packet */
int send_identity_response()
{
	const void *packet = NULL, *identity = NULL;
	size_t packet_len = 0;
	int ret_val = 0;

	identity = WFA_REGISTRAR;

	packet = build_eap_packet(identity, strlen(identity), &packet_len);

	if(packet)
	{
		ret_val = send_packet(packet, packet_len);
		free((void *) packet);
	}

	return ret_val;
}

/* Send the appropriate WPS message based on the current WPS state (globule->wps->state) */
int send_msg()
{
	int ret_val = 0;
	const struct wpabuf *msg = NULL;
	unsigned char *payload = NULL;
        const void *packet = NULL;
        size_t packet_len = 0;
        uint16_t payload_len = 0;
	enum wsc_op_code opcode = 0;
	struct wps_data *wps = get_wps();

	/* 
	 * Get the next message we need to send based on the data retrieved 
	 * from wps_registrar_process_msg (see exchange.c).
	 */
        msg = wps_registrar_get_msg(wps, &opcode);
	set_opcode(opcode);
        if(msg)
        {
		/* Get a pointer to the actual data inside of the wpabuf */
                payload = (unsigned char *) wpabuf_head(msg);
                payload_len = (uint16_t) msg->used;
		
		/* Build and send an EAP packet with the message payload */
                packet = build_eap_packet(payload, payload_len, &packet_len);
		if(packet)
		{
			if(send_packet(packet, packet_len))
			{
				ret_val = 1;
			} else {
				free((void *) packet);
			}
		}

		wpabuf_free((struct wpabuf *) msg);
        }

	return ret_val;
}

/* 
 * Send a WSC_NACK message followed by an EAP failure packet.
 * This is only called when completely terminating a cracking session.
 */
void send_termination()
{
	const void *data = NULL;
	size_t data_size = 0;

	data = build_eap_failure_packet(&data_size);
	if(data)
	{
		send_packet(data, data_size);
		free((void*) data);
	}
}

/* Send a WSC_NACK message */
void send_wsc_nack()
{
	struct wps_data *wps = get_wps();

	wps->state = SEND_WSC_NACK;
	send_msg();
}

/* 
 * All transmissions are handled here to ensure that the receive timer 
 * is always started immediately after a packet is transmitted.
 */
int send_packet(const void *packet, size_t len)
{
	int ret_val = 0;

	if(pcap_inject(get_handle(), packet, len) == len)
	{
		ret_val = 1;
	}
		
	start_timer();

	return ret_val;
}
