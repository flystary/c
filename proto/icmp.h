#ifndef __ICMP_H_
#define	__ICMP_H_


#include <rte_mbuf.h>
#include <netinet/ip_icmp.h>


struct 	work_space;
void	icmp_process(struct work_space *ws, struct rte_mbuf *m);

#endif
