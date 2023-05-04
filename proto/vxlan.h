#ifndef __VXLAN_H
#define __VXLAN_H

#include "eth.h"
#include "ip.h"
#include "udp.h"
#include "ip_range.h"

struct vxlan {
	int vni;
	struct eth_addr inner_smac;
	struct eth_addr inner_dmac;
	struct ip_range vtep_local;
	struct ip_range vtep_remote;
};

struct vxlan_header {
	uint32_t flags:8;
	uint32_t reserved0:24;
	uint32_t vni:24;
	uint32_t reserved1:8;
};

struct vxlan_headers {
	struct eth_hdr eh;
	struct iphdr   iph;
	struct udphdr  uh;
	struct vxlan_hearder vxh;
} __attribute__((__packed__));


#define VXLAN_HEADERS_SIZE sizeof(struct vxlan_headers)
#define VNI_MAX			   0xffffff
#define VXLAN_PORT		   4789
#define VXLAN_SPORT		   6666
#define VXLAN_HTOP		   htonl((vni) << 8 )

struct mbuf_data;
struct work_space;
int vxlan_encapsulate(struct mbuf_data *mdata, struct work_space *ws);

#endif
