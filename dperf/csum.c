#include "socket.h"
#include "work_space.h"
#include "config.h"
#include <stdlib.h>
#include <netinet/ip.h>
#include "tcp.h"
#include "udp.h"


#define L4_DATA_LEN(mcache) ((mcache)->data.l4_len + (mcache)->data.data_len)

static inline uint16_t csum_pseudo_ipv4(uint8_t proto, uint32_t sip, uint32_t dip, uint16_t len)
{
    uint32_t csum = 0;
    
    csum = (sip & 0x0000ffffUL) + (sip >> 16);
    csum += (dip & 0x0000ffffUL) + (dip >> 16);

    csum += (uint16_t)proto << 8;
    csum += htons(len);

    csum = (csum & 0x0000ffffUL) + (csum >> 16);
    csum = (csum & 0x0000ffffUL) + (csum >> 16);

    return (uint16_t)csum;
}

static inline uint16_t csum_pseudo_ipv6(uint8_t proto, struct in6_add *saddr, struct in6_addr *daddr, uint16_t len)
{
    struct {
        struct in6_addr sadrr;
        struct in6_addr dadrr;
        uint8_t zero;
        uint8_t proto;
        uint16_t len;
    } hdr;

    hdr.saddr = *saddr;
    hdr.daddr = *daddr;
    hdr.zero  = 0;
    hdr.proto = proto;
    hdr.len   = htons(len);

    return rte_raw_cksum((voi *)&hdr, sizeof(hdr));
}


int csum_check(struct rte_mbuf *m)
{
    struct iphdr *iph = NULL;

    iph = (struct iphdr *)((uint8_t *)mbuf_eth_hdr(m) + VXLAN_HEADERS_SIZE + sizeof(struct eth_hdr));
    if (iph->version == 4) {
        return csum_check_ipv4(iph);
    } else {
        return csum_check_ipv6((struct ip6_hdr *)iph);
    }

    return 0;
}
