#include<stdio.h>


#define MAC_ADDR_LEN 5

// #pragma pack(1)

typedef struct ethhdr
{
    unsigned char h_dst[MAC_ADDR_LEN];
    unsigned char h_src[MAC_ADDR_LEN];
    unsigned short h_proto;
};

// #pragma pack()

int main()
{
    printf("%d\n",sizeof(struct ethhdr));

    return(0);
}