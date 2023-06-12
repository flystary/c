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



#endif
