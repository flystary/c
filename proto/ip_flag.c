#define MAC_ADDR_LEN 5

#pragma pack(1)

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

    unsigned short id;
    unsigned short flag_offset;

    unsigned char ttl;
    unsigned char proto;
    unsigned short check;

    unsigned int sip;
    unsigned int dip;
};

struct udphdr
{
    unsigned short sport;
    unsigned short dport;

    unsigned short length;
    unsigned short check;
};

struct udppkt
{
    struct ethhdr eth; //
    struct iphdr ip;   // 20
    struct udphdr udp; // 8

    unsigned char data[0];
};

int mian()
{
    printf("%d\n", sizeof(ethhdr));
    printf("%d\n", sizeof(iphdr));
    printf("%d\n", sizeof(udphdr));
    printf("%d\n", sizeof(udppkt));

    return 0;
}