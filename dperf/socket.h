#ifndef __SOCKET_H
#define __SOCKET_H

#include "config.h"
#include "tcp.h"
#include "ip.h"
#include "tick.h"
#include "net_stats.h"


enum {
    SK_CLOSED,
    SK_LISTEN,
    SK_SYN_SENT,
}
