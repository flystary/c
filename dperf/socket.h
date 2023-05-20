#ifndef __SOCKET_H
#define __SOCKET_H

#include "config.h"
#include "tcp.h"
#include "ip.h"
#include "tick.h"
#include "net_stats.h"


enum {
    SK_CLOSED,
    SK_LISTEN,          /* disable a socket, client only */
    SK_SYN_SENT,        /* also UDP client send */
    SK_SYN_RECEIVED,    /* also UDP client recv */
    SK_ESTABLISHED,
    SK_CLOSE_WAIT, /* unused */
    SK_FIN_WAIT_1,
    SK_CLOSING,
    SK_LAST_ACK,
    SK_FIN_WAIT_2,
    SK_TIME_WAIT
};

extern const char *g_sk_states[];

#define RETRANSMIT_NUM_MAX          4
#define RETRANSMIT_TIMEOUT_SEC      2
#define RETRANSMIT_TIMEOUT          (TSC_PER_SEC * RETRANSMIT_TIMEOUT_SEC)
#define REQUEST_INTERVAL_DEFAULT    (TSC_PER_SEC * 60)


struct socket_node {
    struct socket_node *next;
    struct socket_node *prev;
};

struct socket {
    /*16bytes*/
    struct socket_node node;

    /*16bytes*/
    uint32_t    rcv_nxt;
    uint32_t    snd_nxt;
    uint32_t    snd_una;

    uint8_t     flags;
    uint8_t     state:4;
    uint8_t     retrans:3;
    uint8_t     keepaliv:1;
    uint16_t    log:1;
    uint16_t    keepalive_request_num:15;

    
    /*16bytes*/
    uint64_t    timer_tsc;
    uint16_t    csum_tcp_data;
    uint16_t    csum_ip;
    uint16_t    csum_ip_opt;
    uint16_t    csum_ip_data;


    /*16bytes*/
    uint32_t    laddr;
    uint32_t    faddr;
    uint16_t    iport;
    uint16_t    fport;
    union {
        uint16_t    csum_tcp;
        uint16_t    csum_udp;
    };
    uint16_t    csum_tcp_opt;

#ifdef HTTP_PARSE
    /*16bytes*/
    int64_t     http_length;
    uint8_t     http_parse_state;
    uint8_t     http_flags;
    uint8_t     http_ack;
#endif
};

struct socket_port_pool {
    uint32_t    num;
    uint32_t    next;
    struct socket base[0] __attribute__((__aligned__(CACHE_ALIGN_SIZE)));
};

struct socket_table {
    uint32_t    server_ip;
    uint16_t    port_num;
    uint16_t    port_min;
    uint16_t    port_max;

    uint8_t     client_hop;
    uint8_t     rss;
    uint8_t     rss_id;
    uint8_t     rss_num;

    struct socket_table *socket_table_hash[256]; /* server rss hash */
                     /*[client-ip][client-port][server-port]*/
    struct socket_port_table *ht[NETWORK_PORT_NUM];
    struct socket_pool socket_pool;
};

static inline void socket_node_init(struct socket_node *sn)
{
    sn->next    = sn;
    sn->prev    = sn;
}


static inline void socket_node_del(struct socket_node *sn)
{
    struct socket_node *prev = sn->prev;
    struct socket_node *next = sn->next;

    if (sn != next) {
        prev->next = next;
        next->prev = prev;
        socket_node_init(sn);
    }
}

static inline socket *socket_table_get_socket_rss(struct socket_table *st)
{
    struct socket *sk = NULL;
    struct socket socket_pool *sp = &st->socket_pool;

    while(1) {
        sk = &(sp->base[sp->next]);
        if (st->rss == RSS_AUTO) {
            sp->next++;
            if (((ntohs(sk->lport) % st->rss_num) != st->rss_id) || (sk->laddr == 0)) {
                if (sp->next >= sp->num) {
                    sp->next = 0;
                }
                continue
            }
            break;
        }

        if (sk->laddr != 0) {
            sp->next++;
            if (sp>next >= sp->num) {
                sp->next = 0;
            }
            break;
        } else if (st->rss == RSS_L3L4) {
            sp->next++;
            if (sp->next >= sp->num) {
                sp->next = 0;
            }
            continue;
        }
    }

    return sk;
}
