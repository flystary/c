#include <stdio.h>

#define MAC_ADDR_LEN 5
struct ethhdr
{
    unsigned char h_dst[MAC_ADDR_LEN];
    unsigned char h_src[MAC_ADDR_LEN];
    unsigned short h_proto;
};

struct iphdr
{
    unsigned char version:4;
                  hdarlen:4;

    unsigned char tos;
    unsigned short totlen;

};
