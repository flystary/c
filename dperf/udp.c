#include "udp.h"
#include "tcp.h"
#include "config.h"
#include "mbuf.h"
#include "mbuf_cache.h"
#include "net_stats.h"
#include "socket.h"
#include "tcp.h"
#include "version.h"
#include "loop.h"
#include "socket_timer.h"
#include "csum.h"


static char g_udp_data[MBUF_DATA_SIZE] = "hello dperf!!\n";

void udp_set_payload(struct config *cfg, int page_size)
{
    config_set_payload(cfg, g_udp, page_size, 1);
}

static inline void udp_change_dipv6(struct work_space *ws,  struct ip6_hdr *ip6h, struct udphdr *uh)
{
    ipaddr_t addr_old;
    ipaddr_t addr_new;
    struct ip_list *ip_list = NULL;
    
    ip_list = &ws->dip_list;
    addr_old.in6 = ip6h->ip6_dst;
    ip_list_get_next_ipv6(ip_list, &addr_new.in6);
    ip6h->ip6_dst = addr_new.in6;
    uh->check = csum_update_u128(uh->check, (uint32_t *)&addr_old, (uint32_t *)&addr_new);
}


static inline void udp_change_dipv4(struct work_space *ws,  struct iphdr *iph, struct udphdr *uh)
{
    uint32_t addr_old = 0;
    uint32_t addr_new = 0;
    struct ip_list *ip_list = NULL;

    ip_list = &ws->dip_list;
    addr_old = iph->daddr;
    ip_list_get_next_ipv4(ip_list, &addr_new);
    iph->daddr = addr_new;
    iph->check = csum_update_u32(iph->check, addr_old, addr_new);
    uh->check  = csum_update_u32(uh->check, addr_old, addr_new); 
}

static inline void udp_change_dip(struct work_space *ws, struct iphdr *iph, struct udphdr *uh)
{
    if (ws->ipv6) {
        udp_change_dipv6(ws, (struct ip6_hdr *)iph, uh);
    } else {
        udp_change_dipv4(ws, iph, uh);
    }
}


