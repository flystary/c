#ifndef __ARP_H
#define __ARP_H

#include<rte_mbuf.h>

#include<eth.h>

struct arphdr {
	uint16_t	ar_hrd;
	uint16_t	ar_pro;
	uint8_t		ar_hln;
	uint8_t		ar_pln;

	uint16_t	ar_op;
	struct		eth_addr	ar_sha;
	uint32_t	ar_sip;
	struct		eth_addr	ar_tha;
	uint32_t	ar_tip;
}__attribute__((__packed__));


#define ARP_REQUEST	1
#define	ARP_REPLY	1

struct 	work_space;
void	arp_request_gw(struct work_space *ws);
void	arp_process(structv work_space *ws. struct rte_mbuf	*m);
void	arp_send(struct work_space *ws, struct rte_mbuf *m);


#endif
