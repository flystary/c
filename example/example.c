#include<stdio.h>

int hello()
{
    printf("Hello, World!\n");
    return 0;
}


int number()
{
    int number;
    printf("输入一个整数: ");
    scanf("%d", &number);
    printf("你输入的整数是: %d\n", number);

    return 0;
}


// 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？

int xy(void)
{
    int i, j, m, n, x;
    for (i = 1; i < 168/2 + 1;i++)
    {
        if (168 % i == 0)
        {
            j = 168 / i;
            if ( i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
            {
                m = (i + j) / 2;
                n = (i - j) / 2;
                x = n * n - 100;
                printf ("%d + 100 = %d * %d\n", x, n, n);
                printf ("%d + 268 = %d * %d\n", x, m, m);
            }
        }
    }

    return 0;
}


int date()
{
    int day, month, year, sum, leap;
    printf("\n请输入年、月、日，格式为：年/月/日（2015/12/10）\n");
    scanf("%d/%d/%d",&year,&month,&day);  // 格式为：2015/12/10

    switch (month)
    {
        case 1:sum=0;break;
        case 2:sum=31;break;
        case 3:sum=59;break;
        case 4:sum=90;break;
        case 5:sum=120;break;
        case 6:sum=151;break;
        case 7:sum=181;break;
        case 8:sum=211;break;
        case 9:sum=243;break;
        case 10:sum=273;break;
        case 11:sum=304;break;
        case 12:sum=334;break;
        default:printf("date error");break;
    }

    sum=sum+day;
    if (year%400==0||(year%4==0&&year%100!=0)) {
        leap=1;
    } else {
        leap=0;
    }

    if (leap == 1 && month > 2) {
        sum++;
    }
    printf("这是这一年的%d天。\n", sum);
    printf("\n");
    return 0;
}

int xyz()
{
    int x, y, x, t;
    printf("\n请输入三个数字: \n");

    if (x > y) {
        t = x; x = y; y = t;
    }

    if (x > z) {
        t =z; z = x; x = t;
    }

    if (y > z) {
        t = y; y = z; z = t;
    }

    printf("从小到大排序: %d %d %d \n", x, y, z);
}


int print_c()
{
    printf("用*号输出字母 C!\n");
    printf("**********\n");
    printf("***\n");
    printf("**\n");
    printf("*\n");
    printf("**");
    printf("***");
    printf("*********\n");

    return 0;
}

int aba()
{
    char a=176,b=219;
    printf("%c%c%c%c%c\n",b,a,a,a,b);
    printf("%c%c%c%c%c\n",a,b,a,b,a);
    printf("%c%c%c%c%c\n",a,a,b,a,a);
    printf("%c%c%c%c%c\n",a,b,a,b,a);
    printf("%c%c%c%c%c\n",b,a,a,a,b);
    return 0;
}

int nine()
{
    int i, j, result;
    printf("\n");

    for (i=1; i<10; i++)
    {
        for (j=1; j<=i; i++)
        {
            result=i*j;
            printf("%d*%d=%-3d", i,j, result);
        }
        printf("\n");
    }
}

int norepeat()
{
    int i,j,k;
    printf("\n");
    for(i=1;i<5;i++) { // 以下为三重循环
        for(j=1;j<5;j++) {
            for (k=1;k<5;k++) { // 确保i、j、k三位互不相同
                if (i!=k&&i!=j&&j!=k) {
                    printf("%d,%d,%d\n",i,j,k);
                }
            }
        }
    }
}


int main()
{
    hello();
    number();
    xy();
    date();
    xyz();
    print_c();
    aba();
    nine();
}