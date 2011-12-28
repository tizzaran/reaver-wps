#include "misc.h"

/* Converts a raw MAC address to a colon-delimited string */
unsigned char *mac2str(unsigned char *mac, char delim)
{
	int i = 0, str_len = 0;
	int str_mult = 3;
	int buf_size = str_mult+1;
	unsigned char *str = NULL;
	unsigned char buf[4] = { 0 };	/* 4 == buf_size */

	str_len = (MAC_ADDR_LEN * str_mult) + 1;

	str = malloc(str_len);
	if(!str)
	{
		perror("malloc");
	} else {
		memset(str, 0, str_len);
	
		for(i=0; i<MAC_ADDR_LEN; i++)
		{
			memset((char *) &buf, 0, buf_size);
			snprintf((char *) &buf, buf_size, "%.2X%c", mac[i], delim);
			strncat((char *) str, (char *) &buf, str_mult);
		}
		memset(str+((MAC_ADDR_LEN*str_mult)-1), 0, 1);
	}

	return str;
}

/* Converts a colon-delimited string to a raw MAC address */
void str2mac(unsigned char *str, unsigned char *mac)
{
	char *delim_ptr = NULL, *num_ptr = NULL, *tmp_str = NULL;
	char delim = ':';
	int count = 0;

	tmp_str = strdup((char *) str);
	delim_ptr = num_ptr = tmp_str;

	while((delim_ptr = strchr(delim_ptr, delim)) && count < (MAC_ADDR_LEN-1))
	{
		memset(delim_ptr, 0, 1);
		mac[count] = strtol(num_ptr, NULL, 16);
		delim_ptr++;
		count++;
		num_ptr = delim_ptr;
	}
	mac[count] = strtol(num_ptr, NULL, 16);
	
	free(tmp_str);
	return;
}

/* Conditional printf wrapper */
void cprintf(enum debug_level level, const char *fmt, ...)
{
	va_list arg;

	if(level <= get_debug())
	{
		va_start(arg, fmt);
		vfprintf(get_log_file(), fmt, arg);
		va_end(arg);
	}

	fflush(get_log_file());
}

/* Daemonizes the process */
void daemonize(void)
{
	if(fork() > 0)
	{
		exit(EXIT_SUCCESS);
	}

	if(chdir("/") == 0)
	{
		setsid();
		umask(0);

		if(fork() > 0)
		{
			exit(EXIT_SUCCESS);
		}
	}
}
