#include "eth.h"

void eth_addr_to_str(const struct eth_addr *mac, char *str)
{
    const uint8_t *num = mac->bytes;

    sprintf(str, "%x:%x:%x:%x:%x:%x", num[0], num[1], num[2], num[3], num[4], num[5]);
}

int eth_addr_init(struct eth_addr *mac, const char *mac_str)
{
    int i = 0;
    int ret = 0;
    int num[ETH_ADDR_LEN];

    if (strlen(mac_str) != ETH_ADDR_STR_LEN) {
        return -1;
    }

    ret = sscanf(mac_str, "%x:%x:%x:%x:%x:%x", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    if (ret != 6) {
        return -1;
    }

    for (i = 0; i < ETH_ADDR_LEN; i++) {
        if (num[i] > 0xff) {
            return -1;
        }
        mac->bytes[i] = num[i];
    }

    return 0;
}
