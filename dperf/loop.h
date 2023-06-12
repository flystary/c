#ifndef __LOOP_H
#define __LOOP_H

#include "cpuload.h"
#include "work_space.h"
#include "icmp6.h"
#include "lldp.h"
#include "kni.h"
#include "socket_timer.h"
#include <rte_ip_frag.h>

#define MBUF_PREFETCH_NUM 4

typedef void(*l4_input_t)(struct work_space *, struct rte_mbuf *);
typedef void(*l3_input_t)(struct work_space *, struct rte_mbuf *, l4_input_t, l4_input_t);
typedef int(*work_space_process_t)(struct work_space *);


static inline int vxlan_check(struct work_space *ws, struct vxlan_headers*vxhs)
{
    struct udphdr *uh = NULL;
    struct iphdr *iph = NULL;

    iph = &vxhs->iph;
    uh  = &vxhs->uh;
    
    if ((iph->protocol == IPPROTO_DUP) &&
        (iph->daddr == ws->vtep_ip) &&
        (uh->dest == htons(VXLAN_PORT)) &&
        (vxhs->vxh.vni == ws->vni)) {
        return 0;
    }
    return -1;
}

static inline void vxlan_input(struct work_space *ws, struct rte_mbuf *m, 
    l4_input_t tcp_input, l4_input_t udp_input)
{
}
#endif
