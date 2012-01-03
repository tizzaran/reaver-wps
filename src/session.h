#ifndef SESSION_H
#define SESSION_H

#include <sys/types.h>
#include <sys/stat.h>
#include "defs.h"
#include "misc.h"
#include "globule.h"
#include "sql.h"
#include "config.h"

#define MAX_LINE_SIZE	128
#define CONF_EXT	"wpc"

#define P1_STR_LEN	4
#define P2_STR_LEN      3
#define P1_READ_LEN     (P1_STR_LEN + 2)        /* Read lengths == (strlen + new line + null byte) */
#define P2_READ_LEN     (P2_STR_LEN + 2)

int restore_session();
int save_session();
int configuration_directory_exists();

#endif
