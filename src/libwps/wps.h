/*
 * LibWPS
 * Copyright (c) 2011, Tactical Network Solutions, Craig Heffner <cheffner@tacnetsol.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef WPS_H
#define WPS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

#define WPS_TAG_NUMBER          0xDD
#define WPS_VENDOR_ID           "\x00\x50\xF2\x04"
#define WPS_VENDOR_ID_SIZE      4
#define VENDOR_ID_OFFSET        2

#define RADIO_TAP_VERSION       0
#define FAKE_RADIO_TAP_HEADER   "\x00\x00\x00\x00\x00\x00\x00\x00"

#define TIMESTAMP_LEN		8
#define MAC_ADDR_LEN		6

enum wps_el_number
{
        VERSION = 0x104A,
        STATE = 0x1044,
        LOCKED = 0x1057,
        MANUFACTURER = 0x1021,
        MODEL_NAME = 0x1023,
        MODEL_NUMBER = 0x1024,
        DEVICE_NAME = 0x1011,
        SSID = 0x1045,
        UUID = 0x1047,
        SERIAL = 0x1042,
        SELECTED_REGISTRAR = 0x1041,
        RESPONSE_TYPE = 0x103B,
        PRIMARY_DEVICE_TYPE = 0x1054,
        CONFIG_METHODS = 0x1008,
        RF_BANDS = 0x103C,
        OS_VERSION = 0x102D
};

struct wps_data
{
        uint8_t version;
        uint8_t state;
        uint8_t locked;
        char *manufacturer;
        char *model_name;
        char *model_number;
        char *device_name;
        char *ssid;
        char *uuid;
        char *serial;
        char *selected_registrar;
        char *response_type;
        char *primary_device_type;
        char *config_methods;
        char *rf_bands;
        char *os_version;
};

struct wps_element
{
        enum wps_el_number number;
        char *name;
};

struct data_element
{
        uint16_t type;
        uint16_t len;
};

struct tagged_parameter
{
        uint8_t number;
        uint8_t len;
};

struct radio_tap_header
{
        uint8_t revision;
        uint8_t pad;
        uint16_t len;
        uint32_t present_flags;
};

struct dot11_frame_header
{
        uint16_t fc;
        uint16_t duration;
        unsigned char addr1[MAC_ADDR_LEN];
        unsigned char addr2[MAC_ADDR_LEN];
        unsigned char addr3[MAC_ADDR_LEN];
        uint16_t frag_seq;
};

struct management_frame
{
        unsigned char timestamp[TIMESTAMP_LEN];
        uint16_t beacon_interval;
        uint16_t capability;
};


int parse_wps_parameters(const u_char *packet, size_t len, struct wps_data *wps);
int parse_wps_tag(const u_char *tags, size_t len, struct wps_data *wps);
unsigned char *get_wps_data(const u_char *data, size_t len, size_t *tag_len);
unsigned char *get_wps_data_element(const u_char *data, size_t len, uint16_t type, size_t *el_len);
int has_rt_header(const u_char *packet, size_t len);
const u_char *radio_header(const u_char *packet, size_t len);
char *hex2str(unsigned char *hex, int len);

#endif
