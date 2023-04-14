#include <stdio.h>

int x()
{
    unsigned a, b, c, d;
    printf("请输入整数: \n");

    scanf("%o", &a);
    b = a > 4;
    c = ~(~0 << 4);
    d = b & c;
    printf("%o\n%o\n", a, b);

    return 0;
}

int y()
{
    int a, b;
    a = 234;
    b = ~a;
    printf("a 的按位取反值为（十进制） %d \n", b);
    a = ~a;
    printf("a 的按位取反值为（十六进制） %x \n", a);

    return 0;
}
/*
#include<graphics.h>

int z()
{
    int driver, mode, i;
    float j = 1, k = 1;
    driver = VGA;
    mode = VGAHI;
    initgraph(&driver, &mode, "");
    setbkcolor(YELLOW);
    for (i = 0; i <= 25; i++)
    {
        setcolor(8);
        circle(310, 250, k);
        k = k + j;
        j = j + 0.3;
    }
    return 0;
}

int m()
{
    int driver,mode,i;
    float x0,y0,y1,x1;
    float j=12,k;
    driver=VGA;mode=VGAHI;
    initgraph(&driver,&mode,"");
    setbkcolor(GREEN);
    x0=263;y0=263;y1=275;x1=275;
    for(i=0;i<=18;i++)
    {
        setcolor(5);
        line(x0,y0,x0,y1);
        x0=x0-5;
        y0=y0-5;
        x1=x1+5;
        y1=y1+5;
        j=j+10;
    }
}
*/

int z()
{
    int i, j;
    int a[10][10];

    printf("\n");

    for(i=0; i< 10; i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2; i<10;i++)
    {
        for(j=1;j<i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    // 打印
    for(i=0;i<10;i++) {
        for(j=0;j<=i;j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

int main()
{
    // x();
    // printf("---------------------------\n");
    // y();
    z();

    return 0;
}