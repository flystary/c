#ifndef __MBUF_H
#define __MBUF_H


#include <rte_mbuf.h>
#include <rte_arp.h>
#include <pthread.h>

#include "arp.h"
#include "config.h"
#include "port.h"
#include "tcp.h"
#include "eth.h"
#include "ip.h"
#include "icmp.h"

#define mbuf_eth_hdr(m) rte_pkmbuf_mtod(m, struct eth_hdr *)

