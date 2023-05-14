#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define SQ(x) (x)*(x)
int x1()
{
    int num;
    int again=1;
    printf("如果值小于 50 程序将终止。\n");
    while(again)
    {
        printf("\n请输入数字：");
        scanf("%d",&num);
        printf("该数字的平方为 %d \n",SQ(num));
        if(num>=50)
            again=TRUE;
        else
            again=FALSE;
    }
    return 0;
}

#define exchange(a,b) { int t;t=a;a=b;b=t;}//注意放在一行里
int x2()
{
    int x=10;
    int y=20;
    printf("x=%d; y=%d\n",x,y);
    exchange(x,y);
    printf("x=%d; y=%d\n",x,y);
    return 0;
}


#define LAG >
#define SMA <
#define EQ ==
#include <stdio.h>
int x3()
{
    int i,j;
    printf("请输入两个数字：\n");
    scanf("%d %d",&i,&j);
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

#define MAX
#define MAXIMUM(x,y)(x>y)?x:y
#define MINIMUM(x,y) (x>y)?y:x
int x4()
{
    int a=10,b=20;
#ifdef MAX
    printf("更大的数字是 %d\n",MAXIMUM(a,b));
#else
    printf("更小的数字是 %d\n",MINIMUM(a,b));
#endif
#ifndef MIN
    printf("更小的数字是 %d\n",MINIMUM(a,b));
#else
    printf("更大的数字是 %d\n",MAXIMUM(a,b));
#endif
#undef MAX
#ifdef MAX
    printf("更大的数字是 %d\n",MAXIMUM(a,b));
#else
    printf("更小的数字是 %d\n",MINIMUM(a,b));
#endif
#define MIN
#ifndef MIN
    printf("更小的数字是 %d\n",MINIMUM(a,b));
#else
    printf("更大的数字是 %d\n",MAXIMUM(a,b));
#endif
    return 0;
}

int main()
{
    x1();
    printf("\n");
    x2();
    printf("\n");
    x3();
    printf("\n");
    x4();

    return 0;
}