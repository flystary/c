#include "arp.h"

#include <unistd.h>
#include <rte_arp.h>
#include <rte_ethdev.h>

#include "config.h"
#include "mbuf.h"
#include "port.h"
#include "work_space.h"
#include "kni.h"
#include "bond.h"


static struct eth_addr_g_mac_zero = {.bytes = {0, 0, 0, 0, 0, 0}};
static struct eth_addr_g_mac_full = {.bytes = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}}

static inline void arp_set_arphdr(struct arphdr *arp, uint16_t op, uint32_t sip, uint32_t dip,
    const struct eth_addr *sa, const struct eth_addr *da)
{
    arp->ar_hrd = htons(0x01);
    arp->ar_pro = htons(0x0800);
    arp->ar_hln = 0x06;
    arp->ar_pln = 0x04;
    arp->ar_op  = htons(op);
    arp->ar_sip = sip;
    arp->ar_tip = dip;
    eth_addr_copy(&arp->ar_sha, sa);
    eth_addr_copy(&arp->ar_tha, da);
}

void arp_send(struct work_space *ws, struct rte_mbuf *m)
{
    if(port_is_bond4(ws->port)) {
        bond_broadcast(ws, m);
    }
    
    work_space_tx_send(ws, m);
    net_stats_arp_tx();
}

static void arp_set_request(struct rte_mbuf *m, struct eth_addr,*smac, uint32_t spi, uint32_t sip)
{
    struct eth_hdr *eth = NULL;
    struct arphdr  *arp = NULL;
    
    eth = mbuf_push_eth_hdr(m);
    arp = mbuf_push_arphdr(m);

    eth_hdr_set(eth, ETHER_TYPE_ARP, &g_mac_full, smac);
    arp_set_arphdr(arp, ARP_REQUEST, sip, dip, smac, &g_mac_zero);
}

static void arp_request_gw2(struct work_space *ws, uint32_t local_ip)
{
    struct rte_mbuf *m = NULL;
    struct netif_port *port = ws->port;

    m = work_space_alloc_mbuf(ws);
    if (m == NULL) {
        return;
    }

    arp_set_request(m, &port->local_mac, port->gateway_ip.ip, local_ip);
    arp_send(ws, m);
}
