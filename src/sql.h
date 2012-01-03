#ifndef _SQL_H_
#define _SQL_H_

#include <unistd.h>
#include <string.h>
#include <sqlite3.h>
#include <libwps.h>
#include "defs.h"
#include "globule.h"

#define BUSY_WAIT_PERIOD	100
#define REAVER_DATABASE		"/etc/reaver/reaver.db"
#define SETTINGS_TABLE		"auto"
#define HISTORY_TABLE		"history"
#define AP_TABLE		"survey"
#define DROP_TABLE		"DROP TABLE %s"
#define CREATE_TABLE		"CREATE TABLE %s (bssid TEXT PRIMARY KEY NOT NULL, essid TEXT, manufacturer TEXT, model_name TEXT, model_number TEXT, device_name TEXT, version INTEGER DEFAULT 0, state INTEGER DEFAULT 0, locked INTEGER DEFAULT 0, encryption INTEGER DEFAULT 0, probes INTEGER DEFAULT 0, rssi TEXT, complete INTEGER DEFAULT 0, rowid INTEGER NOT NULL)"

int sql_init(void);
int create_ap_table(void);
int update_probe_count(char *bssid);
int update_ap_power(char *bssid, int8_t ssi);
int update_history(char *bssid, char *essid, int attempts, char *key);
int mark_ap_complete(char *bssid);
int is_done(char *bssid);
int should_probe(char *bssid);
int update(char *bssid, char *essid, struct libwps_data *wps, int encryption);
int insert(char *bssid, char *essid, struct libwps_data *wps, int encryption, int rssi);
char *get_db_ssid(char *bssid);
char **auto_detect_settings(char *bssid, int *argc);
int sql_exec(char *query);
void *get(char *query, int *result_size, int *err_code);
char *sql_error_string(void);
void sql_cleanup(void);

#endif
