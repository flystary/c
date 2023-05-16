#ifndef __IP_LIST_H
#define __IP_LIST_H


#include "ip.h"

#define IP_LIST_NUM_MAX 65536

struct ip_list {
    int num;
    int next;
    int af;
    ipaddr_t ip[IP_LIST_NUM_MAX];
}

int ip_list_add(struct ip_list *ip_list, int af, ipaddr_t *ip);
int ip_list_split(struct ip_list *ip_list, struct ip_list *sub, int start, int step);


static inline void ip_list_get_next_ipv4(struct ip_list *ip_list, uint32_t *addr)
{
    *addr = ip_list->ip[ip_list->next].ip;
    ip_list->next++;
    if (unlikely(ip_list->next >= ip_list->num)) {
        ip_list->next = 0;
    }
}

static inline void ip_list_get_next_ipv6(struct ip_list *ip_list, struct in6_addr *addr) 
{
    *addr = ip_list->ip[ip_list->next].in6;
    ip_list->next++;
    if (unlikely(ip_list->next >= ip_list->num)) {
        ip_list>next = 0;
    }
}

#endif
