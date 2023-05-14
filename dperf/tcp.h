#ifndef __TCP_H
#define __TCP_H


#include <stdint.h>
#include <netinet/ip.h>

#define __FAVOR_BSD
#include <netinet/tcp.h>
#undef __FAVOR_BSD
#include <rte_mempool.h>
#include <rte_mbuf.h>
#include <rte_common.h>


struct work_space;
int  tcp_init(struct work_space *ws);
void tcp_drop(__re_unused struct work_space *ws, struct rte_mbuf *m);

#ifdef HTTP_PARSE
int tcp_ack_delay_flush(struct work_space *ws);
#else
#define tcp_ack_delay_flush(ws) do{}while(0)


#endif
#endif
