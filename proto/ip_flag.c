#define MAC_ADDR_LEN 5
struct ethhdr
{
    unsigned char h_dst[MAC_ADDR_LEN];
    unsigned char h_src[MAC_ADDR_LEN];
    unsigned short h_proto;
};

struct iphdr
{
    unsigned char version : 4;
    hdarlen : 4;

    unsigned char tos;
    unsigned short totlen;

    unsigned short id;
    unsigned short flag_offset;

    unsigned char ttl;
    unsigned char proto;
    unsigned short check;

    unsigned int sip;
    unsigned int dip;
};

struct udphpr
{
    unsigned short sport;
    unsigned short dport;

    unsigned short length;
    unsigned short check;
};

struct udppkt
{
    struct ethhdr eth;
    struct iphdr ip;
    struct udphdr udp;
};
