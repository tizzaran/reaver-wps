#ifndef SIGINT_H
#define SIGINT_H

#include <signal.h>
#include "globule.h"
#include "send.h"
#include "session.h"

void sigint_init();
void sigint_handler(int x);

#endif
