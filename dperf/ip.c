#include "ip.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>



int ipaddr_init(ipaddr_t *ip, const char *str)
{
    int ret = 0;
    int af  = -1;

    memset(ip, 0, sizeof(ipaddr_t));
    if (strchr(str, ':')) {
        af  = AF_INET6;
        ret = inet_pton(af, str, &ip->in6); 
    } else {
        af  = AF_INET;
        ret = inet_pton(af, str, &ip->ip);
    }

    if (ret == 1) {
        return af;
    }

    return -1;
}

void ipaddr_inc(ipaddr_t *ip, uint32_t n)
{
    uint32_t addr = 0;

    addr = ntohl(ip->ip) + n;
    ip->ip = htonl(addr);
}

