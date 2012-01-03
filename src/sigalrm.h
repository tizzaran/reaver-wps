#ifndef SIGALRM_H
#define SIGALRM_H

#include <signal.h>
#include <sys/time.h>

#include "defs.h"
#include "globule.h"
#include "misc.h"

void sigalrm_init();
void start_timer();
void stop_timer();
void alarm_handler(int x);

#endif
