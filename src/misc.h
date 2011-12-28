#ifndef MISC_H
#define MISC_H

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "defs.h"
#include "globule.h"

unsigned char *mac2str(unsigned char *mac, char delim);
void str2mac(unsigned char *str, unsigned char *mac);
void cprintf(enum debug_level level, const char *fmt, ...);
void daemonize(void);

#endif
