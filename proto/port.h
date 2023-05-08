#ifndef __PORT_H
#define	__PORT_H


#include <stdbool.h>
#include <stdlib.h>
#include <rte_kni.h>


#include "ip.h"
#include "ip_range.h"
#include "eth.h"
#include "vxlan.h"

#define THREAD_NUM_MAX      64
#define NETIF_PORT_MAX      4
#define PCI_LEN             12

#define NB_RXD              4096
#define NB_TXD              4096

#define RX_BURST_MAX        NB_RXD
#define TX_QUEUE_SIZE       NB_TXD

#define TX_BURST_MAX        1024
#define TX_BURST_DEFAULT    8

#define BOND_SLAVE_MAX      4
#define PCI_NUM_MAX         BOND_SLAVE_MAX
#define BOND_NAME_MAX       32
#define BOND_WAIT_SEC       16


struct netif_port {
	int 	id;
	int 	queue_num;
	int		socket;
	bool	enable;
	
};
