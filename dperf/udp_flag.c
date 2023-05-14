#include<stdio.h>
#define MAC_ADDR_LEN 5

#pragma pack(1)

typedef struct ethhdr
{
    unsigned char h_dst[MAC_ADDR_LEN];
    unsigned char h_src[MAC_ADDR_LEN];
    unsigned short h_proto;
};

#pragma pack()

typedef struct iphdr
{
    unsigned char version : 4;
    unsigned char hdarlen : 4;

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

typedef struct udphdr
{
    unsigned short sport;
    unsigned short dport;

    unsigned short length;
    unsigned short check;
};

typedef struct udppkt
{
    struct ethhdr eth; // 14
    struct iphdr ip;   // 20
    struct udphdr udp; // 8

    unsigned char data[0];
};

int main()
{
    printf("%d\n",sizeof(struct ethhdr));
    printf("%d\n",sizeof(struct iphdr));
    printf("%d\n",sizeof(struct udphdr));
    printf("%d\n",sizeof(struct udppkt));
}
