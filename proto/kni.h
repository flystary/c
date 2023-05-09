#ifndef __KNI_H
#define __KNI_H


#include <rte_mbuf.h>

struct config;
struct work_space;

int  kni_start(struct config *cfg);
void  kni_stop(struct config *cfg);
void  kni_recv(struct work_space *ws, struct rte_mbuf *m);
void  kni_send(struct work_space *ws);

void  kni_broadcast(struct work_space *ws, struct rte_mbuf *m);
int   kni_link_up(struct config *cfg);


#define KNI_NAME_DEFAULT "dperf"
#endif
