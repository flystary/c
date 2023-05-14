#ifdef 	__BOND_H
#define __BOND_H


#include<stdio.h>
#include<rte_eth_bond.h>

struct netif_port;
struct work_space;
int bond_cread(struct netif_port *port);
int bond_config_slaves(struct netif_port *port);
int bond_wait(struct netif_port *port);
void bond_broadcast(struct work_space *ws, struct rte_mbuf *m);

#endif
