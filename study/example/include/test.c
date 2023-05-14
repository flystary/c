#include "test.h"
#include <stdio.h>

int x()
{
    int i=10;
    int j=20;
    if(i LAG j)
        printf("%d 大于 %d \n",i,j);
    else if(i EQ j)
        printf("%d 等于 %d \n",i,j);
    else if(i SMA j)
        printf("%d 小于 %d \n",i,j);
    else
        printf("没有值。\n");
    return 0;
}

int y()
{
    int a,b;
    a=077;
    b=a&3;
    printf("a & b(decimal) 为 %d \n",b);
    b&=7;
    printf("a & b(decimal) 为 %d \n",b);
    return 0;
}

int z()
{
    int a,b;
    a=077;
    b=a|3;
    printf("b 的值为 %d \n",b);
    b|=7;
    printf("b 的值为 %d \n",b);
    return 0;
}

int main()
{
    x();
    printf("\n");
    y();
    printf("\n");
    z();
}