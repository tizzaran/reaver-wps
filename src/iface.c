#include "iface.h"

/* Populates globule->mac with the MAC address of the interface globule->iface */
int read_iface_mac()
{
	struct ifreq ifr;
	struct ether_addr *eth = NULL;
	int sock = 0, ret_val = 0;

	/* Need a socket for the ioctl call */
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
	if(sock != -1)
	{
		eth = malloc(sizeof(struct ether_addr));
		if(eth)
		{
			memset(eth, 0, sizeof(struct ether_addr));

			/* Prepare request */
			memset(&ifr, 0, sizeof(struct ifreq));
			strncpy(ifr.ifr_name, get_iface(), IFNAMSIZ);

			/* Do it */
			if(ioctl(sock, SIOCGIFHWADDR, &ifr) == 0)
			{
				set_mac((unsigned char *) &ifr.ifr_hwaddr.sa_data);
				ret_val = 1;
			}
		}

		close(sock);
	}

	return ret_val;
}

/* 
 * Goes to the next 802.11 channel.
 * This is mostly required for APs that hop channels, which usually hop between channels 1, 6, and 11.
 * We just hop channels until we successfully associate with the AP.
 * The AP's actual channel number is parsed and set by parse_beacon_tags() in 80211.c.
 */
int next_channel()
{
        static int i;
	int n = 0;
        int bg_channels[] = BG_CHANNELS;
	int an_channels[] = AN_CHANNELS;
	int *channels = NULL;

	/* Select the appropriate channels for the target 802.11 band */
	if(get_wifi_band() == AN_BAND)
	{
		channels = (int *) &an_channels;
		n = sizeof(an_channels) / sizeof(int);
	}
	else
	{
		channels = (int *) &bg_channels;
		n = sizeof(bg_channels) / sizeof(int);
	}

	/* Only switch channels if fixed channel operation is disabled */
	if(!get_fixed_channel())
	{
        	i++;

        	if((i >= n) || i < 0)
        	{
        	        i = 0;
        	}

        	return change_channel(channels[i]);
	}
	
	return 0;
}

/* Sets the 802.11 channel for the selected interface */
int change_channel(int channel)
{
        int skfd = 0, ret_val = 0;
        struct iwreq wrq;

        memset((void *) &wrq, 0, sizeof(struct iwreq));

        /* Open NET socket */
        if((skfd = iw_sockets_open()) < 0)
        {
                perror("iw_sockets_open");
        }
        else
        {
                /* Convert channel to a frequency */
                iw_float2freq((double) channel, &(wrq.u.freq));

                /* Fixed frequency */
                wrq.u.freq.flags = IW_FREQ_FIXED;

        	cprintf(VERBOSE, "[+] Switching %s to channel %d\n", get_iface(), channel);

                /* Set frequency */
                if(iw_set_ext(skfd, get_iface(), SIOCSIWFREQ, &wrq) >= 0)
                {
			set_channel(channel);
                        ret_val = 1;
                }

                iw_sockets_close(skfd);
        }

        return ret_val;
}
