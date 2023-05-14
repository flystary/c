#ifndef __ETH_H
#define __ETH_H


#include<arpa/inet.h>
#include<sys/types.h>
#include<rte_ether.h>
#include "dpdk.h"


#define ETH_ADDR_LEN
#define ETH_ADDR_STR_LEN


struct eth_addr {
	uint8_t bytes[ETH_ADDR_LEN];
} __attribute__((__packed__));


struct eth_hdr {
    struct eth_addr d_addr;
    struct eth_addr s_addr;
    uint16_t type;
} __attribute__((__packed__));

