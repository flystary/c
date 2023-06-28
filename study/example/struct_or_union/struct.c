#include <stdio.h>

struct SoftArray
{
    int     len;
    int     array[];
};


int main()
{
    printf("%d\r\n", sizeof(struct SoftArray));

    return 0;
}
