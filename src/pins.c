#include "pins.h"

/* Builds a WPS PIN from the key tables */
char *build_wps_pin()
{
        char *key = NULL, *pin = NULL;
        int pin_len = PIN_SIZE + 1;

        pin = malloc(pin_len);
        key = malloc(pin_len);
        if(pin && key)
        {
                memset(key, 0, pin_len);
                memset(pin, 0, pin_len);

                /* Generate a 7-digit pin from the given key index values */
                snprintf(key, pin_len, "%s%s", get_p1(get_p1_index()), get_p2(get_p2_index()));

                /* Generate and append the pin checksum digit */
                snprintf(pin, pin_len, "%s%d", key, wps_pin_checksum(atoi(key)));

                free(key);
        }

        return pin;
}

/* 
 * Remove the last WPS pin (if any), build the next WPS pin in the p1 and p2 arrays, 
 * and populate the wps structure with the new pin.
 */
char *build_next_pin()
{
        char *pin = NULL;
        struct wps_data *wps = get_wps();

        /* Remove previous pin */
        wps_registrar_invalidate_pin(wps->wps->registrar, wps->uuid_e);

        /* Build a new pin */
        pin = build_wps_pin();
        if(pin)
        {
                /* Add the new pin */
                if(wps_registrar_add_pin(wps->wps->registrar, NULL, (const u8 *) pin, PIN_SIZE, 0) != 0)
                {
                        free(pin);
                        pin = NULL;
                }
        }

        return pin;
}

/* Randomize the p1 and p2 pin arrays */
void randomize_pins()
{
        int i = 0, index = 0;

        srand(time(NULL));

        while(i < P1_SIZE)
        {
                index = (rand() % P1_SIZE);

                if(!k1[index].randomized)
                {
                        set_p1(i, k1[index].key);
                        k1[index].randomized = 1;
                        i++;
                }
        }

        i = 0;

        while(i < P2_SIZE)
        {
                index = (rand() % P2_SIZE);

                if(!k2[index].randomized)
                {
                        set_p2(i, k2[index].key);
                        k2[index].randomized = 1;
                        i++;
                }
        }

        return;
}

