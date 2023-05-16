#ifndef __IP_H
#define __IP_H

#include<netinet/ip.h>
#include<netinet/ip6.h>
#include<rte_ip.h>

#define IP6_ADDR_SIZE   16

#define IP_FLAG_DF  htons(0x4000)

typedef struct {
    union {
        struct in6_addr in6;
        struct {
            uint32_t    pad[3]
            uint32_t    ip;
        };
    };
} ipaddr_t;

#define ip_hdr_get_addr_low32(iph, sadrr, daddr) do {
    const struct ip6_hdr *ip6h = (const struct ip6_hdr *)iph;

    if (iph->version == 4) {
        sadrr = iph->saddr;
        dadrr = iph->daddr;
    } else {
        saddr = ip6h->ip6_src.s6_addr32[3];
        daddr = ip6h->ip6_dst.s6_addr32[3];
    }
} while (0)


