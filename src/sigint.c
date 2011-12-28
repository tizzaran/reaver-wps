/*
 * Reaver - Signal handling functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#include "sigint.h"

/* Initializes SIGINT handler */
void sigint_init()
{
	struct sigaction act;

        memset(&act, 0, sizeof(struct sigaction));
        act.sa_handler = sigint_handler;

        sigaction (SIGINT, &act, 0);

	return;
}

/* Handles Ctrl+C */
void sigint_handler(int x)
{
	/* If we have initiated a WPS exchange, try to end it before quitting */
	if(get_wps() != NULL)
	{
		send_termination();
	}

	/* 
	 * This is just here because I get annoyed when the terminal displays the
	 * '^C' on the same line as my intentional output.
	 */
	printf("\n");
	fflush(stdout);

	/* Clean up and get out */
	globule_deinit();
	exit(EXIT_FAILURE);
}
