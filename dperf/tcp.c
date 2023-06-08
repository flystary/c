#include "tcp.h"
#include "udp.h"
#include "config.h"
#include "http.h"
#include "mbuf.h"
#include "net_stats.h"
#include "socket.h"
#include "version.h"
#include "socket_timer.h"
#include "loop.h"
#include "http_parse.h"


#define tcp_seq_lt(seq0, seq1) ((int)((seq0) - (seq1)) < 0)
#define tcp_seq_le(seq0, seq1) ((int)((seq0) - (seq1)) <= 0)
#define tcp_seq_gt(seq0, seq1) ((int)((seq0) - (seq1)) > 0)
#define tcp_seq_ge(seq0, seq1) ((int)((seq0) - (seq1)) >= 0)

static inline void tcp_process_rst(struct socket *sk, struct rte_mbuf *m)
{
#ifdef DPERF_DEBUG
    if (sk->log) {
        SOCKET_LOG(sk, "rst");
        MBUF_LOG(m, "rst");
    }
#endif
    if (sk->state != SK_CLOSED) {
        socket_close(sk);
    }
    mbuf_free(m);
}

