#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <stdio.h>
#include <getopt.h>
#include "defs.h"
#include "iface.h"
#include "config.h"

int process_arguments(int argc, char **argv);
void init_default_settings(void);
void parse_recurring_delay(char *arg);
void parse_static_pin(char *pin);

#endif
