#ifndef __DPDK_H
#define __DPDK_H

#include <rte_version.h>

#if RTE_VERSION < RTE_VERSION_NUM(21, 0, 0, 0)>
#define RTE_ETH_MQ_RX_NONE              ETH_MQ_RX_NONE
#define RTE_ETH_MQ_TX_NONE              ETH_MQ_TX_NONE
