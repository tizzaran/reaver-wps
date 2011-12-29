/*
 * Reaver - Command line processing functions
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#include "argsparser.h"

/* Processes Reaver command line options */
int process_arguments(int argc, char **argv)
{
	int ret_val = EXIT_SUCCESS;
	char c = 0;
	int long_opt_index = 0;
	char bssid[MAC_ADDR_LEN] = { 0 };
	char mac[MAC_ADDR_LEN] = { 0 };
	char *short_options = "b:e:m:i:t:d:c:T:x:r:g:l:o:5ELfnqvDh";
	struct option long_options[] = {
		{ "interface", required_argument, NULL, 'i' },
		{ "bssid", required_argument, NULL, 'b' },
		{ "essid", required_argument, NULL, 'e' },
		{ "mac", required_argument, NULL, 'm' },
		{ "timeout", required_argument, NULL, 't' },
		{ "m57-timeout", required_argument, NULL, 'T' },
		{ "delay", required_argument, NULL, 'd' },
		{ "lock-delay", required_argument, NULL, 'l' },
		{ "ignore-locks", required_argument, NULL, 'L' },
		{ "fail-wait", required_argument, NULL, 'x' },
		{ "channel", required_argument, NULL, 'c' },
		{ "recurring-delay", required_argument, NULL, 'r' },
		{ "max-attempts", required_argument, NULL, 'g' },
		{ "out-file", required_argument, NULL, 'o' },
		{ "eap-terminate", no_argument, NULL, 'E' },
		{ "fixed", no_argument, NULL, 'f' },
		{ "daemonize", no_argument, NULL, 'D' },
		{ "5ghz", no_argument, NULL, '5' },
		{ "nack", no_argument, NULL, 'n' },
		{ "quiet", no_argument, NULL, 'q' },
		{ "verbose", no_argument, NULL, 'v' },
		{ "help", no_argument, NULL, 'h' },
		{ 0, 0, 0, 0 }
	};

	/* Since this function may be called multiple times, be sure to set opt index to 0 each time */
	optind = 0;

	while((c = getopt_long(argc, argv, short_options, long_options, &long_opt_index)) != -1)
        {
                switch(c)
                {
                        case 'i':
                                set_iface(optarg);
                                break;
                        case 'b':
                                str2mac((unsigned char *) optarg, (unsigned char *) &bssid);
                                set_bssid((unsigned char *) &bssid);
                                break;
                        case 'e':
                                set_ssid(optarg);
                                break;
                        case 'm':
                                str2mac((unsigned char *) optarg, (unsigned char *) &mac);
                                set_mac((unsigned char *) &mac);
                                break;
                        case 't':
                                set_rx_timeout(atoi(optarg));
                                break;
                        case 'T':
                                set_m57_timeout(strtof(optarg, NULL) * SEC_TO_US);
                                break;
                        case 'c':
                                change_channel(strtod(optarg, NULL));
                                set_fixed_channel(1);
                                break;
                        case '5':
                                set_wifi_band(AN_BAND);
                                break;
                        case 'd':
                                set_delay(atoi(optarg));
                                break;
                        case 'l':
                                set_lock_delay(atoi(optarg));
                                break;
                        case 'L':
                                set_ignore_locks(1);
                                break;
			case 'o':
				set_log_file(fopen(optarg, "w"));
				break;
                        case 'x':
                                set_fail_delay(atoi(optarg));
                                break;
                        case 'r':
                                parse_recurring_delay(optarg);
                                break;
                        case 'g':
                                set_max_pin_attempts(atoi(optarg));
                                break;
                        case 'D':
				daemonize();
				break;
			case 'E':
                                set_eap_terminate(1);
                                break;
                        case 'n':
                                set_timeout_is_nack(0);
                                break;
                        case 'f':
                                set_fixed_channel(1);
                                break;
                        case 'v':
                                set_debug(get_debug() + 1);
                                break;
                        case 'q':
                                set_debug(CRITICAL);
                                break;
                        default:
                                ret_val = EXIT_FAILURE;
                }
        }

	return ret_val;
}

/* Initialize some basic config settings */
void init_default_settings(void)
{
	set_log_file(stdout);
        set_delay(DEFAULT_DELAY);
        set_lock_delay(DEFAULT_LOCK_DELAY);
        set_debug(INFO);
        set_auto_channel_select(1);
        set_timeout_is_nack(1);
        set_wifi_band(BG_BAND);
}

/* Parses the recurring delay optarg */
void parse_recurring_delay(char *arg)
{
        char *x = NULL, *y = NULL;

        x = strdup(arg);
        y = strchr(x, ':');

        if(y)
        {
                memset(y, 0, 1);
                y++;

                set_recurring_delay_count(atoi(x));
                set_recurring_delay(atoi(y));
        }

        free(x);
}

