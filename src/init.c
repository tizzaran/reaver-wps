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

#include "init.h"

/* 
 * Generates a wps_config structure which is passed to wps_init() to create
 * an initial wps_data structure.
 */
struct wps_data *initialize_wps_data()
{
	struct wps_config *wpsconf = NULL;
	struct wps_data *wps = NULL;
	struct wps_registrar_config *reg_conf = NULL;
	
	wpsconf = malloc(sizeof(struct wps_config));
	if(!wpsconf)
	{
		perror("malloc");
		goto end;
	}
	memset(wpsconf, 0, sizeof(struct wps_config));

	reg_conf = malloc(sizeof(struct wps_registrar_config));
	if(!reg_conf)
	{
		perror("malloc");
		goto end;
	}
	memset(reg_conf, 0, sizeof(struct wps_registrar_config));

	/* Configure ourselves as a registrar */
        wpsconf->registrar = 1;
	
	/* Allocate space for the wps_context structure member */
	wpsconf->wps = malloc(sizeof(struct wps_context));
	if(!wpsconf->wps)
	{
		perror("malloc");
		goto end;
	}
	memset(wpsconf->wps, 0, sizeof(struct wps_context));

	/* 
	 * Initialize the registrar sub-structure. This is necessary when calling
	 * wpa_supplicant functions to build registrar response payloads.
	 */
	wpsconf->wps->registrar = wps_registrar_init(wpsconf->wps, (const struct wps_registrar_config *) reg_conf);

	/* 
	 * In registrar mode, only the uuid wps_context member needs to be 
	 * populated in order to call wps_init(). If acting as an enrollee,
	 * the wps_device_data sub-structure must also be populated.
	 */
	if(os_get_random(wpsconf->wps->uuid, UUID_LEN) == -1)
	{
		memcpy(wpsconf->wps->uuid, DEFAULT_UUID, UUID_LEN);
	}

	wps = wps_init(wpsconf);

end:
	if(wpsconf) free(wpsconf);
	if(reg_conf) free(reg_conf);
	return wps;
}

/* Initializes pcap capture settings and returns a pcap handle on success, NULL on error */
pcap_t *capture_init(char *capture_source)
{
	pcap_t *handle = NULL;
	char errbuf[PCAP_ERRBUF_SIZE] = { 0 };
	
	handle = pcap_open_live(capture_source, BUFSIZ, 1, 0, errbuf);
	if(!handle)
	{
		handle = pcap_open_offline(capture_source, errbuf);
	}

	return handle;
}

